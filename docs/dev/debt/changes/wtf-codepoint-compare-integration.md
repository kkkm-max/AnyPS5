# libSceNKWebKit

## add Unknown function info

- [WTF::codePointCompare](../../../core/libs/prx/libSceNKWebKit/src/WtfString.cpp) - console ABI and version equivalence are unverified. The two overloads reuse the existing release LP64 String and StringView layouts and follow [WebKit StringImpl.h](https://github.com/WebKit/WebKit/blob/0756854fafd4312b8f0126de111792e39db106ef/Source/WTF/wtf/text/StringImpl.h#L768-L804). A null character buffer throws when the common length is nonzero, where upstream would dereference it.

## remove `_ZN3WTF16codePointCompareENS_10StringViewES0_`

## remove `_ZN3WTF16codePointCompareERKNS_6StringES2_`
