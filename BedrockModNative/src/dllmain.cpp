#include <Windows.h>
#include <iostream>
#include "BedrockMod.h"

#pragma region Proxy
struct IPHLPAPI_dll {
	HMODULE dll;
	FARPROC oAddIPAddress;
	FARPROC oAllocateAndGetInterfaceInfoFromStack;
	FARPROC oAllocateAndGetIpAddrTableFromStack;
	FARPROC oCancelIPChangeNotify;
	FARPROC oCancelIfTimestampConfigChange;
	FARPROC oCancelMibChangeNotify2;
	FARPROC oCaptureInterfaceHardwareCrossTimestamp;
	FARPROC oCloseCompartment;
	FARPROC oCloseGetIPPhysicalInterfaceForDestination;
	FARPROC oConvertCompartmentGuidToId;
	FARPROC oConvertCompartmentIdToGuid;
	FARPROC oConvertGuidToStringA;
	FARPROC oConvertGuidToStringW;
	FARPROC oConvertInterfaceAliasToLuid;
	FARPROC oConvertInterfaceGuidToLuid;
	FARPROC oConvertInterfaceIndexToLuid;
	FARPROC oConvertInterfaceLuidToAlias;
	FARPROC oConvertInterfaceLuidToGuid;
	FARPROC oConvertInterfaceLuidToIndex;
	FARPROC oConvertInterfaceLuidToNameA;
	FARPROC oConvertInterfaceLuidToNameW;
	FARPROC oConvertInterfaceNameToLuidA;
	FARPROC oConvertInterfaceNameToLuidW;
	FARPROC oConvertInterfacePhysicalAddressToLuid;
	FARPROC oConvertIpv4MaskToLength;
	FARPROC oConvertLengthToIpv4Mask;
	FARPROC oConvertRemoteInterfaceAliasToLuid;
	FARPROC oConvertRemoteInterfaceGuidToLuid;
	FARPROC oConvertRemoteInterfaceIndexToLuid;
	FARPROC oConvertRemoteInterfaceLuidToAlias;
	FARPROC oConvertRemoteInterfaceLuidToGuid;
	FARPROC oConvertRemoteInterfaceLuidToIndex;
	FARPROC oConvertStringToGuidA;
	FARPROC oConvertStringToGuidW;
	FARPROC oConvertStringToInterfacePhysicalAddress;
	FARPROC oCreateAnycastIpAddressEntry;
	FARPROC oCreateCompartment;
	FARPROC oCreateIpForwardEntry;
	FARPROC oCreateIpForwardEntry2;
	FARPROC oCreateIpNetEntry;
	FARPROC oCreateIpNetEntry2;
	FARPROC oCreatePersistentTcpPortReservation;
	FARPROC oCreatePersistentUdpPortReservation;
	FARPROC oCreateProxyArpEntry;
	FARPROC oCreateSortedAddressPairs;
	FARPROC oCreateUnicastIpAddressEntry;
	FARPROC oDeleteAnycastIpAddressEntry;
	FARPROC oDeleteCompartment;
	FARPROC oDeleteIPAddress;
	FARPROC oDeleteIpForwardEntry;
	FARPROC oDeleteIpForwardEntry2;
	FARPROC oDeleteIpNetEntry;
	FARPROC oDeleteIpNetEntry2;
	FARPROC oDeletePersistentTcpPortReservation;
	FARPROC oDeletePersistentUdpPortReservation;
	FARPROC oDeleteProxyArpEntry;
	FARPROC oDeleteUnicastIpAddressEntry;
	FARPROC oDisableMediaSense;
	FARPROC oEnableRouter;
	FARPROC oFlushIpNetTable;
	FARPROC oFlushIpNetTable2;
	FARPROC oFlushIpPathTable;
	FARPROC oFreeDnsSettings;
	FARPROC oFreeInterfaceDnsSettings;
	FARPROC oFreeMibTable;
	FARPROC oGetAdapterIndex;
	FARPROC oGetAdapterOrderMap;
	FARPROC oGetAdaptersAddresses;
	FARPROC oGetAdaptersInfo;
	FARPROC oGetAnycastIpAddressEntry;
	FARPROC oGetAnycastIpAddressTable;
	FARPROC oGetBestInterface;
	FARPROC oGetBestInterfaceEx;
	FARPROC oGetBestRoute;
	FARPROC oGetBestRoute2;
	FARPROC oGetCurrentThreadCompartmentId;
	FARPROC oGetCurrentThreadCompartmentScope;
	FARPROC oGetDefaultCompartmentId;
	FARPROC oGetDnsSettings;
	FARPROC oGetExtendedTcpTable;
	FARPROC oGetExtendedUdpTable;
	FARPROC oGetFriendlyIfIndex;
	FARPROC oGetIcmpStatistics;
	FARPROC oGetIcmpStatisticsEx;
	FARPROC oGetIfEntry;
	FARPROC oGetIfEntry2;
	FARPROC oGetIfEntry2Ex;
	FARPROC oGetIfStackTable;
	FARPROC oGetIfTable;
	FARPROC oGetIfTable2;
	FARPROC oGetIfTable2Ex;
	FARPROC oGetInterfaceCompartmentId;
	FARPROC oGetInterfaceCurrentTimestampCapabilities;
	FARPROC oGetInterfaceDnsSettings;
	FARPROC oGetInterfaceHardwareTimestampCapabilities;
	FARPROC oGetInterfaceInfo;
	FARPROC oGetInvertedIfStackTable;
	FARPROC oGetIpAddrTable;
	FARPROC oGetIpErrorString;
	FARPROC oGetIpForwardEntry2;
	FARPROC oGetIpForwardTable;
	FARPROC oGetIpForwardTable2;
	FARPROC oGetIpInterfaceEntry;
	FARPROC oGetIpInterfaceTable;
	FARPROC oGetIpNetEntry2;
	FARPROC oGetIpNetTable;
	FARPROC oGetIpNetTable2;
	FARPROC oGetIpNetworkConnectionBandwidthEstimates;
	FARPROC oGetIpPathEntry;
	FARPROC oGetIpPathTable;
	FARPROC oGetIpStatistics;
	FARPROC oGetIpStatisticsEx;
	FARPROC oGetJobCompartmentId;
	FARPROC oGetMulticastIpAddressEntry;
	FARPROC oGetMulticastIpAddressTable;
	FARPROC oGetNetworkConnectivityHint;
	FARPROC oGetNetworkConnectivityHintForInterface;
	FARPROC oGetNetworkInformation;
	FARPROC oGetNetworkParams;
	FARPROC oGetNumberOfInterfaces;
	FARPROC oGetOwnerModuleFromPidAndInfo;
	FARPROC oGetOwnerModuleFromTcp6Entry;
	FARPROC oGetOwnerModuleFromTcpEntry;
	FARPROC oGetOwnerModuleFromUdp6Entry;
	FARPROC oGetOwnerModuleFromUdpEntry;
	FARPROC oGetPerAdapterInfo;
	FARPROC oGetPerTcp6ConnectionEStats;
	FARPROC oGetPerTcp6ConnectionStats;
	FARPROC oGetPerTcpConnectionEStats;
	FARPROC oGetPerTcpConnectionStats;
	FARPROC oGetRTTAndHopCount;
	FARPROC oGetSessionCompartmentId;
	FARPROC oGetTcp6Table;
	FARPROC oGetTcp6Table2;
	FARPROC oGetTcpStatistics;
	FARPROC oGetTcpStatisticsEx;
	FARPROC oGetTcpStatisticsEx2;
	FARPROC oGetTcpTable;
	FARPROC oGetTcpTable2;
	FARPROC oGetTeredoPort;
	FARPROC oGetUdp6Table;
	FARPROC oGetUdpStatistics;
	FARPROC oGetUdpStatisticsEx;
	FARPROC oGetUdpStatisticsEx2;
	FARPROC oGetUdpTable;
	FARPROC oGetUniDirectionalAdapterInfo;
	FARPROC oGetUnicastIpAddressEntry;
	FARPROC oGetUnicastIpAddressTable;
	FARPROC oGetWPAOACSupportLevel;
	FARPROC oIcmp6CreateFile;
	FARPROC oIcmp6ParseReplies;
	FARPROC oIcmp6SendEcho2;
	FARPROC oIcmpCloseHandle;
	FARPROC oIcmpCreateFile;
	FARPROC oIcmpParseReplies;
	FARPROC oIcmpSendEcho;
	FARPROC oIcmpSendEcho2;
	FARPROC oIcmpSendEcho2Ex;
	FARPROC oInitializeCompartmentEntry;
	FARPROC oInitializeIpForwardEntry;
	FARPROC oInitializeIpInterfaceEntry;
	FARPROC oInitializeUnicastIpAddressEntry;
	FARPROC oInternalCleanupPersistentStore;
	FARPROC oInternalCreateAnycastIpAddressEntry;
	FARPROC oInternalCreateIpForwardEntry;
	FARPROC oInternalCreateIpForwardEntry2;
	FARPROC oInternalCreateIpNetEntry;
	FARPROC oInternalCreateIpNetEntry2;
	FARPROC oInternalCreateOrRefIpForwardEntry2;
	FARPROC oInternalCreateUnicastIpAddressEntry;
	FARPROC oInternalDeleteAnycastIpAddressEntry;
	FARPROC oInternalDeleteIpForwardEntry;
	FARPROC oInternalDeleteIpForwardEntry2;
	FARPROC oInternalDeleteIpNetEntry;
	FARPROC oInternalDeleteIpNetEntry2;
	FARPROC oInternalDeleteUnicastIpAddressEntry;
	FARPROC oInternalFindInterfaceByAddress;
	FARPROC oInternalGetAnycastIpAddressEntry;
	FARPROC oInternalGetAnycastIpAddressTable;
	FARPROC oInternalGetBoundTcp6EndpointTable;
	FARPROC oInternalGetBoundTcpEndpointTable;
	FARPROC oInternalGetForwardIpTable2;
	FARPROC oInternalGetIPPhysicalInterfaceForDestination;
	FARPROC oInternalGetIfEntry2;
	FARPROC oInternalGetIfTable;
	FARPROC oInternalGetIfTable2;
	FARPROC oInternalGetIpAddrTable;
	FARPROC oInternalGetIpForwardEntry2;
	FARPROC oInternalGetIpForwardTable;
	FARPROC oInternalGetIpInterfaceEntry;
	FARPROC oInternalGetIpInterfaceTable;
	FARPROC oInternalGetIpNetEntry2;
	FARPROC oInternalGetIpNetTable;
	FARPROC oInternalGetIpNetTable2;
	FARPROC oInternalGetMulticastIpAddressEntry;
	FARPROC oInternalGetMulticastIpAddressTable;
	FARPROC oInternalGetRtcSlotInformation;
	FARPROC oInternalGetTcp6Table2;
	FARPROC oInternalGetTcp6TableWithOwnerModule;
	FARPROC oInternalGetTcp6TableWithOwnerPid;
	FARPROC oInternalGetTcpTable;
	FARPROC oInternalGetTcpTable2;
	FARPROC oInternalGetTcpTableEx;
	FARPROC oInternalGetTcpTableWithOwnerModule;
	FARPROC oInternalGetTcpTableWithOwnerPid;
	FARPROC oInternalGetTunnelPhysicalAdapter;
	FARPROC oInternalGetUdp6TableWithOwnerModule;
	FARPROC oInternalGetUdp6TableWithOwnerPid;
	FARPROC oInternalGetUdpTable;
	FARPROC oInternalGetUdpTableEx;
	FARPROC oInternalGetUdpTableWithOwnerModule;
	FARPROC oInternalGetUdpTableWithOwnerPid;
	FARPROC oInternalGetUnicastIpAddressEntry;
	FARPROC oInternalGetUnicastIpAddressTable;
	FARPROC oInternalIcmpCreateFileEx;
	FARPROC oInternalSetIfEntry;
	FARPROC oInternalSetIpForwardEntry;
	FARPROC oInternalSetIpForwardEntry2;
	FARPROC oInternalSetIpInterfaceEntry;
	FARPROC oInternalSetIpNetEntry;
	FARPROC oInternalSetIpNetEntry2;
	FARPROC oInternalSetIpStats;
	FARPROC oInternalSetTcpEntry;
	FARPROC oInternalSetTeredoPort;
	FARPROC oInternalSetUnicastIpAddressEntry;
	FARPROC oIpReleaseAddress;
	FARPROC oIpRenewAddress;
	FARPROC oLookupPersistentTcpPortReservation;
	FARPROC oLookupPersistentUdpPortReservation;
	FARPROC oNTPTimeToNTFileTime;
	FARPROC oNTTimeToNTPTime;
	FARPROC oNhGetGuidFromInterfaceName;
	FARPROC oNhGetInterfaceDescriptionFromGuid;
	FARPROC oNhGetInterfaceNameFromDeviceGuid;
	FARPROC oNhGetInterfaceNameFromGuid;
	FARPROC oNhpAllocateAndGetInterfaceInfoFromStack;
	FARPROC oNotifyAddrChange;
	FARPROC oNotifyCompartmentChange;
	FARPROC oNotifyIfTimestampConfigChange;
	FARPROC oNotifyIpInterfaceChange;
	FARPROC oNotifyNetworkConnectivityHintChange;
	FARPROC oNotifyRouteChange;
	FARPROC oNotifyRouteChange2;
	FARPROC oNotifyStableUnicastIpAddressTable;
	FARPROC oNotifyTeredoPortChange;
	FARPROC oNotifyUnicastIpAddressChange;
	FARPROC oOpenCompartment;
	FARPROC oParseNetworkString;
	FARPROC oPfAddFiltersToInterface;
	FARPROC oPfAddGlobalFilterToInterface;
	FARPROC oPfBindInterfaceToIPAddress;
	FARPROC oPfBindInterfaceToIndex;
	FARPROC oPfCreateInterface;
	FARPROC oPfDeleteInterface;
	FARPROC oPfDeleteLog;
	FARPROC oPfGetInterfaceStatistics;
	FARPROC oPfMakeLog;
	FARPROC oPfRebindFilters;
	FARPROC oPfRemoveFilterHandles;
	FARPROC oPfRemoveFiltersFromInterface;
	FARPROC oPfRemoveGlobalFilterFromInterface;
	FARPROC oPfSetLogBuffer;
	FARPROC oPfTestPacket;
	FARPROC oPfUnBindInterface;
	FARPROC oResolveIpNetEntry2;
	FARPROC oResolveNeighbor;
	FARPROC oRestoreMediaSense;
	FARPROC oSendARP;
	FARPROC oSetAdapterIpAddress;
	FARPROC oSetCurrentThreadCompartmentId;
	FARPROC oSetCurrentThreadCompartmentScope;
	FARPROC oSetDnsSettings;
	FARPROC oSetIfEntry;
	FARPROC oSetInterfaceDnsSettings;
	FARPROC oSetIpForwardEntry;
	FARPROC oSetIpForwardEntry2;
	FARPROC oSetIpInterfaceEntry;
	FARPROC oSetIpNetEntry;
	FARPROC oSetIpNetEntry2;
	FARPROC oSetIpStatistics;
	FARPROC oSetIpStatisticsEx;
	FARPROC oSetIpTTL;
	FARPROC oSetJobCompartmentId;
	FARPROC oSetNetworkInformation;
	FARPROC oSetPerTcp6ConnectionEStats;
	FARPROC oSetPerTcp6ConnectionStats;
	FARPROC oSetPerTcpConnectionEStats;
	FARPROC oSetPerTcpConnectionStats;
	FARPROC oSetSessionCompartmentId;
	FARPROC oSetTcpEntry;
	FARPROC oSetUnicastIpAddressEntry;
	FARPROC oUnenableRouter;
	FARPROC odo_echo_rep;
	FARPROC odo_echo_req;
	FARPROC oif_indextoname;
	FARPROC oif_nametoindex;
	FARPROC oregister_icmp;
} IPHLPAPI;

extern "C" {
	FARPROC PA = 0;
	int runASM();

	void fAddIPAddress() { PA = IPHLPAPI.oAddIPAddress; runASM(); }
	void fAllocateAndGetInterfaceInfoFromStack() { PA = IPHLPAPI.oAllocateAndGetInterfaceInfoFromStack; runASM(); }
	void fAllocateAndGetIpAddrTableFromStack() { PA = IPHLPAPI.oAllocateAndGetIpAddrTableFromStack; runASM(); }
	void fCancelIPChangeNotify() { PA = IPHLPAPI.oCancelIPChangeNotify; runASM(); }
	void fCancelIfTimestampConfigChange() { PA = IPHLPAPI.oCancelIfTimestampConfigChange; runASM(); }
	void fCancelMibChangeNotify2() { PA = IPHLPAPI.oCancelMibChangeNotify2; runASM(); }
	void fCaptureInterfaceHardwareCrossTimestamp() { PA = IPHLPAPI.oCaptureInterfaceHardwareCrossTimestamp; runASM(); }
	void fCloseCompartment() { PA = IPHLPAPI.oCloseCompartment; runASM(); }
	void fCloseGetIPPhysicalInterfaceForDestination() { PA = IPHLPAPI.oCloseGetIPPhysicalInterfaceForDestination; runASM(); }
	void fConvertCompartmentGuidToId() { PA = IPHLPAPI.oConvertCompartmentGuidToId; runASM(); }
	void fConvertCompartmentIdToGuid() { PA = IPHLPAPI.oConvertCompartmentIdToGuid; runASM(); }
	void fConvertGuidToStringA() { PA = IPHLPAPI.oConvertGuidToStringA; runASM(); }
	void fConvertGuidToStringW() { PA = IPHLPAPI.oConvertGuidToStringW; runASM(); }
	void fConvertInterfaceAliasToLuid() { PA = IPHLPAPI.oConvertInterfaceAliasToLuid; runASM(); }
	void fConvertInterfaceGuidToLuid() { PA = IPHLPAPI.oConvertInterfaceGuidToLuid; runASM(); }
	void fConvertInterfaceIndexToLuid() { PA = IPHLPAPI.oConvertInterfaceIndexToLuid; runASM(); }
	void fConvertInterfaceLuidToAlias() { PA = IPHLPAPI.oConvertInterfaceLuidToAlias; runASM(); }
	void fConvertInterfaceLuidToGuid() { PA = IPHLPAPI.oConvertInterfaceLuidToGuid; runASM(); }
	void fConvertInterfaceLuidToIndex() { PA = IPHLPAPI.oConvertInterfaceLuidToIndex; runASM(); }
	void fConvertInterfaceLuidToNameA() { PA = IPHLPAPI.oConvertInterfaceLuidToNameA; runASM(); }
	void fConvertInterfaceLuidToNameW() { PA = IPHLPAPI.oConvertInterfaceLuidToNameW; runASM(); }
	void fConvertInterfaceNameToLuidA() { PA = IPHLPAPI.oConvertInterfaceNameToLuidA; runASM(); }
	void fConvertInterfaceNameToLuidW() { PA = IPHLPAPI.oConvertInterfaceNameToLuidW; runASM(); }
	void fConvertInterfacePhysicalAddressToLuid() { PA = IPHLPAPI.oConvertInterfacePhysicalAddressToLuid; runASM(); }
	void fConvertIpv4MaskToLength() { PA = IPHLPAPI.oConvertIpv4MaskToLength; runASM(); }
	void fConvertLengthToIpv4Mask() { PA = IPHLPAPI.oConvertLengthToIpv4Mask; runASM(); }
	void fConvertRemoteInterfaceAliasToLuid() { PA = IPHLPAPI.oConvertRemoteInterfaceAliasToLuid; runASM(); }
	void fConvertRemoteInterfaceGuidToLuid() { PA = IPHLPAPI.oConvertRemoteInterfaceGuidToLuid; runASM(); }
	void fConvertRemoteInterfaceIndexToLuid() { PA = IPHLPAPI.oConvertRemoteInterfaceIndexToLuid; runASM(); }
	void fConvertRemoteInterfaceLuidToAlias() { PA = IPHLPAPI.oConvertRemoteInterfaceLuidToAlias; runASM(); }
	void fConvertRemoteInterfaceLuidToGuid() { PA = IPHLPAPI.oConvertRemoteInterfaceLuidToGuid; runASM(); }
	void fConvertRemoteInterfaceLuidToIndex() { PA = IPHLPAPI.oConvertRemoteInterfaceLuidToIndex; runASM(); }
	void fConvertStringToGuidA() { PA = IPHLPAPI.oConvertStringToGuidA; runASM(); }
	void fConvertStringToGuidW() { PA = IPHLPAPI.oConvertStringToGuidW; runASM(); }
	void fConvertStringToInterfacePhysicalAddress() { PA = IPHLPAPI.oConvertStringToInterfacePhysicalAddress; runASM(); }
	void fCreateAnycastIpAddressEntry() { PA = IPHLPAPI.oCreateAnycastIpAddressEntry; runASM(); }
	void fCreateCompartment() { PA = IPHLPAPI.oCreateCompartment; runASM(); }
	void fCreateIpForwardEntry() { PA = IPHLPAPI.oCreateIpForwardEntry; runASM(); }
	void fCreateIpForwardEntry2() { PA = IPHLPAPI.oCreateIpForwardEntry2; runASM(); }
	void fCreateIpNetEntry() { PA = IPHLPAPI.oCreateIpNetEntry; runASM(); }
	void fCreateIpNetEntry2() { PA = IPHLPAPI.oCreateIpNetEntry2; runASM(); }
	void fCreatePersistentTcpPortReservation() { PA = IPHLPAPI.oCreatePersistentTcpPortReservation; runASM(); }
	void fCreatePersistentUdpPortReservation() { PA = IPHLPAPI.oCreatePersistentUdpPortReservation; runASM(); }
	void fCreateProxyArpEntry() { PA = IPHLPAPI.oCreateProxyArpEntry; runASM(); }
	void fCreateSortedAddressPairs() { PA = IPHLPAPI.oCreateSortedAddressPairs; runASM(); }
	void fCreateUnicastIpAddressEntry() { PA = IPHLPAPI.oCreateUnicastIpAddressEntry; runASM(); }
	void fDeleteAnycastIpAddressEntry() { PA = IPHLPAPI.oDeleteAnycastIpAddressEntry; runASM(); }
	void fDeleteCompartment() { PA = IPHLPAPI.oDeleteCompartment; runASM(); }
	void fDeleteIPAddress() { PA = IPHLPAPI.oDeleteIPAddress; runASM(); }
	void fDeleteIpForwardEntry() { PA = IPHLPAPI.oDeleteIpForwardEntry; runASM(); }
	void fDeleteIpForwardEntry2() { PA = IPHLPAPI.oDeleteIpForwardEntry2; runASM(); }
	void fDeleteIpNetEntry() { PA = IPHLPAPI.oDeleteIpNetEntry; runASM(); }
	void fDeleteIpNetEntry2() { PA = IPHLPAPI.oDeleteIpNetEntry2; runASM(); }
	void fDeletePersistentTcpPortReservation() { PA = IPHLPAPI.oDeletePersistentTcpPortReservation; runASM(); }
	void fDeletePersistentUdpPortReservation() { PA = IPHLPAPI.oDeletePersistentUdpPortReservation; runASM(); }
	void fDeleteProxyArpEntry() { PA = IPHLPAPI.oDeleteProxyArpEntry; runASM(); }
	void fDeleteUnicastIpAddressEntry() { PA = IPHLPAPI.oDeleteUnicastIpAddressEntry; runASM(); }
	void fDisableMediaSense() { PA = IPHLPAPI.oDisableMediaSense; runASM(); }
	void fEnableRouter() { PA = IPHLPAPI.oEnableRouter; runASM(); }
	void fFlushIpNetTable() { PA = IPHLPAPI.oFlushIpNetTable; runASM(); }
	void fFlushIpNetTable2() { PA = IPHLPAPI.oFlushIpNetTable2; runASM(); }
	void fFlushIpPathTable() { PA = IPHLPAPI.oFlushIpPathTable; runASM(); }
	void fFreeDnsSettings() { PA = IPHLPAPI.oFreeDnsSettings; runASM(); }
	void fFreeInterfaceDnsSettings() { PA = IPHLPAPI.oFreeInterfaceDnsSettings; runASM(); }
	void fFreeMibTable() { PA = IPHLPAPI.oFreeMibTable; runASM(); }
	void fGetAdapterIndex() { PA = IPHLPAPI.oGetAdapterIndex; runASM(); }
	void fGetAdapterOrderMap() { PA = IPHLPAPI.oGetAdapterOrderMap; runASM(); }
	void fGetAdaptersAddresses() { PA = IPHLPAPI.oGetAdaptersAddresses; runASM(); }
	void fGetAdaptersInfo() { PA = IPHLPAPI.oGetAdaptersInfo; runASM(); }
	void fGetAnycastIpAddressEntry() { PA = IPHLPAPI.oGetAnycastIpAddressEntry; runASM(); }
	void fGetAnycastIpAddressTable() { PA = IPHLPAPI.oGetAnycastIpAddressTable; runASM(); }
	void fGetBestInterface() { PA = IPHLPAPI.oGetBestInterface; runASM(); }
	void fGetBestInterfaceEx() { PA = IPHLPAPI.oGetBestInterfaceEx; runASM(); }
	void fGetBestRoute() { PA = IPHLPAPI.oGetBestRoute; runASM(); }
	void fGetBestRoute2() { PA = IPHLPAPI.oGetBestRoute2; runASM(); }
	void fGetCurrentThreadCompartmentId() { PA = IPHLPAPI.oGetCurrentThreadCompartmentId; runASM(); }
	void fGetCurrentThreadCompartmentScope() { PA = IPHLPAPI.oGetCurrentThreadCompartmentScope; runASM(); }
	void fGetDefaultCompartmentId() { PA = IPHLPAPI.oGetDefaultCompartmentId; runASM(); }
	void fGetDnsSettings() { PA = IPHLPAPI.oGetDnsSettings; runASM(); }
	void fGetExtendedTcpTable() { PA = IPHLPAPI.oGetExtendedTcpTable; runASM(); }
	void fGetExtendedUdpTable() { PA = IPHLPAPI.oGetExtendedUdpTable; runASM(); }
	void fGetFriendlyIfIndex() { PA = IPHLPAPI.oGetFriendlyIfIndex; runASM(); }
	void fGetIcmpStatistics() { PA = IPHLPAPI.oGetIcmpStatistics; runASM(); }
	void fGetIcmpStatisticsEx() { PA = IPHLPAPI.oGetIcmpStatisticsEx; runASM(); }
	void fGetIfEntry() { PA = IPHLPAPI.oGetIfEntry; runASM(); }
	void fGetIfEntry2() { PA = IPHLPAPI.oGetIfEntry2; runASM(); }
	void fGetIfEntry2Ex() { PA = IPHLPAPI.oGetIfEntry2Ex; runASM(); }
	void fGetIfStackTable() { PA = IPHLPAPI.oGetIfStackTable; runASM(); }
	void fGetIfTable() { PA = IPHLPAPI.oGetIfTable; runASM(); }
	void fGetIfTable2() { PA = IPHLPAPI.oGetIfTable2; runASM(); }
	void fGetIfTable2Ex() { PA = IPHLPAPI.oGetIfTable2Ex; runASM(); }
	void fGetInterfaceCompartmentId() { PA = IPHLPAPI.oGetInterfaceCompartmentId; runASM(); }
	void fGetInterfaceCurrentTimestampCapabilities() { PA = IPHLPAPI.oGetInterfaceCurrentTimestampCapabilities; runASM(); }
	void fGetInterfaceDnsSettings() { PA = IPHLPAPI.oGetInterfaceDnsSettings; runASM(); }
	void fGetInterfaceHardwareTimestampCapabilities() { PA = IPHLPAPI.oGetInterfaceHardwareTimestampCapabilities; runASM(); }
	void fGetInterfaceInfo() { PA = IPHLPAPI.oGetInterfaceInfo; runASM(); }
	void fGetInvertedIfStackTable() { PA = IPHLPAPI.oGetInvertedIfStackTable; runASM(); }
	void fGetIpAddrTable() { PA = IPHLPAPI.oGetIpAddrTable; runASM(); }
	void fGetIpErrorString() { PA = IPHLPAPI.oGetIpErrorString; runASM(); }
	void fGetIpForwardEntry2() { PA = IPHLPAPI.oGetIpForwardEntry2; runASM(); }
	void fGetIpForwardTable() { PA = IPHLPAPI.oGetIpForwardTable; runASM(); }
	void fGetIpForwardTable2() { PA = IPHLPAPI.oGetIpForwardTable2; runASM(); }
	void fGetIpInterfaceEntry() { PA = IPHLPAPI.oGetIpInterfaceEntry; runASM(); }
	void fGetIpInterfaceTable() { PA = IPHLPAPI.oGetIpInterfaceTable; runASM(); }
	void fGetIpNetEntry2() { PA = IPHLPAPI.oGetIpNetEntry2; runASM(); }
	void fGetIpNetTable() { PA = IPHLPAPI.oGetIpNetTable; runASM(); }
	void fGetIpNetTable2() { PA = IPHLPAPI.oGetIpNetTable2; runASM(); }
	void fGetIpNetworkConnectionBandwidthEstimates() { PA = IPHLPAPI.oGetIpNetworkConnectionBandwidthEstimates; runASM(); }
	void fGetIpPathEntry() { PA = IPHLPAPI.oGetIpPathEntry; runASM(); }
	void fGetIpPathTable() { PA = IPHLPAPI.oGetIpPathTable; runASM(); }
	void fGetIpStatistics() { PA = IPHLPAPI.oGetIpStatistics; runASM(); }
	void fGetIpStatisticsEx() { PA = IPHLPAPI.oGetIpStatisticsEx; runASM(); }
	void fGetJobCompartmentId() { PA = IPHLPAPI.oGetJobCompartmentId; runASM(); }
	void fGetMulticastIpAddressEntry() { PA = IPHLPAPI.oGetMulticastIpAddressEntry; runASM(); }
	void fGetMulticastIpAddressTable() { PA = IPHLPAPI.oGetMulticastIpAddressTable; runASM(); }
	void fGetNetworkConnectivityHint() { PA = IPHLPAPI.oGetNetworkConnectivityHint; runASM(); }
	void fGetNetworkConnectivityHintForInterface() { PA = IPHLPAPI.oGetNetworkConnectivityHintForInterface; runASM(); }
	void fGetNetworkInformation() { PA = IPHLPAPI.oGetNetworkInformation; runASM(); }
	void fGetNetworkParams() { PA = IPHLPAPI.oGetNetworkParams; runASM(); }
	void fGetNumberOfInterfaces() { PA = IPHLPAPI.oGetNumberOfInterfaces; runASM(); }
	void fGetOwnerModuleFromPidAndInfo() { PA = IPHLPAPI.oGetOwnerModuleFromPidAndInfo; runASM(); }
	void fGetOwnerModuleFromTcp6Entry() { PA = IPHLPAPI.oGetOwnerModuleFromTcp6Entry; runASM(); }
	void fGetOwnerModuleFromTcpEntry() { PA = IPHLPAPI.oGetOwnerModuleFromTcpEntry; runASM(); }
	void fGetOwnerModuleFromUdp6Entry() { PA = IPHLPAPI.oGetOwnerModuleFromUdp6Entry; runASM(); }
	void fGetOwnerModuleFromUdpEntry() { PA = IPHLPAPI.oGetOwnerModuleFromUdpEntry; runASM(); }
	void fGetPerAdapterInfo() { PA = IPHLPAPI.oGetPerAdapterInfo; runASM(); }
	void fGetPerTcp6ConnectionEStats() { PA = IPHLPAPI.oGetPerTcp6ConnectionEStats; runASM(); }
	void fGetPerTcp6ConnectionStats() { PA = IPHLPAPI.oGetPerTcp6ConnectionStats; runASM(); }
	void fGetPerTcpConnectionEStats() { PA = IPHLPAPI.oGetPerTcpConnectionEStats; runASM(); }
	void fGetPerTcpConnectionStats() { PA = IPHLPAPI.oGetPerTcpConnectionStats; runASM(); }
	void fGetRTTAndHopCount() { PA = IPHLPAPI.oGetRTTAndHopCount; runASM(); }
	void fGetSessionCompartmentId() { PA = IPHLPAPI.oGetSessionCompartmentId; runASM(); }
	void fGetTcp6Table() { PA = IPHLPAPI.oGetTcp6Table; runASM(); }
	void fGetTcp6Table2() { PA = IPHLPAPI.oGetTcp6Table2; runASM(); }
	void fGetTcpStatistics() { PA = IPHLPAPI.oGetTcpStatistics; runASM(); }
	void fGetTcpStatisticsEx() { PA = IPHLPAPI.oGetTcpStatisticsEx; runASM(); }
	void fGetTcpStatisticsEx2() { PA = IPHLPAPI.oGetTcpStatisticsEx2; runASM(); }
	void fGetTcpTable() { PA = IPHLPAPI.oGetTcpTable; runASM(); }
	void fGetTcpTable2() { PA = IPHLPAPI.oGetTcpTable2; runASM(); }
	void fGetTeredoPort() { PA = IPHLPAPI.oGetTeredoPort; runASM(); }
	void fGetUdp6Table() { PA = IPHLPAPI.oGetUdp6Table; runASM(); }
	void fGetUdpStatistics() { PA = IPHLPAPI.oGetUdpStatistics; runASM(); }
	void fGetUdpStatisticsEx() { PA = IPHLPAPI.oGetUdpStatisticsEx; runASM(); }
	void fGetUdpStatisticsEx2() { PA = IPHLPAPI.oGetUdpStatisticsEx2; runASM(); }
	void fGetUdpTable() { PA = IPHLPAPI.oGetUdpTable; runASM(); }
	void fGetUniDirectionalAdapterInfo() { PA = IPHLPAPI.oGetUniDirectionalAdapterInfo; runASM(); }
	void fGetUnicastIpAddressEntry() { PA = IPHLPAPI.oGetUnicastIpAddressEntry; runASM(); }
	void fGetUnicastIpAddressTable() { PA = IPHLPAPI.oGetUnicastIpAddressTable; runASM(); }
	void fGetWPAOACSupportLevel() { PA = IPHLPAPI.oGetWPAOACSupportLevel; runASM(); }
	void fIcmp6CreateFile() { PA = IPHLPAPI.oIcmp6CreateFile; runASM(); }
	void fIcmp6ParseReplies() { PA = IPHLPAPI.oIcmp6ParseReplies; runASM(); }
	void fIcmp6SendEcho2() { PA = IPHLPAPI.oIcmp6SendEcho2; runASM(); }
	void fIcmpCloseHandle() { PA = IPHLPAPI.oIcmpCloseHandle; runASM(); }
	void fIcmpCreateFile() { PA = IPHLPAPI.oIcmpCreateFile; runASM(); }
	void fIcmpParseReplies() { PA = IPHLPAPI.oIcmpParseReplies; runASM(); }
	void fIcmpSendEcho() { PA = IPHLPAPI.oIcmpSendEcho; runASM(); }
	void fIcmpSendEcho2() { PA = IPHLPAPI.oIcmpSendEcho2; runASM(); }
	void fIcmpSendEcho2Ex() { PA = IPHLPAPI.oIcmpSendEcho2Ex; runASM(); }
	void fInitializeCompartmentEntry() { PA = IPHLPAPI.oInitializeCompartmentEntry; runASM(); }
	void fInitializeIpForwardEntry() { PA = IPHLPAPI.oInitializeIpForwardEntry; runASM(); }
	void fInitializeIpInterfaceEntry() { PA = IPHLPAPI.oInitializeIpInterfaceEntry; runASM(); }
	void fInitializeUnicastIpAddressEntry() { PA = IPHLPAPI.oInitializeUnicastIpAddressEntry; runASM(); }
	void fInternalCleanupPersistentStore() { PA = IPHLPAPI.oInternalCleanupPersistentStore; runASM(); }
	void fInternalCreateAnycastIpAddressEntry() { PA = IPHLPAPI.oInternalCreateAnycastIpAddressEntry; runASM(); }
	void fInternalCreateIpForwardEntry() { PA = IPHLPAPI.oInternalCreateIpForwardEntry; runASM(); }
	void fInternalCreateIpForwardEntry2() { PA = IPHLPAPI.oInternalCreateIpForwardEntry2; runASM(); }
	void fInternalCreateIpNetEntry() { PA = IPHLPAPI.oInternalCreateIpNetEntry; runASM(); }
	void fInternalCreateIpNetEntry2() { PA = IPHLPAPI.oInternalCreateIpNetEntry2; runASM(); }
	void fInternalCreateOrRefIpForwardEntry2() { PA = IPHLPAPI.oInternalCreateOrRefIpForwardEntry2; runASM(); }
	void fInternalCreateUnicastIpAddressEntry() { PA = IPHLPAPI.oInternalCreateUnicastIpAddressEntry; runASM(); }
	void fInternalDeleteAnycastIpAddressEntry() { PA = IPHLPAPI.oInternalDeleteAnycastIpAddressEntry; runASM(); }
	void fInternalDeleteIpForwardEntry() { PA = IPHLPAPI.oInternalDeleteIpForwardEntry; runASM(); }
	void fInternalDeleteIpForwardEntry2() { PA = IPHLPAPI.oInternalDeleteIpForwardEntry2; runASM(); }
	void fInternalDeleteIpNetEntry() { PA = IPHLPAPI.oInternalDeleteIpNetEntry; runASM(); }
	void fInternalDeleteIpNetEntry2() { PA = IPHLPAPI.oInternalDeleteIpNetEntry2; runASM(); }
	void fInternalDeleteUnicastIpAddressEntry() { PA = IPHLPAPI.oInternalDeleteUnicastIpAddressEntry; runASM(); }
	void fInternalFindInterfaceByAddress() { PA = IPHLPAPI.oInternalFindInterfaceByAddress; runASM(); }
	void fInternalGetAnycastIpAddressEntry() { PA = IPHLPAPI.oInternalGetAnycastIpAddressEntry; runASM(); }
	void fInternalGetAnycastIpAddressTable() { PA = IPHLPAPI.oInternalGetAnycastIpAddressTable; runASM(); }
	void fInternalGetBoundTcp6EndpointTable() { PA = IPHLPAPI.oInternalGetBoundTcp6EndpointTable; runASM(); }
	void fInternalGetBoundTcpEndpointTable() { PA = IPHLPAPI.oInternalGetBoundTcpEndpointTable; runASM(); }
	void fInternalGetForwardIpTable2() { PA = IPHLPAPI.oInternalGetForwardIpTable2; runASM(); }
	void fInternalGetIPPhysicalInterfaceForDestination() { PA = IPHLPAPI.oInternalGetIPPhysicalInterfaceForDestination; runASM(); }
	void fInternalGetIfEntry2() { PA = IPHLPAPI.oInternalGetIfEntry2; runASM(); }
	void fInternalGetIfTable() { PA = IPHLPAPI.oInternalGetIfTable; runASM(); }
	void fInternalGetIfTable2() { PA = IPHLPAPI.oInternalGetIfTable2; runASM(); }
	void fInternalGetIpAddrTable() { PA = IPHLPAPI.oInternalGetIpAddrTable; runASM(); }
	void fInternalGetIpForwardEntry2() { PA = IPHLPAPI.oInternalGetIpForwardEntry2; runASM(); }
	void fInternalGetIpForwardTable() { PA = IPHLPAPI.oInternalGetIpForwardTable; runASM(); }
	void fInternalGetIpInterfaceEntry() { PA = IPHLPAPI.oInternalGetIpInterfaceEntry; runASM(); }
	void fInternalGetIpInterfaceTable() { PA = IPHLPAPI.oInternalGetIpInterfaceTable; runASM(); }
	void fInternalGetIpNetEntry2() { PA = IPHLPAPI.oInternalGetIpNetEntry2; runASM(); }
	void fInternalGetIpNetTable() { PA = IPHLPAPI.oInternalGetIpNetTable; runASM(); }
	void fInternalGetIpNetTable2() { PA = IPHLPAPI.oInternalGetIpNetTable2; runASM(); }
	void fInternalGetMulticastIpAddressEntry() { PA = IPHLPAPI.oInternalGetMulticastIpAddressEntry; runASM(); }
	void fInternalGetMulticastIpAddressTable() { PA = IPHLPAPI.oInternalGetMulticastIpAddressTable; runASM(); }
	void fInternalGetRtcSlotInformation() { PA = IPHLPAPI.oInternalGetRtcSlotInformation; runASM(); }
	void fInternalGetTcp6Table2() { PA = IPHLPAPI.oInternalGetTcp6Table2; runASM(); }
	void fInternalGetTcp6TableWithOwnerModule() { PA = IPHLPAPI.oInternalGetTcp6TableWithOwnerModule; runASM(); }
	void fInternalGetTcp6TableWithOwnerPid() { PA = IPHLPAPI.oInternalGetTcp6TableWithOwnerPid; runASM(); }
	void fInternalGetTcpTable() { PA = IPHLPAPI.oInternalGetTcpTable; runASM(); }
	void fInternalGetTcpTable2() { PA = IPHLPAPI.oInternalGetTcpTable2; runASM(); }
	void fInternalGetTcpTableEx() { PA = IPHLPAPI.oInternalGetTcpTableEx; runASM(); }
	void fInternalGetTcpTableWithOwnerModule() { PA = IPHLPAPI.oInternalGetTcpTableWithOwnerModule; runASM(); }
	void fInternalGetTcpTableWithOwnerPid() { PA = IPHLPAPI.oInternalGetTcpTableWithOwnerPid; runASM(); }
	void fInternalGetTunnelPhysicalAdapter() { PA = IPHLPAPI.oInternalGetTunnelPhysicalAdapter; runASM(); }
	void fInternalGetUdp6TableWithOwnerModule() { PA = IPHLPAPI.oInternalGetUdp6TableWithOwnerModule; runASM(); }
	void fInternalGetUdp6TableWithOwnerPid() { PA = IPHLPAPI.oInternalGetUdp6TableWithOwnerPid; runASM(); }
	void fInternalGetUdpTable() { PA = IPHLPAPI.oInternalGetUdpTable; runASM(); }
	void fInternalGetUdpTableEx() { PA = IPHLPAPI.oInternalGetUdpTableEx; runASM(); }
	void fInternalGetUdpTableWithOwnerModule() { PA = IPHLPAPI.oInternalGetUdpTableWithOwnerModule; runASM(); }
	void fInternalGetUdpTableWithOwnerPid() { PA = IPHLPAPI.oInternalGetUdpTableWithOwnerPid; runASM(); }
	void fInternalGetUnicastIpAddressEntry() { PA = IPHLPAPI.oInternalGetUnicastIpAddressEntry; runASM(); }
	void fInternalGetUnicastIpAddressTable() { PA = IPHLPAPI.oInternalGetUnicastIpAddressTable; runASM(); }
	void fInternalIcmpCreateFileEx() { PA = IPHLPAPI.oInternalIcmpCreateFileEx; runASM(); }
	void fInternalSetIfEntry() { PA = IPHLPAPI.oInternalSetIfEntry; runASM(); }
	void fInternalSetIpForwardEntry() { PA = IPHLPAPI.oInternalSetIpForwardEntry; runASM(); }
	void fInternalSetIpForwardEntry2() { PA = IPHLPAPI.oInternalSetIpForwardEntry2; runASM(); }
	void fInternalSetIpInterfaceEntry() { PA = IPHLPAPI.oInternalSetIpInterfaceEntry; runASM(); }
	void fInternalSetIpNetEntry() { PA = IPHLPAPI.oInternalSetIpNetEntry; runASM(); }
	void fInternalSetIpNetEntry2() { PA = IPHLPAPI.oInternalSetIpNetEntry2; runASM(); }
	void fInternalSetIpStats() { PA = IPHLPAPI.oInternalSetIpStats; runASM(); }
	void fInternalSetTcpEntry() { PA = IPHLPAPI.oInternalSetTcpEntry; runASM(); }
	void fInternalSetTeredoPort() { PA = IPHLPAPI.oInternalSetTeredoPort; runASM(); }
	void fInternalSetUnicastIpAddressEntry() { PA = IPHLPAPI.oInternalSetUnicastIpAddressEntry; runASM(); }
	void fIpReleaseAddress() { PA = IPHLPAPI.oIpReleaseAddress; runASM(); }
	void fIpRenewAddress() { PA = IPHLPAPI.oIpRenewAddress; runASM(); }
	void fLookupPersistentTcpPortReservation() { PA = IPHLPAPI.oLookupPersistentTcpPortReservation; runASM(); }
	void fLookupPersistentUdpPortReservation() { PA = IPHLPAPI.oLookupPersistentUdpPortReservation; runASM(); }
	void fNTPTimeToNTFileTime() { PA = IPHLPAPI.oNTPTimeToNTFileTime; runASM(); }
	void fNTTimeToNTPTime() { PA = IPHLPAPI.oNTTimeToNTPTime; runASM(); }
	void fNhGetGuidFromInterfaceName() { PA = IPHLPAPI.oNhGetGuidFromInterfaceName; runASM(); }
	void fNhGetInterfaceDescriptionFromGuid() { PA = IPHLPAPI.oNhGetInterfaceDescriptionFromGuid; runASM(); }
	void fNhGetInterfaceNameFromDeviceGuid() { PA = IPHLPAPI.oNhGetInterfaceNameFromDeviceGuid; runASM(); }
	void fNhGetInterfaceNameFromGuid() { PA = IPHLPAPI.oNhGetInterfaceNameFromGuid; runASM(); }
	void fNhpAllocateAndGetInterfaceInfoFromStack() { PA = IPHLPAPI.oNhpAllocateAndGetInterfaceInfoFromStack; runASM(); }
	void fNotifyAddrChange() { PA = IPHLPAPI.oNotifyAddrChange; runASM(); }
	void fNotifyCompartmentChange() { PA = IPHLPAPI.oNotifyCompartmentChange; runASM(); }
	void fNotifyIfTimestampConfigChange() { PA = IPHLPAPI.oNotifyIfTimestampConfigChange; runASM(); }
	void fNotifyIpInterfaceChange() { PA = IPHLPAPI.oNotifyIpInterfaceChange; runASM(); }
	void fNotifyNetworkConnectivityHintChange() { PA = IPHLPAPI.oNotifyNetworkConnectivityHintChange; runASM(); }
	void fNotifyRouteChange() { PA = IPHLPAPI.oNotifyRouteChange; runASM(); }
	void fNotifyRouteChange2() { PA = IPHLPAPI.oNotifyRouteChange2; runASM(); }
	void fNotifyStableUnicastIpAddressTable() { PA = IPHLPAPI.oNotifyStableUnicastIpAddressTable; runASM(); }
	void fNotifyTeredoPortChange() { PA = IPHLPAPI.oNotifyTeredoPortChange; runASM(); }
	void fNotifyUnicastIpAddressChange() { PA = IPHLPAPI.oNotifyUnicastIpAddressChange; runASM(); }
	void fOpenCompartment() { PA = IPHLPAPI.oOpenCompartment; runASM(); }
	void fParseNetworkString() { PA = IPHLPAPI.oParseNetworkString; runASM(); }
	void fPfAddFiltersToInterface() { PA = IPHLPAPI.oPfAddFiltersToInterface; runASM(); }
	void fPfAddGlobalFilterToInterface() { PA = IPHLPAPI.oPfAddGlobalFilterToInterface; runASM(); }
	void fPfBindInterfaceToIPAddress() { PA = IPHLPAPI.oPfBindInterfaceToIPAddress; runASM(); }
	void fPfBindInterfaceToIndex() { PA = IPHLPAPI.oPfBindInterfaceToIndex; runASM(); }
	void fPfCreateInterface() { PA = IPHLPAPI.oPfCreateInterface; runASM(); }
	void fPfDeleteInterface() { PA = IPHLPAPI.oPfDeleteInterface; runASM(); }
	void fPfDeleteLog() { PA = IPHLPAPI.oPfDeleteLog; runASM(); }
	void fPfGetInterfaceStatistics() { PA = IPHLPAPI.oPfGetInterfaceStatistics; runASM(); }
	void fPfMakeLog() { PA = IPHLPAPI.oPfMakeLog; runASM(); }
	void fPfRebindFilters() { PA = IPHLPAPI.oPfRebindFilters; runASM(); }
	void fPfRemoveFilterHandles() { PA = IPHLPAPI.oPfRemoveFilterHandles; runASM(); }
	void fPfRemoveFiltersFromInterface() { PA = IPHLPAPI.oPfRemoveFiltersFromInterface; runASM(); }
	void fPfRemoveGlobalFilterFromInterface() { PA = IPHLPAPI.oPfRemoveGlobalFilterFromInterface; runASM(); }
	void fPfSetLogBuffer() { PA = IPHLPAPI.oPfSetLogBuffer; runASM(); }
	void fPfTestPacket() { PA = IPHLPAPI.oPfTestPacket; runASM(); }
	void fPfUnBindInterface() { PA = IPHLPAPI.oPfUnBindInterface; runASM(); }
	void fResolveIpNetEntry2() { PA = IPHLPAPI.oResolveIpNetEntry2; runASM(); }
	void fResolveNeighbor() { PA = IPHLPAPI.oResolveNeighbor; runASM(); }
	void fRestoreMediaSense() { PA = IPHLPAPI.oRestoreMediaSense; runASM(); }
	void fSendARP() { PA = IPHLPAPI.oSendARP; runASM(); }
	void fSetAdapterIpAddress() { PA = IPHLPAPI.oSetAdapterIpAddress; runASM(); }
	void fSetCurrentThreadCompartmentId() { PA = IPHLPAPI.oSetCurrentThreadCompartmentId; runASM(); }
	void fSetCurrentThreadCompartmentScope() { PA = IPHLPAPI.oSetCurrentThreadCompartmentScope; runASM(); }
	void fSetDnsSettings() { PA = IPHLPAPI.oSetDnsSettings; runASM(); }
	void fSetIfEntry() { PA = IPHLPAPI.oSetIfEntry; runASM(); }
	void fSetInterfaceDnsSettings() { PA = IPHLPAPI.oSetInterfaceDnsSettings; runASM(); }
	void fSetIpForwardEntry() { PA = IPHLPAPI.oSetIpForwardEntry; runASM(); }
	void fSetIpForwardEntry2() { PA = IPHLPAPI.oSetIpForwardEntry2; runASM(); }
	void fSetIpInterfaceEntry() { PA = IPHLPAPI.oSetIpInterfaceEntry; runASM(); }
	void fSetIpNetEntry() { PA = IPHLPAPI.oSetIpNetEntry; runASM(); }
	void fSetIpNetEntry2() { PA = IPHLPAPI.oSetIpNetEntry2; runASM(); }
	void fSetIpStatistics() { PA = IPHLPAPI.oSetIpStatistics; runASM(); }
	void fSetIpStatisticsEx() { PA = IPHLPAPI.oSetIpStatisticsEx; runASM(); }
	void fSetIpTTL() { PA = IPHLPAPI.oSetIpTTL; runASM(); }
	void fSetJobCompartmentId() { PA = IPHLPAPI.oSetJobCompartmentId; runASM(); }
	void fSetNetworkInformation() { PA = IPHLPAPI.oSetNetworkInformation; runASM(); }
	void fSetPerTcp6ConnectionEStats() { PA = IPHLPAPI.oSetPerTcp6ConnectionEStats; runASM(); }
	void fSetPerTcp6ConnectionStats() { PA = IPHLPAPI.oSetPerTcp6ConnectionStats; runASM(); }
	void fSetPerTcpConnectionEStats() { PA = IPHLPAPI.oSetPerTcpConnectionEStats; runASM(); }
	void fSetPerTcpConnectionStats() { PA = IPHLPAPI.oSetPerTcpConnectionStats; runASM(); }
	void fSetSessionCompartmentId() { PA = IPHLPAPI.oSetSessionCompartmentId; runASM(); }
	void fSetTcpEntry() { PA = IPHLPAPI.oSetTcpEntry; runASM(); }
	void fSetUnicastIpAddressEntry() { PA = IPHLPAPI.oSetUnicastIpAddressEntry; runASM(); }
	void fUnenableRouter() { PA = IPHLPAPI.oUnenableRouter; runASM(); }
	void fdo_echo_rep() { PA = IPHLPAPI.odo_echo_rep; runASM(); }
	void fdo_echo_req() { PA = IPHLPAPI.odo_echo_req; runASM(); }
	void fif_indextoname() { PA = IPHLPAPI.oif_indextoname; runASM(); }
	void fif_nametoindex() { PA = IPHLPAPI.oif_nametoindex; runASM(); }
	void fregister_icmp() { PA = IPHLPAPI.oregister_icmp; runASM(); }
}

void setupFunctions() {
	IPHLPAPI.oAddIPAddress = GetProcAddress(IPHLPAPI.dll, "AddIPAddress");
	IPHLPAPI.oAllocateAndGetInterfaceInfoFromStack = GetProcAddress(IPHLPAPI.dll, "AllocateAndGetInterfaceInfoFromStack");
	IPHLPAPI.oAllocateAndGetIpAddrTableFromStack = GetProcAddress(IPHLPAPI.dll, "AllocateAndGetIpAddrTableFromStack");
	IPHLPAPI.oCancelIPChangeNotify = GetProcAddress(IPHLPAPI.dll, "CancelIPChangeNotify");
	IPHLPAPI.oCancelIfTimestampConfigChange = GetProcAddress(IPHLPAPI.dll, "CancelIfTimestampConfigChange");
	IPHLPAPI.oCancelMibChangeNotify2 = GetProcAddress(IPHLPAPI.dll, "CancelMibChangeNotify2");
	IPHLPAPI.oCaptureInterfaceHardwareCrossTimestamp = GetProcAddress(IPHLPAPI.dll, "CaptureInterfaceHardwareCrossTimestamp");
	IPHLPAPI.oCloseCompartment = GetProcAddress(IPHLPAPI.dll, "CloseCompartment");
	IPHLPAPI.oCloseGetIPPhysicalInterfaceForDestination = GetProcAddress(IPHLPAPI.dll, "CloseGetIPPhysicalInterfaceForDestination");
	IPHLPAPI.oConvertCompartmentGuidToId = GetProcAddress(IPHLPAPI.dll, "ConvertCompartmentGuidToId");
	IPHLPAPI.oConvertCompartmentIdToGuid = GetProcAddress(IPHLPAPI.dll, "ConvertCompartmentIdToGuid");
	IPHLPAPI.oConvertGuidToStringA = GetProcAddress(IPHLPAPI.dll, "ConvertGuidToStringA");
	IPHLPAPI.oConvertGuidToStringW = GetProcAddress(IPHLPAPI.dll, "ConvertGuidToStringW");
	IPHLPAPI.oConvertInterfaceAliasToLuid = GetProcAddress(IPHLPAPI.dll, "ConvertInterfaceAliasToLuid");
	IPHLPAPI.oConvertInterfaceGuidToLuid = GetProcAddress(IPHLPAPI.dll, "ConvertInterfaceGuidToLuid");
	IPHLPAPI.oConvertInterfaceIndexToLuid = GetProcAddress(IPHLPAPI.dll, "ConvertInterfaceIndexToLuid");
	IPHLPAPI.oConvertInterfaceLuidToAlias = GetProcAddress(IPHLPAPI.dll, "ConvertInterfaceLuidToAlias");
	IPHLPAPI.oConvertInterfaceLuidToGuid = GetProcAddress(IPHLPAPI.dll, "ConvertInterfaceLuidToGuid");
	IPHLPAPI.oConvertInterfaceLuidToIndex = GetProcAddress(IPHLPAPI.dll, "ConvertInterfaceLuidToIndex");
	IPHLPAPI.oConvertInterfaceLuidToNameA = GetProcAddress(IPHLPAPI.dll, "ConvertInterfaceLuidToNameA");
	IPHLPAPI.oConvertInterfaceLuidToNameW = GetProcAddress(IPHLPAPI.dll, "ConvertInterfaceLuidToNameW");
	IPHLPAPI.oConvertInterfaceNameToLuidA = GetProcAddress(IPHLPAPI.dll, "ConvertInterfaceNameToLuidA");
	IPHLPAPI.oConvertInterfaceNameToLuidW = GetProcAddress(IPHLPAPI.dll, "ConvertInterfaceNameToLuidW");
	IPHLPAPI.oConvertInterfacePhysicalAddressToLuid = GetProcAddress(IPHLPAPI.dll, "ConvertInterfacePhysicalAddressToLuid");
	IPHLPAPI.oConvertIpv4MaskToLength = GetProcAddress(IPHLPAPI.dll, "ConvertIpv4MaskToLength");
	IPHLPAPI.oConvertLengthToIpv4Mask = GetProcAddress(IPHLPAPI.dll, "ConvertLengthToIpv4Mask");
	IPHLPAPI.oConvertRemoteInterfaceAliasToLuid = GetProcAddress(IPHLPAPI.dll, "ConvertRemoteInterfaceAliasToLuid");
	IPHLPAPI.oConvertRemoteInterfaceGuidToLuid = GetProcAddress(IPHLPAPI.dll, "ConvertRemoteInterfaceGuidToLuid");
	IPHLPAPI.oConvertRemoteInterfaceIndexToLuid = GetProcAddress(IPHLPAPI.dll, "ConvertRemoteInterfaceIndexToLuid");
	IPHLPAPI.oConvertRemoteInterfaceLuidToAlias = GetProcAddress(IPHLPAPI.dll, "ConvertRemoteInterfaceLuidToAlias");
	IPHLPAPI.oConvertRemoteInterfaceLuidToGuid = GetProcAddress(IPHLPAPI.dll, "ConvertRemoteInterfaceLuidToGuid");
	IPHLPAPI.oConvertRemoteInterfaceLuidToIndex = GetProcAddress(IPHLPAPI.dll, "ConvertRemoteInterfaceLuidToIndex");
	IPHLPAPI.oConvertStringToGuidA = GetProcAddress(IPHLPAPI.dll, "ConvertStringToGuidA");
	IPHLPAPI.oConvertStringToGuidW = GetProcAddress(IPHLPAPI.dll, "ConvertStringToGuidW");
	IPHLPAPI.oConvertStringToInterfacePhysicalAddress = GetProcAddress(IPHLPAPI.dll, "ConvertStringToInterfacePhysicalAddress");
	IPHLPAPI.oCreateAnycastIpAddressEntry = GetProcAddress(IPHLPAPI.dll, "CreateAnycastIpAddressEntry");
	IPHLPAPI.oCreateCompartment = GetProcAddress(IPHLPAPI.dll, "CreateCompartment");
	IPHLPAPI.oCreateIpForwardEntry = GetProcAddress(IPHLPAPI.dll, "CreateIpForwardEntry");
	IPHLPAPI.oCreateIpForwardEntry2 = GetProcAddress(IPHLPAPI.dll, "CreateIpForwardEntry2");
	IPHLPAPI.oCreateIpNetEntry = GetProcAddress(IPHLPAPI.dll, "CreateIpNetEntry");
	IPHLPAPI.oCreateIpNetEntry2 = GetProcAddress(IPHLPAPI.dll, "CreateIpNetEntry2");
	IPHLPAPI.oCreatePersistentTcpPortReservation = GetProcAddress(IPHLPAPI.dll, "CreatePersistentTcpPortReservation");
	IPHLPAPI.oCreatePersistentUdpPortReservation = GetProcAddress(IPHLPAPI.dll, "CreatePersistentUdpPortReservation");
	IPHLPAPI.oCreateProxyArpEntry = GetProcAddress(IPHLPAPI.dll, "CreateProxyArpEntry");
	IPHLPAPI.oCreateSortedAddressPairs = GetProcAddress(IPHLPAPI.dll, "CreateSortedAddressPairs");
	IPHLPAPI.oCreateUnicastIpAddressEntry = GetProcAddress(IPHLPAPI.dll, "CreateUnicastIpAddressEntry");
	IPHLPAPI.oDeleteAnycastIpAddressEntry = GetProcAddress(IPHLPAPI.dll, "DeleteAnycastIpAddressEntry");
	IPHLPAPI.oDeleteCompartment = GetProcAddress(IPHLPAPI.dll, "DeleteCompartment");
	IPHLPAPI.oDeleteIPAddress = GetProcAddress(IPHLPAPI.dll, "DeleteIPAddress");
	IPHLPAPI.oDeleteIpForwardEntry = GetProcAddress(IPHLPAPI.dll, "DeleteIpForwardEntry");
	IPHLPAPI.oDeleteIpForwardEntry2 = GetProcAddress(IPHLPAPI.dll, "DeleteIpForwardEntry2");
	IPHLPAPI.oDeleteIpNetEntry = GetProcAddress(IPHLPAPI.dll, "DeleteIpNetEntry");
	IPHLPAPI.oDeleteIpNetEntry2 = GetProcAddress(IPHLPAPI.dll, "DeleteIpNetEntry2");
	IPHLPAPI.oDeletePersistentTcpPortReservation = GetProcAddress(IPHLPAPI.dll, "DeletePersistentTcpPortReservation");
	IPHLPAPI.oDeletePersistentUdpPortReservation = GetProcAddress(IPHLPAPI.dll, "DeletePersistentUdpPortReservation");
	IPHLPAPI.oDeleteProxyArpEntry = GetProcAddress(IPHLPAPI.dll, "DeleteProxyArpEntry");
	IPHLPAPI.oDeleteUnicastIpAddressEntry = GetProcAddress(IPHLPAPI.dll, "DeleteUnicastIpAddressEntry");
	IPHLPAPI.oDisableMediaSense = GetProcAddress(IPHLPAPI.dll, "DisableMediaSense");
	IPHLPAPI.oEnableRouter = GetProcAddress(IPHLPAPI.dll, "EnableRouter");
	IPHLPAPI.oFlushIpNetTable = GetProcAddress(IPHLPAPI.dll, "FlushIpNetTable");
	IPHLPAPI.oFlushIpNetTable2 = GetProcAddress(IPHLPAPI.dll, "FlushIpNetTable2");
	IPHLPAPI.oFlushIpPathTable = GetProcAddress(IPHLPAPI.dll, "FlushIpPathTable");
	IPHLPAPI.oFreeDnsSettings = GetProcAddress(IPHLPAPI.dll, "FreeDnsSettings");
	IPHLPAPI.oFreeInterfaceDnsSettings = GetProcAddress(IPHLPAPI.dll, "FreeInterfaceDnsSettings");
	IPHLPAPI.oFreeMibTable = GetProcAddress(IPHLPAPI.dll, "FreeMibTable");
	IPHLPAPI.oGetAdapterIndex = GetProcAddress(IPHLPAPI.dll, "GetAdapterIndex");
	IPHLPAPI.oGetAdapterOrderMap = GetProcAddress(IPHLPAPI.dll, "GetAdapterOrderMap");
	IPHLPAPI.oGetAdaptersAddresses = GetProcAddress(IPHLPAPI.dll, "GetAdaptersAddresses");
	IPHLPAPI.oGetAdaptersInfo = GetProcAddress(IPHLPAPI.dll, "GetAdaptersInfo");
	IPHLPAPI.oGetAnycastIpAddressEntry = GetProcAddress(IPHLPAPI.dll, "GetAnycastIpAddressEntry");
	IPHLPAPI.oGetAnycastIpAddressTable = GetProcAddress(IPHLPAPI.dll, "GetAnycastIpAddressTable");
	IPHLPAPI.oGetBestInterface = GetProcAddress(IPHLPAPI.dll, "GetBestInterface");
	IPHLPAPI.oGetBestInterfaceEx = GetProcAddress(IPHLPAPI.dll, "GetBestInterfaceEx");
	IPHLPAPI.oGetBestRoute = GetProcAddress(IPHLPAPI.dll, "GetBestRoute");
	IPHLPAPI.oGetBestRoute2 = GetProcAddress(IPHLPAPI.dll, "GetBestRoute2");
	IPHLPAPI.oGetCurrentThreadCompartmentId = GetProcAddress(IPHLPAPI.dll, "GetCurrentThreadCompartmentId");
	IPHLPAPI.oGetCurrentThreadCompartmentScope = GetProcAddress(IPHLPAPI.dll, "GetCurrentThreadCompartmentScope");
	IPHLPAPI.oGetDefaultCompartmentId = GetProcAddress(IPHLPAPI.dll, "GetDefaultCompartmentId");
	IPHLPAPI.oGetDnsSettings = GetProcAddress(IPHLPAPI.dll, "GetDnsSettings");
	IPHLPAPI.oGetExtendedTcpTable = GetProcAddress(IPHLPAPI.dll, "GetExtendedTcpTable");
	IPHLPAPI.oGetExtendedUdpTable = GetProcAddress(IPHLPAPI.dll, "GetExtendedUdpTable");
	IPHLPAPI.oGetFriendlyIfIndex = GetProcAddress(IPHLPAPI.dll, "GetFriendlyIfIndex");
	IPHLPAPI.oGetIcmpStatistics = GetProcAddress(IPHLPAPI.dll, "GetIcmpStatistics");
	IPHLPAPI.oGetIcmpStatisticsEx = GetProcAddress(IPHLPAPI.dll, "GetIcmpStatisticsEx");
	IPHLPAPI.oGetIfEntry = GetProcAddress(IPHLPAPI.dll, "GetIfEntry");
	IPHLPAPI.oGetIfEntry2 = GetProcAddress(IPHLPAPI.dll, "GetIfEntry2");
	IPHLPAPI.oGetIfEntry2Ex = GetProcAddress(IPHLPAPI.dll, "GetIfEntry2Ex");
	IPHLPAPI.oGetIfStackTable = GetProcAddress(IPHLPAPI.dll, "GetIfStackTable");
	IPHLPAPI.oGetIfTable = GetProcAddress(IPHLPAPI.dll, "GetIfTable");
	IPHLPAPI.oGetIfTable2 = GetProcAddress(IPHLPAPI.dll, "GetIfTable2");
	IPHLPAPI.oGetIfTable2Ex = GetProcAddress(IPHLPAPI.dll, "GetIfTable2Ex");
	IPHLPAPI.oGetInterfaceCompartmentId = GetProcAddress(IPHLPAPI.dll, "GetInterfaceCompartmentId");
	IPHLPAPI.oGetInterfaceCurrentTimestampCapabilities = GetProcAddress(IPHLPAPI.dll, "GetInterfaceCurrentTimestampCapabilities");
	IPHLPAPI.oGetInterfaceDnsSettings = GetProcAddress(IPHLPAPI.dll, "GetInterfaceDnsSettings");
	IPHLPAPI.oGetInterfaceHardwareTimestampCapabilities = GetProcAddress(IPHLPAPI.dll, "GetInterfaceHardwareTimestampCapabilities");
	IPHLPAPI.oGetInterfaceInfo = GetProcAddress(IPHLPAPI.dll, "GetInterfaceInfo");
	IPHLPAPI.oGetInvertedIfStackTable = GetProcAddress(IPHLPAPI.dll, "GetInvertedIfStackTable");
	IPHLPAPI.oGetIpAddrTable = GetProcAddress(IPHLPAPI.dll, "GetIpAddrTable");
	IPHLPAPI.oGetIpErrorString = GetProcAddress(IPHLPAPI.dll, "GetIpErrorString");
	IPHLPAPI.oGetIpForwardEntry2 = GetProcAddress(IPHLPAPI.dll, "GetIpForwardEntry2");
	IPHLPAPI.oGetIpForwardTable = GetProcAddress(IPHLPAPI.dll, "GetIpForwardTable");
	IPHLPAPI.oGetIpForwardTable2 = GetProcAddress(IPHLPAPI.dll, "GetIpForwardTable2");
	IPHLPAPI.oGetIpInterfaceEntry = GetProcAddress(IPHLPAPI.dll, "GetIpInterfaceEntry");
	IPHLPAPI.oGetIpInterfaceTable = GetProcAddress(IPHLPAPI.dll, "GetIpInterfaceTable");
	IPHLPAPI.oGetIpNetEntry2 = GetProcAddress(IPHLPAPI.dll, "GetIpNetEntry2");
	IPHLPAPI.oGetIpNetTable = GetProcAddress(IPHLPAPI.dll, "GetIpNetTable");
	IPHLPAPI.oGetIpNetTable2 = GetProcAddress(IPHLPAPI.dll, "GetIpNetTable2");
	IPHLPAPI.oGetIpNetworkConnectionBandwidthEstimates = GetProcAddress(IPHLPAPI.dll, "GetIpNetworkConnectionBandwidthEstimates");
	IPHLPAPI.oGetIpPathEntry = GetProcAddress(IPHLPAPI.dll, "GetIpPathEntry");
	IPHLPAPI.oGetIpPathTable = GetProcAddress(IPHLPAPI.dll, "GetIpPathTable");
	IPHLPAPI.oGetIpStatistics = GetProcAddress(IPHLPAPI.dll, "GetIpStatistics");
	IPHLPAPI.oGetIpStatisticsEx = GetProcAddress(IPHLPAPI.dll, "GetIpStatisticsEx");
	IPHLPAPI.oGetJobCompartmentId = GetProcAddress(IPHLPAPI.dll, "GetJobCompartmentId");
	IPHLPAPI.oGetMulticastIpAddressEntry = GetProcAddress(IPHLPAPI.dll, "GetMulticastIpAddressEntry");
	IPHLPAPI.oGetMulticastIpAddressTable = GetProcAddress(IPHLPAPI.dll, "GetMulticastIpAddressTable");
	IPHLPAPI.oGetNetworkConnectivityHint = GetProcAddress(IPHLPAPI.dll, "GetNetworkConnectivityHint");
	IPHLPAPI.oGetNetworkConnectivityHintForInterface = GetProcAddress(IPHLPAPI.dll, "GetNetworkConnectivityHintForInterface");
	IPHLPAPI.oGetNetworkInformation = GetProcAddress(IPHLPAPI.dll, "GetNetworkInformation");
	IPHLPAPI.oGetNetworkParams = GetProcAddress(IPHLPAPI.dll, "GetNetworkParams");
	IPHLPAPI.oGetNumberOfInterfaces = GetProcAddress(IPHLPAPI.dll, "GetNumberOfInterfaces");
	IPHLPAPI.oGetOwnerModuleFromPidAndInfo = GetProcAddress(IPHLPAPI.dll, "GetOwnerModuleFromPidAndInfo");
	IPHLPAPI.oGetOwnerModuleFromTcp6Entry = GetProcAddress(IPHLPAPI.dll, "GetOwnerModuleFromTcp6Entry");
	IPHLPAPI.oGetOwnerModuleFromTcpEntry = GetProcAddress(IPHLPAPI.dll, "GetOwnerModuleFromTcpEntry");
	IPHLPAPI.oGetOwnerModuleFromUdp6Entry = GetProcAddress(IPHLPAPI.dll, "GetOwnerModuleFromUdp6Entry");
	IPHLPAPI.oGetOwnerModuleFromUdpEntry = GetProcAddress(IPHLPAPI.dll, "GetOwnerModuleFromUdpEntry");
	IPHLPAPI.oGetPerAdapterInfo = GetProcAddress(IPHLPAPI.dll, "GetPerAdapterInfo");
	IPHLPAPI.oGetPerTcp6ConnectionEStats = GetProcAddress(IPHLPAPI.dll, "GetPerTcp6ConnectionEStats");
	IPHLPAPI.oGetPerTcp6ConnectionStats = GetProcAddress(IPHLPAPI.dll, "GetPerTcp6ConnectionStats");
	IPHLPAPI.oGetPerTcpConnectionEStats = GetProcAddress(IPHLPAPI.dll, "GetPerTcpConnectionEStats");
	IPHLPAPI.oGetPerTcpConnectionStats = GetProcAddress(IPHLPAPI.dll, "GetPerTcpConnectionStats");
	IPHLPAPI.oGetRTTAndHopCount = GetProcAddress(IPHLPAPI.dll, "GetRTTAndHopCount");
	IPHLPAPI.oGetSessionCompartmentId = GetProcAddress(IPHLPAPI.dll, "GetSessionCompartmentId");
	IPHLPAPI.oGetTcp6Table = GetProcAddress(IPHLPAPI.dll, "GetTcp6Table");
	IPHLPAPI.oGetTcp6Table2 = GetProcAddress(IPHLPAPI.dll, "GetTcp6Table2");
	IPHLPAPI.oGetTcpStatistics = GetProcAddress(IPHLPAPI.dll, "GetTcpStatistics");
	IPHLPAPI.oGetTcpStatisticsEx = GetProcAddress(IPHLPAPI.dll, "GetTcpStatisticsEx");
	IPHLPAPI.oGetTcpStatisticsEx2 = GetProcAddress(IPHLPAPI.dll, "GetTcpStatisticsEx2");
	IPHLPAPI.oGetTcpTable = GetProcAddress(IPHLPAPI.dll, "GetTcpTable");
	IPHLPAPI.oGetTcpTable2 = GetProcAddress(IPHLPAPI.dll, "GetTcpTable2");
	IPHLPAPI.oGetTeredoPort = GetProcAddress(IPHLPAPI.dll, "GetTeredoPort");
	IPHLPAPI.oGetUdp6Table = GetProcAddress(IPHLPAPI.dll, "GetUdp6Table");
	IPHLPAPI.oGetUdpStatistics = GetProcAddress(IPHLPAPI.dll, "GetUdpStatistics");
	IPHLPAPI.oGetUdpStatisticsEx = GetProcAddress(IPHLPAPI.dll, "GetUdpStatisticsEx");
	IPHLPAPI.oGetUdpStatisticsEx2 = GetProcAddress(IPHLPAPI.dll, "GetUdpStatisticsEx2");
	IPHLPAPI.oGetUdpTable = GetProcAddress(IPHLPAPI.dll, "GetUdpTable");
	IPHLPAPI.oGetUniDirectionalAdapterInfo = GetProcAddress(IPHLPAPI.dll, "GetUniDirectionalAdapterInfo");
	IPHLPAPI.oGetUnicastIpAddressEntry = GetProcAddress(IPHLPAPI.dll, "GetUnicastIpAddressEntry");
	IPHLPAPI.oGetUnicastIpAddressTable = GetProcAddress(IPHLPAPI.dll, "GetUnicastIpAddressTable");
	IPHLPAPI.oGetWPAOACSupportLevel = GetProcAddress(IPHLPAPI.dll, "GetWPAOACSupportLevel");
	IPHLPAPI.oIcmp6CreateFile = GetProcAddress(IPHLPAPI.dll, "Icmp6CreateFile");
	IPHLPAPI.oIcmp6ParseReplies = GetProcAddress(IPHLPAPI.dll, "Icmp6ParseReplies");
	IPHLPAPI.oIcmp6SendEcho2 = GetProcAddress(IPHLPAPI.dll, "Icmp6SendEcho2");
	IPHLPAPI.oIcmpCloseHandle = GetProcAddress(IPHLPAPI.dll, "IcmpCloseHandle");
	IPHLPAPI.oIcmpCreateFile = GetProcAddress(IPHLPAPI.dll, "IcmpCreateFile");
	IPHLPAPI.oIcmpParseReplies = GetProcAddress(IPHLPAPI.dll, "IcmpParseReplies");
	IPHLPAPI.oIcmpSendEcho = GetProcAddress(IPHLPAPI.dll, "IcmpSendEcho");
	IPHLPAPI.oIcmpSendEcho2 = GetProcAddress(IPHLPAPI.dll, "IcmpSendEcho2");
	IPHLPAPI.oIcmpSendEcho2Ex = GetProcAddress(IPHLPAPI.dll, "IcmpSendEcho2Ex");
	IPHLPAPI.oInitializeCompartmentEntry = GetProcAddress(IPHLPAPI.dll, "InitializeCompartmentEntry");
	IPHLPAPI.oInitializeIpForwardEntry = GetProcAddress(IPHLPAPI.dll, "InitializeIpForwardEntry");
	IPHLPAPI.oInitializeIpInterfaceEntry = GetProcAddress(IPHLPAPI.dll, "InitializeIpInterfaceEntry");
	IPHLPAPI.oInitializeUnicastIpAddressEntry = GetProcAddress(IPHLPAPI.dll, "InitializeUnicastIpAddressEntry");
	IPHLPAPI.oInternalCleanupPersistentStore = GetProcAddress(IPHLPAPI.dll, "InternalCleanupPersistentStore");
	IPHLPAPI.oInternalCreateAnycastIpAddressEntry = GetProcAddress(IPHLPAPI.dll, "InternalCreateAnycastIpAddressEntry");
	IPHLPAPI.oInternalCreateIpForwardEntry = GetProcAddress(IPHLPAPI.dll, "InternalCreateIpForwardEntry");
	IPHLPAPI.oInternalCreateIpForwardEntry2 = GetProcAddress(IPHLPAPI.dll, "InternalCreateIpForwardEntry2");
	IPHLPAPI.oInternalCreateIpNetEntry = GetProcAddress(IPHLPAPI.dll, "InternalCreateIpNetEntry");
	IPHLPAPI.oInternalCreateIpNetEntry2 = GetProcAddress(IPHLPAPI.dll, "InternalCreateIpNetEntry2");
	IPHLPAPI.oInternalCreateOrRefIpForwardEntry2 = GetProcAddress(IPHLPAPI.dll, "InternalCreateOrRefIpForwardEntry2");
	IPHLPAPI.oInternalCreateUnicastIpAddressEntry = GetProcAddress(IPHLPAPI.dll, "InternalCreateUnicastIpAddressEntry");
	IPHLPAPI.oInternalDeleteAnycastIpAddressEntry = GetProcAddress(IPHLPAPI.dll, "InternalDeleteAnycastIpAddressEntry");
	IPHLPAPI.oInternalDeleteIpForwardEntry = GetProcAddress(IPHLPAPI.dll, "InternalDeleteIpForwardEntry");
	IPHLPAPI.oInternalDeleteIpForwardEntry2 = GetProcAddress(IPHLPAPI.dll, "InternalDeleteIpForwardEntry2");
	IPHLPAPI.oInternalDeleteIpNetEntry = GetProcAddress(IPHLPAPI.dll, "InternalDeleteIpNetEntry");
	IPHLPAPI.oInternalDeleteIpNetEntry2 = GetProcAddress(IPHLPAPI.dll, "InternalDeleteIpNetEntry2");
	IPHLPAPI.oInternalDeleteUnicastIpAddressEntry = GetProcAddress(IPHLPAPI.dll, "InternalDeleteUnicastIpAddressEntry");
	IPHLPAPI.oInternalFindInterfaceByAddress = GetProcAddress(IPHLPAPI.dll, "InternalFindInterfaceByAddress");
	IPHLPAPI.oInternalGetAnycastIpAddressEntry = GetProcAddress(IPHLPAPI.dll, "InternalGetAnycastIpAddressEntry");
	IPHLPAPI.oInternalGetAnycastIpAddressTable = GetProcAddress(IPHLPAPI.dll, "InternalGetAnycastIpAddressTable");
	IPHLPAPI.oInternalGetBoundTcp6EndpointTable = GetProcAddress(IPHLPAPI.dll, "InternalGetBoundTcp6EndpointTable");
	IPHLPAPI.oInternalGetBoundTcpEndpointTable = GetProcAddress(IPHLPAPI.dll, "InternalGetBoundTcpEndpointTable");
	IPHLPAPI.oInternalGetForwardIpTable2 = GetProcAddress(IPHLPAPI.dll, "InternalGetForwardIpTable2");
	IPHLPAPI.oInternalGetIPPhysicalInterfaceForDestination = GetProcAddress(IPHLPAPI.dll, "InternalGetIPPhysicalInterfaceForDestination");
	IPHLPAPI.oInternalGetIfEntry2 = GetProcAddress(IPHLPAPI.dll, "InternalGetIfEntry2");
	IPHLPAPI.oInternalGetIfTable = GetProcAddress(IPHLPAPI.dll, "InternalGetIfTable");
	IPHLPAPI.oInternalGetIfTable2 = GetProcAddress(IPHLPAPI.dll, "InternalGetIfTable2");
	IPHLPAPI.oInternalGetIpAddrTable = GetProcAddress(IPHLPAPI.dll, "InternalGetIpAddrTable");
	IPHLPAPI.oInternalGetIpForwardEntry2 = GetProcAddress(IPHLPAPI.dll, "InternalGetIpForwardEntry2");
	IPHLPAPI.oInternalGetIpForwardTable = GetProcAddress(IPHLPAPI.dll, "InternalGetIpForwardTable");
	IPHLPAPI.oInternalGetIpInterfaceEntry = GetProcAddress(IPHLPAPI.dll, "InternalGetIpInterfaceEntry");
	IPHLPAPI.oInternalGetIpInterfaceTable = GetProcAddress(IPHLPAPI.dll, "InternalGetIpInterfaceTable");
	IPHLPAPI.oInternalGetIpNetEntry2 = GetProcAddress(IPHLPAPI.dll, "InternalGetIpNetEntry2");
	IPHLPAPI.oInternalGetIpNetTable = GetProcAddress(IPHLPAPI.dll, "InternalGetIpNetTable");
	IPHLPAPI.oInternalGetIpNetTable2 = GetProcAddress(IPHLPAPI.dll, "InternalGetIpNetTable2");
	IPHLPAPI.oInternalGetMulticastIpAddressEntry = GetProcAddress(IPHLPAPI.dll, "InternalGetMulticastIpAddressEntry");
	IPHLPAPI.oInternalGetMulticastIpAddressTable = GetProcAddress(IPHLPAPI.dll, "InternalGetMulticastIpAddressTable");
	IPHLPAPI.oInternalGetRtcSlotInformation = GetProcAddress(IPHLPAPI.dll, "InternalGetRtcSlotInformation");
	IPHLPAPI.oInternalGetTcp6Table2 = GetProcAddress(IPHLPAPI.dll, "InternalGetTcp6Table2");
	IPHLPAPI.oInternalGetTcp6TableWithOwnerModule = GetProcAddress(IPHLPAPI.dll, "InternalGetTcp6TableWithOwnerModule");
	IPHLPAPI.oInternalGetTcp6TableWithOwnerPid = GetProcAddress(IPHLPAPI.dll, "InternalGetTcp6TableWithOwnerPid");
	IPHLPAPI.oInternalGetTcpTable = GetProcAddress(IPHLPAPI.dll, "InternalGetTcpTable");
	IPHLPAPI.oInternalGetTcpTable2 = GetProcAddress(IPHLPAPI.dll, "InternalGetTcpTable2");
	IPHLPAPI.oInternalGetTcpTableEx = GetProcAddress(IPHLPAPI.dll, "InternalGetTcpTableEx");
	IPHLPAPI.oInternalGetTcpTableWithOwnerModule = GetProcAddress(IPHLPAPI.dll, "InternalGetTcpTableWithOwnerModule");
	IPHLPAPI.oInternalGetTcpTableWithOwnerPid = GetProcAddress(IPHLPAPI.dll, "InternalGetTcpTableWithOwnerPid");
	IPHLPAPI.oInternalGetTunnelPhysicalAdapter = GetProcAddress(IPHLPAPI.dll, "InternalGetTunnelPhysicalAdapter");
	IPHLPAPI.oInternalGetUdp6TableWithOwnerModule = GetProcAddress(IPHLPAPI.dll, "InternalGetUdp6TableWithOwnerModule");
	IPHLPAPI.oInternalGetUdp6TableWithOwnerPid = GetProcAddress(IPHLPAPI.dll, "InternalGetUdp6TableWithOwnerPid");
	IPHLPAPI.oInternalGetUdpTable = GetProcAddress(IPHLPAPI.dll, "InternalGetUdpTable");
	IPHLPAPI.oInternalGetUdpTableEx = GetProcAddress(IPHLPAPI.dll, "InternalGetUdpTableEx");
	IPHLPAPI.oInternalGetUdpTableWithOwnerModule = GetProcAddress(IPHLPAPI.dll, "InternalGetUdpTableWithOwnerModule");
	IPHLPAPI.oInternalGetUdpTableWithOwnerPid = GetProcAddress(IPHLPAPI.dll, "InternalGetUdpTableWithOwnerPid");
	IPHLPAPI.oInternalGetUnicastIpAddressEntry = GetProcAddress(IPHLPAPI.dll, "InternalGetUnicastIpAddressEntry");
	IPHLPAPI.oInternalGetUnicastIpAddressTable = GetProcAddress(IPHLPAPI.dll, "InternalGetUnicastIpAddressTable");
	IPHLPAPI.oInternalIcmpCreateFileEx = GetProcAddress(IPHLPAPI.dll, "InternalIcmpCreateFileEx");
	IPHLPAPI.oInternalSetIfEntry = GetProcAddress(IPHLPAPI.dll, "InternalSetIfEntry");
	IPHLPAPI.oInternalSetIpForwardEntry = GetProcAddress(IPHLPAPI.dll, "InternalSetIpForwardEntry");
	IPHLPAPI.oInternalSetIpForwardEntry2 = GetProcAddress(IPHLPAPI.dll, "InternalSetIpForwardEntry2");
	IPHLPAPI.oInternalSetIpInterfaceEntry = GetProcAddress(IPHLPAPI.dll, "InternalSetIpInterfaceEntry");
	IPHLPAPI.oInternalSetIpNetEntry = GetProcAddress(IPHLPAPI.dll, "InternalSetIpNetEntry");
	IPHLPAPI.oInternalSetIpNetEntry2 = GetProcAddress(IPHLPAPI.dll, "InternalSetIpNetEntry2");
	IPHLPAPI.oInternalSetIpStats = GetProcAddress(IPHLPAPI.dll, "InternalSetIpStats");
	IPHLPAPI.oInternalSetTcpEntry = GetProcAddress(IPHLPAPI.dll, "InternalSetTcpEntry");
	IPHLPAPI.oInternalSetTeredoPort = GetProcAddress(IPHLPAPI.dll, "InternalSetTeredoPort");
	IPHLPAPI.oInternalSetUnicastIpAddressEntry = GetProcAddress(IPHLPAPI.dll, "InternalSetUnicastIpAddressEntry");
	IPHLPAPI.oIpReleaseAddress = GetProcAddress(IPHLPAPI.dll, "IpReleaseAddress");
	IPHLPAPI.oIpRenewAddress = GetProcAddress(IPHLPAPI.dll, "IpRenewAddress");
	IPHLPAPI.oLookupPersistentTcpPortReservation = GetProcAddress(IPHLPAPI.dll, "LookupPersistentTcpPortReservation");
	IPHLPAPI.oLookupPersistentUdpPortReservation = GetProcAddress(IPHLPAPI.dll, "LookupPersistentUdpPortReservation");
	IPHLPAPI.oNTPTimeToNTFileTime = GetProcAddress(IPHLPAPI.dll, "NTPTimeToNTFileTime");
	IPHLPAPI.oNTTimeToNTPTime = GetProcAddress(IPHLPAPI.dll, "NTTimeToNTPTime");
	IPHLPAPI.oNhGetGuidFromInterfaceName = GetProcAddress(IPHLPAPI.dll, "NhGetGuidFromInterfaceName");
	IPHLPAPI.oNhGetInterfaceDescriptionFromGuid = GetProcAddress(IPHLPAPI.dll, "NhGetInterfaceDescriptionFromGuid");
	IPHLPAPI.oNhGetInterfaceNameFromDeviceGuid = GetProcAddress(IPHLPAPI.dll, "NhGetInterfaceNameFromDeviceGuid");
	IPHLPAPI.oNhGetInterfaceNameFromGuid = GetProcAddress(IPHLPAPI.dll, "NhGetInterfaceNameFromGuid");
	IPHLPAPI.oNhpAllocateAndGetInterfaceInfoFromStack = GetProcAddress(IPHLPAPI.dll, "NhpAllocateAndGetInterfaceInfoFromStack");
	IPHLPAPI.oNotifyAddrChange = GetProcAddress(IPHLPAPI.dll, "NotifyAddrChange");
	IPHLPAPI.oNotifyCompartmentChange = GetProcAddress(IPHLPAPI.dll, "NotifyCompartmentChange");
	IPHLPAPI.oNotifyIfTimestampConfigChange = GetProcAddress(IPHLPAPI.dll, "NotifyIfTimestampConfigChange");
	IPHLPAPI.oNotifyIpInterfaceChange = GetProcAddress(IPHLPAPI.dll, "NotifyIpInterfaceChange");
	IPHLPAPI.oNotifyNetworkConnectivityHintChange = GetProcAddress(IPHLPAPI.dll, "NotifyNetworkConnectivityHintChange");
	IPHLPAPI.oNotifyRouteChange = GetProcAddress(IPHLPAPI.dll, "NotifyRouteChange");
	IPHLPAPI.oNotifyRouteChange2 = GetProcAddress(IPHLPAPI.dll, "NotifyRouteChange2");
	IPHLPAPI.oNotifyStableUnicastIpAddressTable = GetProcAddress(IPHLPAPI.dll, "NotifyStableUnicastIpAddressTable");
	IPHLPAPI.oNotifyTeredoPortChange = GetProcAddress(IPHLPAPI.dll, "NotifyTeredoPortChange");
	IPHLPAPI.oNotifyUnicastIpAddressChange = GetProcAddress(IPHLPAPI.dll, "NotifyUnicastIpAddressChange");
	IPHLPAPI.oOpenCompartment = GetProcAddress(IPHLPAPI.dll, "OpenCompartment");
	IPHLPAPI.oParseNetworkString = GetProcAddress(IPHLPAPI.dll, "ParseNetworkString");
	IPHLPAPI.oPfAddFiltersToInterface = GetProcAddress(IPHLPAPI.dll, "PfAddFiltersToInterface");
	IPHLPAPI.oPfAddGlobalFilterToInterface = GetProcAddress(IPHLPAPI.dll, "PfAddGlobalFilterToInterface");
	IPHLPAPI.oPfBindInterfaceToIPAddress = GetProcAddress(IPHLPAPI.dll, "PfBindInterfaceToIPAddress");
	IPHLPAPI.oPfBindInterfaceToIndex = GetProcAddress(IPHLPAPI.dll, "PfBindInterfaceToIndex");
	IPHLPAPI.oPfCreateInterface = GetProcAddress(IPHLPAPI.dll, "PfCreateInterface");
	IPHLPAPI.oPfDeleteInterface = GetProcAddress(IPHLPAPI.dll, "PfDeleteInterface");
	IPHLPAPI.oPfDeleteLog = GetProcAddress(IPHLPAPI.dll, "PfDeleteLog");
	IPHLPAPI.oPfGetInterfaceStatistics = GetProcAddress(IPHLPAPI.dll, "PfGetInterfaceStatistics");
	IPHLPAPI.oPfMakeLog = GetProcAddress(IPHLPAPI.dll, "PfMakeLog");
	IPHLPAPI.oPfRebindFilters = GetProcAddress(IPHLPAPI.dll, "PfRebindFilters");
	IPHLPAPI.oPfRemoveFilterHandles = GetProcAddress(IPHLPAPI.dll, "PfRemoveFilterHandles");
	IPHLPAPI.oPfRemoveFiltersFromInterface = GetProcAddress(IPHLPAPI.dll, "PfRemoveFiltersFromInterface");
	IPHLPAPI.oPfRemoveGlobalFilterFromInterface = GetProcAddress(IPHLPAPI.dll, "PfRemoveGlobalFilterFromInterface");
	IPHLPAPI.oPfSetLogBuffer = GetProcAddress(IPHLPAPI.dll, "PfSetLogBuffer");
	IPHLPAPI.oPfTestPacket = GetProcAddress(IPHLPAPI.dll, "PfTestPacket");
	IPHLPAPI.oPfUnBindInterface = GetProcAddress(IPHLPAPI.dll, "PfUnBindInterface");
	IPHLPAPI.oResolveIpNetEntry2 = GetProcAddress(IPHLPAPI.dll, "ResolveIpNetEntry2");
	IPHLPAPI.oResolveNeighbor = GetProcAddress(IPHLPAPI.dll, "ResolveNeighbor");
	IPHLPAPI.oRestoreMediaSense = GetProcAddress(IPHLPAPI.dll, "RestoreMediaSense");
	IPHLPAPI.oSendARP = GetProcAddress(IPHLPAPI.dll, "SendARP");
	IPHLPAPI.oSetAdapterIpAddress = GetProcAddress(IPHLPAPI.dll, "SetAdapterIpAddress");
	IPHLPAPI.oSetCurrentThreadCompartmentId = GetProcAddress(IPHLPAPI.dll, "SetCurrentThreadCompartmentId");
	IPHLPAPI.oSetCurrentThreadCompartmentScope = GetProcAddress(IPHLPAPI.dll, "SetCurrentThreadCompartmentScope");
	IPHLPAPI.oSetDnsSettings = GetProcAddress(IPHLPAPI.dll, "SetDnsSettings");
	IPHLPAPI.oSetIfEntry = GetProcAddress(IPHLPAPI.dll, "SetIfEntry");
	IPHLPAPI.oSetInterfaceDnsSettings = GetProcAddress(IPHLPAPI.dll, "SetInterfaceDnsSettings");
	IPHLPAPI.oSetIpForwardEntry = GetProcAddress(IPHLPAPI.dll, "SetIpForwardEntry");
	IPHLPAPI.oSetIpForwardEntry2 = GetProcAddress(IPHLPAPI.dll, "SetIpForwardEntry2");
	IPHLPAPI.oSetIpInterfaceEntry = GetProcAddress(IPHLPAPI.dll, "SetIpInterfaceEntry");
	IPHLPAPI.oSetIpNetEntry = GetProcAddress(IPHLPAPI.dll, "SetIpNetEntry");
	IPHLPAPI.oSetIpNetEntry2 = GetProcAddress(IPHLPAPI.dll, "SetIpNetEntry2");
	IPHLPAPI.oSetIpStatistics = GetProcAddress(IPHLPAPI.dll, "SetIpStatistics");
	IPHLPAPI.oSetIpStatisticsEx = GetProcAddress(IPHLPAPI.dll, "SetIpStatisticsEx");
	IPHLPAPI.oSetIpTTL = GetProcAddress(IPHLPAPI.dll, "SetIpTTL");
	IPHLPAPI.oSetJobCompartmentId = GetProcAddress(IPHLPAPI.dll, "SetJobCompartmentId");
	IPHLPAPI.oSetNetworkInformation = GetProcAddress(IPHLPAPI.dll, "SetNetworkInformation");
	IPHLPAPI.oSetPerTcp6ConnectionEStats = GetProcAddress(IPHLPAPI.dll, "SetPerTcp6ConnectionEStats");
	IPHLPAPI.oSetPerTcp6ConnectionStats = GetProcAddress(IPHLPAPI.dll, "SetPerTcp6ConnectionStats");
	IPHLPAPI.oSetPerTcpConnectionEStats = GetProcAddress(IPHLPAPI.dll, "SetPerTcpConnectionEStats");
	IPHLPAPI.oSetPerTcpConnectionStats = GetProcAddress(IPHLPAPI.dll, "SetPerTcpConnectionStats");
	IPHLPAPI.oSetSessionCompartmentId = GetProcAddress(IPHLPAPI.dll, "SetSessionCompartmentId");
	IPHLPAPI.oSetTcpEntry = GetProcAddress(IPHLPAPI.dll, "SetTcpEntry");
	IPHLPAPI.oSetUnicastIpAddressEntry = GetProcAddress(IPHLPAPI.dll, "SetUnicastIpAddressEntry");
	IPHLPAPI.oUnenableRouter = GetProcAddress(IPHLPAPI.dll, "UnenableRouter");
	IPHLPAPI.odo_echo_rep = GetProcAddress(IPHLPAPI.dll, "do_echo_rep");
	IPHLPAPI.odo_echo_req = GetProcAddress(IPHLPAPI.dll, "do_echo_req");
	IPHLPAPI.oif_indextoname = GetProcAddress(IPHLPAPI.dll, "if_indextoname");
	IPHLPAPI.oif_nametoindex = GetProcAddress(IPHLPAPI.dll, "if_nametoindex");
	IPHLPAPI.oregister_icmp = GetProcAddress(IPHLPAPI.dll, "register_icmp");
}
#pragma endregion

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		char path[MAX_PATH];
		GetWindowsDirectory(path, sizeof(path));
		strcat_s(path, "\\System32\\IPHLPAPI.dll");
		IPHLPAPI.dll = LoadLibrary(path);
		setupFunctions();
		std::cout << "Injected DLL" << std::endl;
		g_BedrockMod = new BedrockMod();
		g_BedrockMod->Init();
		break;
	case DLL_PROCESS_DETACH:
		FreeLibrary(IPHLPAPI.dll);
		break;
	}
	return 1;
}
