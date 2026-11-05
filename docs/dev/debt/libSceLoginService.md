# libSceLoginService technical debt

### Unknown function info

- [sceLoginServiceInitialize, sceLoginServiceTerminate](../../../core/libs/prx/libSceLoginService/Export.cpp): initialization and termination behavior, including return values, repeated calls, and service side effects, remain unverified. EA SPORTS FC 27 (PPSA34015) calls `sceLoginServiceInitialize` with no arguments; its call site does not establish the result or side effects. Both exports throw until their contracts are established. The service cannot be initialized, including on Windows.

- [sceLoginServiceRequestDevices](../../../core/libs/prx/libSceLoginService/Export.cpp): the native wrapper confirms one read-only request pointer and transfers exactly 64 bytes to the login service. Null input returns 0x813a0003 before the initialization check; an uninitialized service returns 0x813a0001. The request fields are interpreted by the service backend and remain unresolved.
