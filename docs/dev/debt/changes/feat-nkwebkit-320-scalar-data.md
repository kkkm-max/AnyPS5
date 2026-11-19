# libSceNKWebKit

## add Functional

- [Scalar data exports](../../../core/libs/prx/libSceNKWebKit/Export.cpp) - `WebCore::BlobDataItem::toEndOfFile` and `WebCoreHas3DRendering` expose their observed initial values. The rendering flag is writable, but WebCore rendering is not implemented by these exports; no game compatibility is implied.
