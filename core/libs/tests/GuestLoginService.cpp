#include "prx/libSceLoginService/include/Api.hpp"
#include "prx/libc/include/general/VabiMacros.hpp"

#include <cstdlib>
#include <cstring>
#include <stdexcept>

namespace {

void Require(bool value) {
    if (!value) std::abort();
}

constexpr int kErrNotInitialized = static_cast<int>(0x813a0001u);
constexpr int kErrInvalidArg = static_cast<int>(0x813a0003u);

}

int main() {
    unsigned char buffer[0x80]{};
    const auto* request = reinterpret_cast<const LoginServiceDeviceRequest*>(buffer);

    Require(sceLoginServiceRequestDevices(nullptr) == kErrInvalidArg);
    Require(sceLoginServiceRequestDevices(request) == kErrNotInitialized);

    try {
        sceLoginServiceInitialize();
        std::abort();
    } catch (const std::runtime_error& error) {
        Require(std::strcmp(error.what(), "sceLoginServiceInitialize not implemented") == 0);
    }
    Require(sceLoginServiceRequestDevices(nullptr) == kErrInvalidArg);
    Require(sceLoginServiceRequestDevices(request) == kErrNotInitialized);

    try {
        sceLoginServiceTerminate();
        std::abort();
    } catch (const std::runtime_error& error) {
        Require(std::strcmp(error.what(), "sceLoginServiceTerminate not implemented") == 0);
    }
    Require(sceLoginServiceRequestDevices(nullptr) == kErrInvalidArg);
    Require(sceLoginServiceRequestDevices(request) == kErrNotInitialized);
    return 0;
}
