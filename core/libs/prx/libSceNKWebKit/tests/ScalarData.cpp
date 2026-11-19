#include <cstdint>
#include <cstdio>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

static void Require(bool condition, const char* message) {
    if (!condition) {
        std::fprintf(stderr, "%s\n", message);
        std::exit(1);
    }
}

int main() {
#ifdef _WIN32
    auto library = LoadLibraryW(L"" NKWEBKIT_TEST_LIBRARY);
    auto symbol = [library](const char* name) { return reinterpret_cast<void*>(GetProcAddress(library, name)); };
#else
    auto library = dlopen(NKWEBKIT_TEST_LIBRARY, RTLD_NOW | RTLD_LOCAL);
    auto symbol = [library](const char* name) { return dlsym(library, name); };
#endif
    Require(library != nullptr, "could not load libSceNKWebKit");

    auto* end = static_cast<const std::int64_t*>(symbol("NUaLW57Xu7U_nid_no_patch_cut"));
    Require(end && end == symbol("libSceNKWebKitBlobToEndOfFile_nid_no_patch"), "end-of-file alias must share storage");
    Require(*end == -1, "end-of-file sentinel must be -1");

    auto* flag = static_cast<volatile bool*>(symbol("yssxWr+ar0U_nid_no_patch_cut"));
    auto* namedFlag = static_cast<volatile bool*>(symbol("libSceNKWebKitHas3DRendering_nid_no_patch"));
    Require(flag && flag == namedFlag, "3D rendering alias must share storage");
    Require(*flag, "3D rendering must start enabled");
    *flag = false;
    Require(!*namedFlag, "write through the alias must update the named flag");
    *namedFlag = true;
    Require(*flag, "write through the named flag must update the alias");
}
