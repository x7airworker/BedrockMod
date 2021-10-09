#pragma once
#include <cstdint>
#include <string>
#include <iostream>

#define PTR_SIZE sizeof(void*)
#define STR_FIRST_ALIGN 0xF

namespace Utils {
	void DebugF(std::string x);

	uintptr_t PreInit(const char* pattern, int pad);

	class string {
		//textData union to help us a bit
		union textData
		{
			const char* contentPtr;
			char contentData[STR_FIRST_ALIGN + 1];
		} text;
		static_assert(sizeof(textData) == 16, "textData is misaligned!");
		size_t length;
		size_t lengthTillRealign;
	public:
		//nuv::string constructor
		string(std::string text) {
			this->lengthTillRealign = STR_FIRST_ALIGN;
			this->setString(text);
		}
		~string() {
			clearContent();
		}
		//setting the string content via std::string
		void setString(std::string text) {
			//Clear any existing content
			clearContent();

			//Check the text length, we may need to reallocate where the content is stored
			if (text.length() > this->lengthTillRealign) {
				//If we need to relocate, allocate new memory with the text length + 1
				//Also is this a memory leak?
				char* alloc = (char*)malloc(text.length() * 2);
				//Set the content of the allocated memory
				for (int i = 0; i < text.length(); i++) {
					alloc[i] = text[i];
				}
				//Set the content pointer to the allocated mem
				this->text.contentPtr = alloc;
				this->lengthTillRealign = text.length() * 2;
			}
			//If we do not need to re allocate
			else {
				//Set the contents to the text with no memory allocation
				for (int i = 0; i < text.length(); i++) {
					this->text.contentData[i] = text[i];
				}
			}
			//Set the length
			this->length = text.length();
		}
		//Convert back to std::string
		std::string getString() {
			//create a new string
			std::string newStr = "";
			//if the content is in a pointer
			if (isPtr()) {
				//Its a pointer, std::string can use a char* to form a new instance
				newStr = text.contentPtr;
			}
			else {
				//Its not a pointer, so we can append each character
				for (int i = 0; i < this->length; i++) {
					newStr += text.contentData[i];
				}
			}
			return newStr;
		}
		//Free memory allocated
		void clearContent() {
			if (isPtr()) {
				free((void*)text.contentPtr);
			}
			//Clear the contentData, make sure its all null
			memset(this->text.contentData, 0, STR_FIRST_ALIGN + 1);
		}
		//Tells us if the content for the string is in the pointer
		bool isPtr() {
			//This tells us if its a pointer or if we can just copy the bytes
			return STR_FIRST_ALIGN != this->lengthTillRealign;
		}

		//C string ==
		bool operator==(const char* text) {
			return getString() == text;
		}
		//nuv::string ==
		bool operator==(string text) {
			return getString() == text.getString();
		}
		//std::string ==
		bool operator==(std::string text) {
			return getString() == text;
		}
	};
	static_assert(sizeof(Utils::string) == 32, "Utils::string is misaligned!");
};