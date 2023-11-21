#include "raylib.h"
#include "pocketpy.h"

namespace pkpy{

template<typename T0, typename T1>
T1 _struct_cast(T0& v){
    static_assert(sizeof(T0) == sizeof(T1));
    static_assert(std::is_trivially_copyable_v<T0>);
    static_assert(std::is_trivially_copyable_v<T1>);
    return (T1&)v;
}

template<size_t N>
void _bind_enums(VM* vm, PyObject* obj, const std::pair<const char*, i64> (&enums)[N]){
    for(auto [k, v]: enums){
        obj->attr().set(k, py_var(vm, v));
    }
}

PyObject* py_var(VM* vm, Vector2 v){
    return py_var(vm, _struct_cast<Vector2, Vec2>(v));
}
template<>
Vector2 py_cast<Vector2>(VM* vm, PyObject* obj){
    Vec2 v = py_cast<Vec2>(vm, obj);
    return _struct_cast<Vec2, Vector2>(v);
}
template<>
Vector2 _py_cast<Vector2>(VM* vm, PyObject* obj){
    Vec2 v = _py_cast<Vec2>(vm, obj);
    return _struct_cast<Vec2, Vector2>(v);
}

PyObject* py_var(VM* vm, Vector3 v){
    return py_var(vm, _struct_cast<Vector3, Vec3>(v));
}
template<>
Vector3 py_cast<Vector3>(VM* vm, PyObject* obj){
    Vec3 v = py_cast<Vec3>(vm, obj);
    return _struct_cast<Vec3, Vector3>(v);
}
template<>
Vector3 _py_cast<Vector3>(VM* vm, PyObject* obj){
    Vec3 v = _py_cast<Vec3>(vm, obj);
    return _struct_cast<Vec3, Vector3>(v);
}

PyObject* py_var(VM* vm, Vector4 v){
    return py_var(vm, _struct_cast<Vector4, Vec4>(v));
}
template<>
Vector4 py_cast<Vector4>(VM* vm, PyObject* obj){
    Vec4 v = py_cast<Vec4>(vm, obj);
    return _struct_cast<Vec4, Vector4>(v);
}
template<>
Vector4 _py_cast<Vector4>(VM* vm, PyObject* obj){
    Vec4 v = _py_cast<Vec4>(vm, obj);
    return _struct_cast<Vec4, Vector4>(v);
}

/*************** Matrix ***************/
struct wrapped__Matrix{
    PY_CLASS(wrapped__Matrix, raylib, Matrix)

    Matrix _value;
    Matrix* _() { return &_value; }
    wrapped__Matrix() = default;
    wrapped__Matrix(const wrapped__Matrix& other) = default;

    wrapped__Matrix(const Matrix& other){
        memcpy(&_value, &other, sizeof(Matrix));
    }
    bool operator==(const wrapped__Matrix& other) const{
        return memcmp(&_value, &other._value, sizeof(Matrix)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"m0", "m4", "m8", "m12", "m1", "m5", "m9", "m13", "m2", "m6", "m10", "m14", "m3", "m7", "m11", "m15"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 16) vm->TypeError(fmt("expected 16 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__Matrix)
        PY_FIELD(wrapped__Matrix, "m0", _, m0)
        PY_FIELD(wrapped__Matrix, "m4", _, m4)
        PY_FIELD(wrapped__Matrix, "m8", _, m8)
        PY_FIELD(wrapped__Matrix, "m12", _, m12)
        PY_FIELD(wrapped__Matrix, "m1", _, m1)
        PY_FIELD(wrapped__Matrix, "m5", _, m5)
        PY_FIELD(wrapped__Matrix, "m9", _, m9)
        PY_FIELD(wrapped__Matrix, "m13", _, m13)
        PY_FIELD(wrapped__Matrix, "m2", _, m2)
        PY_FIELD(wrapped__Matrix, "m6", _, m6)
        PY_FIELD(wrapped__Matrix, "m10", _, m10)
        PY_FIELD(wrapped__Matrix, "m14", _, m14)
        PY_FIELD(wrapped__Matrix, "m3", _, m3)
        PY_FIELD(wrapped__Matrix, "m7", _, m7)
        PY_FIELD(wrapped__Matrix, "m11", _, m11)
        PY_FIELD(wrapped__Matrix, "m15", _, m15)
    }
};

PyObject* py_var(VM* vm, Matrix v){
    return VAR_T(wrapped__Matrix, v);
}
template<>
Matrix py_cast<Matrix>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__Matrix&>(vm, obj)._();
}
template<>
Matrix _py_cast<Matrix>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__Matrix&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const Matrix* v){
    const static std::pair<StrName, StrName> P("raylib", "Matrix_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** Color ***************/
struct wrapped__Color{
    PY_CLASS(wrapped__Color, raylib, Color)

    Color _value;
    Color* _() { return &_value; }
    wrapped__Color() = default;
    wrapped__Color(const wrapped__Color& other) = default;

    wrapped__Color(const Color& other){
        memcpy(&_value, &other, sizeof(Color));
    }
    bool operator==(const wrapped__Color& other) const{
        return memcmp(&_value, &other._value, sizeof(Color)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"r", "g", "b", "a"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 4) vm->TypeError(fmt("expected 4 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__Color)
        PY_FIELD(wrapped__Color, "r", _, r)
        PY_FIELD(wrapped__Color, "g", _, g)
        PY_FIELD(wrapped__Color, "b", _, b)
        PY_FIELD(wrapped__Color, "a", _, a)
    }
};

PyObject* py_var(VM* vm, Color v){
    return VAR_T(wrapped__Color, v);
}
template<>
Color py_cast<Color>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__Color&>(vm, obj)._();
}
template<>
Color _py_cast<Color>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__Color&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const Color* v){
    const static std::pair<StrName, StrName> P("raylib", "Color_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** Rectangle ***************/
struct wrapped__Rectangle{
    PY_CLASS(wrapped__Rectangle, raylib, Rectangle)

    Rectangle _value;
    Rectangle* _() { return &_value; }
    wrapped__Rectangle() = default;
    wrapped__Rectangle(const wrapped__Rectangle& other) = default;

    wrapped__Rectangle(const Rectangle& other){
        memcpy(&_value, &other, sizeof(Rectangle));
    }
    bool operator==(const wrapped__Rectangle& other) const{
        return memcmp(&_value, &other._value, sizeof(Rectangle)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"x", "y", "width", "height"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 4) vm->TypeError(fmt("expected 4 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__Rectangle)
        PY_FIELD(wrapped__Rectangle, "x", _, x)
        PY_FIELD(wrapped__Rectangle, "y", _, y)
        PY_FIELD(wrapped__Rectangle, "width", _, width)
        PY_FIELD(wrapped__Rectangle, "height", _, height)
    }
};

PyObject* py_var(VM* vm, Rectangle v){
    return VAR_T(wrapped__Rectangle, v);
}
template<>
Rectangle py_cast<Rectangle>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__Rectangle&>(vm, obj)._();
}
template<>
Rectangle _py_cast<Rectangle>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__Rectangle&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const Rectangle* v){
    const static std::pair<StrName, StrName> P("raylib", "Rectangle_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** Image ***************/
struct wrapped__Image{
    PY_CLASS(wrapped__Image, raylib, Image)

    Image _value;
    Image* _() { return &_value; }
    wrapped__Image() = default;
    wrapped__Image(const wrapped__Image& other) = default;

    wrapped__Image(const Image& other){
        memcpy(&_value, &other, sizeof(Image));
    }
    bool operator==(const wrapped__Image& other) const{
        return memcmp(&_value, &other._value, sizeof(Image)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"data", "width", "height", "mipmaps", "format"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 5) vm->TypeError(fmt("expected 5 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__Image)
        PY_FIELD(wrapped__Image, "data", _, data)
        PY_FIELD(wrapped__Image, "width", _, width)
        PY_FIELD(wrapped__Image, "height", _, height)
        PY_FIELD(wrapped__Image, "mipmaps", _, mipmaps)
        PY_FIELD(wrapped__Image, "format", _, format)
    }
};

PyObject* py_var(VM* vm, Image v){
    return VAR_T(wrapped__Image, v);
}
template<>
Image py_cast<Image>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__Image&>(vm, obj)._();
}
template<>
Image _py_cast<Image>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__Image&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const Image* v){
    const static std::pair<StrName, StrName> P("raylib", "Image_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** Texture ***************/
struct wrapped__Texture{
    PY_CLASS(wrapped__Texture, raylib, Texture)

    Texture _value;
    Texture* _() { return &_value; }
    wrapped__Texture() = default;
    wrapped__Texture(const wrapped__Texture& other) = default;

    wrapped__Texture(const Texture& other){
        memcpy(&_value, &other, sizeof(Texture));
    }
    bool operator==(const wrapped__Texture& other) const{
        return memcmp(&_value, &other._value, sizeof(Texture)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"id", "width", "height", "mipmaps", "format"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 5) vm->TypeError(fmt("expected 5 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__Texture)
        PY_FIELD(wrapped__Texture, "id", _, id)
        PY_FIELD(wrapped__Texture, "width", _, width)
        PY_FIELD(wrapped__Texture, "height", _, height)
        PY_FIELD(wrapped__Texture, "mipmaps", _, mipmaps)
        PY_FIELD(wrapped__Texture, "format", _, format)
    }
};

PyObject* py_var(VM* vm, Texture v){
    return VAR_T(wrapped__Texture, v);
}
template<>
Texture py_cast<Texture>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__Texture&>(vm, obj)._();
}
template<>
Texture _py_cast<Texture>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__Texture&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const Texture* v){
    const static std::pair<StrName, StrName> P("raylib", "Texture_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** RenderTexture ***************/
struct wrapped__RenderTexture{
    PY_CLASS(wrapped__RenderTexture, raylib, RenderTexture)

    RenderTexture _value;
    RenderTexture* _() { return &_value; }
    wrapped__RenderTexture() = default;
    wrapped__RenderTexture(const wrapped__RenderTexture& other) = default;

    wrapped__RenderTexture(const RenderTexture& other){
        memcpy(&_value, &other, sizeof(RenderTexture));
    }
    bool operator==(const wrapped__RenderTexture& other) const{
        return memcmp(&_value, &other._value, sizeof(RenderTexture)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"id", "texture", "depth"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 3) vm->TypeError(fmt("expected 3 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__RenderTexture)
        PY_FIELD(wrapped__RenderTexture, "id", _, id)
        PY_FIELD(wrapped__RenderTexture, "texture", _, texture)
        PY_FIELD(wrapped__RenderTexture, "depth", _, depth)
    }
};

PyObject* py_var(VM* vm, RenderTexture v){
    return VAR_T(wrapped__RenderTexture, v);
}
template<>
RenderTexture py_cast<RenderTexture>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__RenderTexture&>(vm, obj)._();
}
template<>
RenderTexture _py_cast<RenderTexture>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__RenderTexture&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const RenderTexture* v){
    const static std::pair<StrName, StrName> P("raylib", "RenderTexture_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** NPatchInfo ***************/
struct wrapped__NPatchInfo{
    PY_CLASS(wrapped__NPatchInfo, raylib, NPatchInfo)

    NPatchInfo _value;
    NPatchInfo* _() { return &_value; }
    wrapped__NPatchInfo() = default;
    wrapped__NPatchInfo(const wrapped__NPatchInfo& other) = default;

    wrapped__NPatchInfo(const NPatchInfo& other){
        memcpy(&_value, &other, sizeof(NPatchInfo));
    }
    bool operator==(const wrapped__NPatchInfo& other) const{
        return memcmp(&_value, &other._value, sizeof(NPatchInfo)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"source", "left", "top", "right", "bottom", "layout"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 6) vm->TypeError(fmt("expected 6 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__NPatchInfo)
        PY_FIELD(wrapped__NPatchInfo, "source", _, source)
        PY_FIELD(wrapped__NPatchInfo, "left", _, left)
        PY_FIELD(wrapped__NPatchInfo, "top", _, top)
        PY_FIELD(wrapped__NPatchInfo, "right", _, right)
        PY_FIELD(wrapped__NPatchInfo, "bottom", _, bottom)
        PY_FIELD(wrapped__NPatchInfo, "layout", _, layout)
    }
};

PyObject* py_var(VM* vm, NPatchInfo v){
    return VAR_T(wrapped__NPatchInfo, v);
}
template<>
NPatchInfo py_cast<NPatchInfo>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__NPatchInfo&>(vm, obj)._();
}
template<>
NPatchInfo _py_cast<NPatchInfo>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__NPatchInfo&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const NPatchInfo* v){
    const static std::pair<StrName, StrName> P("raylib", "NPatchInfo_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** GlyphInfo ***************/
struct wrapped__GlyphInfo{
    PY_CLASS(wrapped__GlyphInfo, raylib, GlyphInfo)

    GlyphInfo _value;
    GlyphInfo* _() { return &_value; }
    wrapped__GlyphInfo() = default;
    wrapped__GlyphInfo(const wrapped__GlyphInfo& other) = default;

    wrapped__GlyphInfo(const GlyphInfo& other){
        memcpy(&_value, &other, sizeof(GlyphInfo));
    }
    bool operator==(const wrapped__GlyphInfo& other) const{
        return memcmp(&_value, &other._value, sizeof(GlyphInfo)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"value", "offsetX", "offsetY", "advanceX", "image"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 5) vm->TypeError(fmt("expected 5 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__GlyphInfo)
        PY_FIELD(wrapped__GlyphInfo, "value", _, value)
        PY_FIELD(wrapped__GlyphInfo, "offsetX", _, offsetX)
        PY_FIELD(wrapped__GlyphInfo, "offsetY", _, offsetY)
        PY_FIELD(wrapped__GlyphInfo, "advanceX", _, advanceX)
        PY_FIELD(wrapped__GlyphInfo, "image", _, image)
    }
};

PyObject* py_var(VM* vm, GlyphInfo v){
    return VAR_T(wrapped__GlyphInfo, v);
}
template<>
GlyphInfo py_cast<GlyphInfo>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__GlyphInfo&>(vm, obj)._();
}
template<>
GlyphInfo _py_cast<GlyphInfo>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__GlyphInfo&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const GlyphInfo* v){
    const static std::pair<StrName, StrName> P("raylib", "GlyphInfo_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** Font ***************/
struct wrapped__Font{
    PY_CLASS(wrapped__Font, raylib, Font)

    Font _value;
    Font* _() { return &_value; }
    wrapped__Font() = default;
    wrapped__Font(const wrapped__Font& other) = default;

    wrapped__Font(const Font& other){
        memcpy(&_value, &other, sizeof(Font));
    }
    bool operator==(const wrapped__Font& other) const{
        return memcmp(&_value, &other._value, sizeof(Font)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"baseSize", "glyphCount", "glyphPadding", "texture", "recs", "glyphs"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 6) vm->TypeError(fmt("expected 6 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__Font)
        PY_FIELD(wrapped__Font, "baseSize", _, baseSize)
        PY_FIELD(wrapped__Font, "glyphCount", _, glyphCount)
        PY_FIELD(wrapped__Font, "glyphPadding", _, glyphPadding)
        PY_FIELD(wrapped__Font, "texture", _, texture)
        PY_FIELD(wrapped__Font, "recs", _, recs)
        PY_FIELD(wrapped__Font, "glyphs", _, glyphs)
    }
};

PyObject* py_var(VM* vm, Font v){
    return VAR_T(wrapped__Font, v);
}
template<>
Font py_cast<Font>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__Font&>(vm, obj)._();
}
template<>
Font _py_cast<Font>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__Font&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const Font* v){
    const static std::pair<StrName, StrName> P("raylib", "Font_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** Camera3D ***************/
struct wrapped__Camera3D{
    PY_CLASS(wrapped__Camera3D, raylib, Camera3D)

    Camera3D _value;
    Camera3D* _() { return &_value; }
    wrapped__Camera3D() = default;
    wrapped__Camera3D(const wrapped__Camera3D& other) = default;

    wrapped__Camera3D(const Camera3D& other){
        memcpy(&_value, &other, sizeof(Camera3D));
    }
    bool operator==(const wrapped__Camera3D& other) const{
        return memcmp(&_value, &other._value, sizeof(Camera3D)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"position", "target", "up", "fovy", "projection"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 5) vm->TypeError(fmt("expected 5 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__Camera3D)
        PY_FIELD(wrapped__Camera3D, "position", _, position)
        PY_FIELD(wrapped__Camera3D, "target", _, target)
        PY_FIELD(wrapped__Camera3D, "up", _, up)
        PY_FIELD(wrapped__Camera3D, "fovy", _, fovy)
        PY_FIELD(wrapped__Camera3D, "projection", _, projection)
    }
};

PyObject* py_var(VM* vm, Camera3D v){
    return VAR_T(wrapped__Camera3D, v);
}
template<>
Camera3D py_cast<Camera3D>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__Camera3D&>(vm, obj)._();
}
template<>
Camera3D _py_cast<Camera3D>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__Camera3D&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const Camera3D* v){
    const static std::pair<StrName, StrName> P("raylib", "Camera3D_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** Camera2D ***************/
struct wrapped__Camera2D{
    PY_CLASS(wrapped__Camera2D, raylib, Camera2D)

    Camera2D _value;
    Camera2D* _() { return &_value; }
    wrapped__Camera2D() = default;
    wrapped__Camera2D(const wrapped__Camera2D& other) = default;

    wrapped__Camera2D(const Camera2D& other){
        memcpy(&_value, &other, sizeof(Camera2D));
    }
    bool operator==(const wrapped__Camera2D& other) const{
        return memcmp(&_value, &other._value, sizeof(Camera2D)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"offset", "target", "rotation", "zoom"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 4) vm->TypeError(fmt("expected 4 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__Camera2D)
        PY_FIELD(wrapped__Camera2D, "offset", _, offset)
        PY_FIELD(wrapped__Camera2D, "target", _, target)
        PY_FIELD(wrapped__Camera2D, "rotation", _, rotation)
        PY_FIELD(wrapped__Camera2D, "zoom", _, zoom)
    }
};

PyObject* py_var(VM* vm, Camera2D v){
    return VAR_T(wrapped__Camera2D, v);
}
template<>
Camera2D py_cast<Camera2D>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__Camera2D&>(vm, obj)._();
}
template<>
Camera2D _py_cast<Camera2D>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__Camera2D&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const Camera2D* v){
    const static std::pair<StrName, StrName> P("raylib", "Camera2D_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** Mesh ***************/
struct wrapped__Mesh{
    PY_CLASS(wrapped__Mesh, raylib, Mesh)

    Mesh _value;
    Mesh* _() { return &_value; }
    wrapped__Mesh() = default;
    wrapped__Mesh(const wrapped__Mesh& other) = default;

    wrapped__Mesh(const Mesh& other){
        memcpy(&_value, &other, sizeof(Mesh));
    }
    bool operator==(const wrapped__Mesh& other) const{
        return memcmp(&_value, &other._value, sizeof(Mesh)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"vertexCount", "triangleCount", "vertices", "texcoords", "texcoords2", "normals", "tangents", "colors", "indices", "animVertices", "animNormals", "boneIds", "boneWeights", "vaoId", "vboId"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 15) vm->TypeError(fmt("expected 15 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__Mesh)
        PY_FIELD(wrapped__Mesh, "vertexCount", _, vertexCount)
        PY_FIELD(wrapped__Mesh, "triangleCount", _, triangleCount)
        PY_FIELD(wrapped__Mesh, "vertices", _, vertices)
        PY_FIELD(wrapped__Mesh, "texcoords", _, texcoords)
        PY_FIELD(wrapped__Mesh, "texcoords2", _, texcoords2)
        PY_FIELD(wrapped__Mesh, "normals", _, normals)
        PY_FIELD(wrapped__Mesh, "tangents", _, tangents)
        PY_FIELD(wrapped__Mesh, "colors", _, colors)
        PY_FIELD(wrapped__Mesh, "indices", _, indices)
        PY_FIELD(wrapped__Mesh, "animVertices", _, animVertices)
        PY_FIELD(wrapped__Mesh, "animNormals", _, animNormals)
        PY_FIELD(wrapped__Mesh, "boneIds", _, boneIds)
        PY_FIELD(wrapped__Mesh, "boneWeights", _, boneWeights)
        PY_FIELD(wrapped__Mesh, "vaoId", _, vaoId)
        PY_FIELD(wrapped__Mesh, "vboId", _, vboId)
    }
};

PyObject* py_var(VM* vm, Mesh v){
    return VAR_T(wrapped__Mesh, v);
}
template<>
Mesh py_cast<Mesh>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__Mesh&>(vm, obj)._();
}
template<>
Mesh _py_cast<Mesh>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__Mesh&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const Mesh* v){
    const static std::pair<StrName, StrName> P("raylib", "Mesh_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** Shader ***************/
struct wrapped__Shader{
    PY_CLASS(wrapped__Shader, raylib, Shader)

    Shader _value;
    Shader* _() { return &_value; }
    wrapped__Shader() = default;
    wrapped__Shader(const wrapped__Shader& other) = default;

    wrapped__Shader(const Shader& other){
        memcpy(&_value, &other, sizeof(Shader));
    }
    bool operator==(const wrapped__Shader& other) const{
        return memcmp(&_value, &other._value, sizeof(Shader)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"id", "locs"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 2) vm->TypeError(fmt("expected 2 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__Shader)
        PY_FIELD(wrapped__Shader, "id", _, id)
        PY_FIELD(wrapped__Shader, "locs", _, locs)
    }
};

PyObject* py_var(VM* vm, Shader v){
    return VAR_T(wrapped__Shader, v);
}
template<>
Shader py_cast<Shader>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__Shader&>(vm, obj)._();
}
template<>
Shader _py_cast<Shader>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__Shader&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const Shader* v){
    const static std::pair<StrName, StrName> P("raylib", "Shader_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** MaterialMap ***************/
struct wrapped__MaterialMap{
    PY_CLASS(wrapped__MaterialMap, raylib, MaterialMap)

    MaterialMap _value;
    MaterialMap* _() { return &_value; }
    wrapped__MaterialMap() = default;
    wrapped__MaterialMap(const wrapped__MaterialMap& other) = default;

    wrapped__MaterialMap(const MaterialMap& other){
        memcpy(&_value, &other, sizeof(MaterialMap));
    }
    bool operator==(const wrapped__MaterialMap& other) const{
        return memcmp(&_value, &other._value, sizeof(MaterialMap)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"texture", "color", "value"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 3) vm->TypeError(fmt("expected 3 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__MaterialMap)
        PY_FIELD(wrapped__MaterialMap, "texture", _, texture)
        PY_FIELD(wrapped__MaterialMap, "color", _, color)
        PY_FIELD(wrapped__MaterialMap, "value", _, value)
    }
};

PyObject* py_var(VM* vm, MaterialMap v){
    return VAR_T(wrapped__MaterialMap, v);
}
template<>
MaterialMap py_cast<MaterialMap>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__MaterialMap&>(vm, obj)._();
}
template<>
MaterialMap _py_cast<MaterialMap>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__MaterialMap&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const MaterialMap* v){
    const static std::pair<StrName, StrName> P("raylib", "MaterialMap_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** Material ***************/
struct wrapped__Material{
    PY_CLASS(wrapped__Material, raylib, Material)

    Material _value;
    Material* _() { return &_value; }
    wrapped__Material() = default;
    wrapped__Material(const wrapped__Material& other) = default;

    wrapped__Material(const Material& other){
        memcpy(&_value, &other, sizeof(Material));
    }
    bool operator==(const wrapped__Material& other) const{
        return memcmp(&_value, &other._value, sizeof(Material)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"shader", "maps", "params"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 3) vm->TypeError(fmt("expected 3 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__Material)
        PY_FIELD(wrapped__Material, "shader", _, shader)
        PY_FIELD(wrapped__Material, "maps", _, maps)
        PY_READONLY_FIELD(wrapped__Material, "params", _, params)
    }
};

PyObject* py_var(VM* vm, Material v){
    return VAR_T(wrapped__Material, v);
}
template<>
Material py_cast<Material>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__Material&>(vm, obj)._();
}
template<>
Material _py_cast<Material>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__Material&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const Material* v){
    const static std::pair<StrName, StrName> P("raylib", "Material_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** Transform ***************/
struct wrapped__Transform{
    PY_CLASS(wrapped__Transform, raylib, Transform)

    Transform _value;
    Transform* _() { return &_value; }
    wrapped__Transform() = default;
    wrapped__Transform(const wrapped__Transform& other) = default;

    wrapped__Transform(const Transform& other){
        memcpy(&_value, &other, sizeof(Transform));
    }
    bool operator==(const wrapped__Transform& other) const{
        return memcmp(&_value, &other._value, sizeof(Transform)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"translation", "rotation", "scale"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 3) vm->TypeError(fmt("expected 3 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__Transform)
        PY_FIELD(wrapped__Transform, "translation", _, translation)
        PY_FIELD(wrapped__Transform, "rotation", _, rotation)
        PY_FIELD(wrapped__Transform, "scale", _, scale)
    }
};

PyObject* py_var(VM* vm, Transform v){
    return VAR_T(wrapped__Transform, v);
}
template<>
Transform py_cast<Transform>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__Transform&>(vm, obj)._();
}
template<>
Transform _py_cast<Transform>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__Transform&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const Transform* v){
    const static std::pair<StrName, StrName> P("raylib", "Transform_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** BoneInfo ***************/
struct wrapped__BoneInfo{
    PY_CLASS(wrapped__BoneInfo, raylib, BoneInfo)

    BoneInfo _value;
    BoneInfo* _() { return &_value; }
    wrapped__BoneInfo() = default;
    wrapped__BoneInfo(const wrapped__BoneInfo& other) = default;

    wrapped__BoneInfo(const BoneInfo& other){
        memcpy(&_value, &other, sizeof(BoneInfo));
    }
    bool operator==(const wrapped__BoneInfo& other) const{
        return memcmp(&_value, &other._value, sizeof(BoneInfo)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"name", "parent"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 2) vm->TypeError(fmt("expected 2 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__BoneInfo)
        PY_READONLY_FIELD(wrapped__BoneInfo, "name", _, name)
        PY_FIELD(wrapped__BoneInfo, "parent", _, parent)
    }
};

PyObject* py_var(VM* vm, BoneInfo v){
    return VAR_T(wrapped__BoneInfo, v);
}
template<>
BoneInfo py_cast<BoneInfo>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__BoneInfo&>(vm, obj)._();
}
template<>
BoneInfo _py_cast<BoneInfo>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__BoneInfo&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const BoneInfo* v){
    const static std::pair<StrName, StrName> P("raylib", "BoneInfo_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** Model ***************/
struct wrapped__Model{
    PY_CLASS(wrapped__Model, raylib, Model)

    Model _value;
    Model* _() { return &_value; }
    wrapped__Model() = default;
    wrapped__Model(const wrapped__Model& other) = default;

    wrapped__Model(const Model& other){
        memcpy(&_value, &other, sizeof(Model));
    }
    bool operator==(const wrapped__Model& other) const{
        return memcmp(&_value, &other._value, sizeof(Model)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"transform", "meshCount", "materialCount", "meshes", "materials", "meshMaterial", "boneCount", "bones", "bindPose"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 9) vm->TypeError(fmt("expected 9 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__Model)
        PY_FIELD(wrapped__Model, "transform", _, transform)
        PY_FIELD(wrapped__Model, "meshCount", _, meshCount)
        PY_FIELD(wrapped__Model, "materialCount", _, materialCount)
        PY_FIELD(wrapped__Model, "meshes", _, meshes)
        PY_FIELD(wrapped__Model, "materials", _, materials)
        PY_FIELD(wrapped__Model, "meshMaterial", _, meshMaterial)
        PY_FIELD(wrapped__Model, "boneCount", _, boneCount)
        PY_FIELD(wrapped__Model, "bones", _, bones)
        PY_FIELD(wrapped__Model, "bindPose", _, bindPose)
    }
};

PyObject* py_var(VM* vm, Model v){
    return VAR_T(wrapped__Model, v);
}
template<>
Model py_cast<Model>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__Model&>(vm, obj)._();
}
template<>
Model _py_cast<Model>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__Model&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const Model* v){
    const static std::pair<StrName, StrName> P("raylib", "Model_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** ModelAnimation ***************/
struct wrapped__ModelAnimation{
    PY_CLASS(wrapped__ModelAnimation, raylib, ModelAnimation)

    ModelAnimation _value;
    ModelAnimation* _() { return &_value; }
    wrapped__ModelAnimation() = default;
    wrapped__ModelAnimation(const wrapped__ModelAnimation& other) = default;

    wrapped__ModelAnimation(const ModelAnimation& other){
        memcpy(&_value, &other, sizeof(ModelAnimation));
    }
    bool operator==(const wrapped__ModelAnimation& other) const{
        return memcmp(&_value, &other._value, sizeof(ModelAnimation)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"boneCount", "frameCount", "bones", "framePoses", "name"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 5) vm->TypeError(fmt("expected 5 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__ModelAnimation)
        PY_FIELD(wrapped__ModelAnimation, "boneCount", _, boneCount)
        PY_FIELD(wrapped__ModelAnimation, "frameCount", _, frameCount)
        PY_FIELD(wrapped__ModelAnimation, "bones", _, bones)
        PY_FIELD(wrapped__ModelAnimation, "framePoses", _, framePoses)
        PY_READONLY_FIELD(wrapped__ModelAnimation, "name", _, name)
    }
};

PyObject* py_var(VM* vm, ModelAnimation v){
    return VAR_T(wrapped__ModelAnimation, v);
}
template<>
ModelAnimation py_cast<ModelAnimation>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__ModelAnimation&>(vm, obj)._();
}
template<>
ModelAnimation _py_cast<ModelAnimation>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__ModelAnimation&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const ModelAnimation* v){
    const static std::pair<StrName, StrName> P("raylib", "ModelAnimation_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** Ray ***************/
struct wrapped__Ray{
    PY_CLASS(wrapped__Ray, raylib, Ray)

    Ray _value;
    Ray* _() { return &_value; }
    wrapped__Ray() = default;
    wrapped__Ray(const wrapped__Ray& other) = default;

    wrapped__Ray(const Ray& other){
        memcpy(&_value, &other, sizeof(Ray));
    }
    bool operator==(const wrapped__Ray& other) const{
        return memcmp(&_value, &other._value, sizeof(Ray)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"position", "direction"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 2) vm->TypeError(fmt("expected 2 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__Ray)
        PY_FIELD(wrapped__Ray, "position", _, position)
        PY_FIELD(wrapped__Ray, "direction", _, direction)
    }
};

PyObject* py_var(VM* vm, Ray v){
    return VAR_T(wrapped__Ray, v);
}
template<>
Ray py_cast<Ray>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__Ray&>(vm, obj)._();
}
template<>
Ray _py_cast<Ray>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__Ray&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const Ray* v){
    const static std::pair<StrName, StrName> P("raylib", "Ray_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** RayCollision ***************/
struct wrapped__RayCollision{
    PY_CLASS(wrapped__RayCollision, raylib, RayCollision)

    RayCollision _value;
    RayCollision* _() { return &_value; }
    wrapped__RayCollision() = default;
    wrapped__RayCollision(const wrapped__RayCollision& other) = default;

    wrapped__RayCollision(const RayCollision& other){
        memcpy(&_value, &other, sizeof(RayCollision));
    }
    bool operator==(const wrapped__RayCollision& other) const{
        return memcmp(&_value, &other._value, sizeof(RayCollision)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"hit", "distance", "point", "normal"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 4) vm->TypeError(fmt("expected 4 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__RayCollision)
        PY_FIELD(wrapped__RayCollision, "hit", _, hit)
        PY_FIELD(wrapped__RayCollision, "distance", _, distance)
        PY_FIELD(wrapped__RayCollision, "point", _, point)
        PY_FIELD(wrapped__RayCollision, "normal", _, normal)
    }
};

PyObject* py_var(VM* vm, RayCollision v){
    return VAR_T(wrapped__RayCollision, v);
}
template<>
RayCollision py_cast<RayCollision>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__RayCollision&>(vm, obj)._();
}
template<>
RayCollision _py_cast<RayCollision>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__RayCollision&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const RayCollision* v){
    const static std::pair<StrName, StrName> P("raylib", "RayCollision_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** BoundingBox ***************/
struct wrapped__BoundingBox{
    PY_CLASS(wrapped__BoundingBox, raylib, BoundingBox)

    BoundingBox _value;
    BoundingBox* _() { return &_value; }
    wrapped__BoundingBox() = default;
    wrapped__BoundingBox(const wrapped__BoundingBox& other) = default;

    wrapped__BoundingBox(const BoundingBox& other){
        memcpy(&_value, &other, sizeof(BoundingBox));
    }
    bool operator==(const wrapped__BoundingBox& other) const{
        return memcmp(&_value, &other._value, sizeof(BoundingBox)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"min", "max"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 2) vm->TypeError(fmt("expected 2 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__BoundingBox)
        PY_FIELD(wrapped__BoundingBox, "min", _, min)
        PY_FIELD(wrapped__BoundingBox, "max", _, max)
    }
};

PyObject* py_var(VM* vm, BoundingBox v){
    return VAR_T(wrapped__BoundingBox, v);
}
template<>
BoundingBox py_cast<BoundingBox>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__BoundingBox&>(vm, obj)._();
}
template<>
BoundingBox _py_cast<BoundingBox>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__BoundingBox&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const BoundingBox* v){
    const static std::pair<StrName, StrName> P("raylib", "BoundingBox_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** Wave ***************/
struct wrapped__Wave{
    PY_CLASS(wrapped__Wave, raylib, Wave)

    Wave _value;
    Wave* _() { return &_value; }
    wrapped__Wave() = default;
    wrapped__Wave(const wrapped__Wave& other) = default;

    wrapped__Wave(const Wave& other){
        memcpy(&_value, &other, sizeof(Wave));
    }
    bool operator==(const wrapped__Wave& other) const{
        return memcmp(&_value, &other._value, sizeof(Wave)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"frameCount", "sampleRate", "sampleSize", "channels", "data"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 5) vm->TypeError(fmt("expected 5 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__Wave)
        PY_FIELD(wrapped__Wave, "frameCount", _, frameCount)
        PY_FIELD(wrapped__Wave, "sampleRate", _, sampleRate)
        PY_FIELD(wrapped__Wave, "sampleSize", _, sampleSize)
        PY_FIELD(wrapped__Wave, "channels", _, channels)
        PY_FIELD(wrapped__Wave, "data", _, data)
    }
};

PyObject* py_var(VM* vm, Wave v){
    return VAR_T(wrapped__Wave, v);
}
template<>
Wave py_cast<Wave>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__Wave&>(vm, obj)._();
}
template<>
Wave _py_cast<Wave>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__Wave&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const Wave* v){
    const static std::pair<StrName, StrName> P("raylib", "Wave_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** AudioStream ***************/
struct wrapped__AudioStream{
    PY_CLASS(wrapped__AudioStream, raylib, AudioStream)

    AudioStream _value;
    AudioStream* _() { return &_value; }
    wrapped__AudioStream() = default;
    wrapped__AudioStream(const wrapped__AudioStream& other) = default;

    wrapped__AudioStream(const AudioStream& other){
        memcpy(&_value, &other, sizeof(AudioStream));
    }
    bool operator==(const wrapped__AudioStream& other) const{
        return memcmp(&_value, &other._value, sizeof(AudioStream)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"buffer", "processor", "sampleRate", "sampleSize", "channels"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 5) vm->TypeError(fmt("expected 5 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__AudioStream)
        PY_FIELD(wrapped__AudioStream, "buffer", _, buffer)
        PY_FIELD(wrapped__AudioStream, "processor", _, processor)
        PY_FIELD(wrapped__AudioStream, "sampleRate", _, sampleRate)
        PY_FIELD(wrapped__AudioStream, "sampleSize", _, sampleSize)
        PY_FIELD(wrapped__AudioStream, "channels", _, channels)
    }
};

PyObject* py_var(VM* vm, AudioStream v){
    return VAR_T(wrapped__AudioStream, v);
}
template<>
AudioStream py_cast<AudioStream>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__AudioStream&>(vm, obj)._();
}
template<>
AudioStream _py_cast<AudioStream>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__AudioStream&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const AudioStream* v){
    const static std::pair<StrName, StrName> P("raylib", "AudioStream_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** Sound ***************/
struct wrapped__Sound{
    PY_CLASS(wrapped__Sound, raylib, Sound)

    Sound _value;
    Sound* _() { return &_value; }
    wrapped__Sound() = default;
    wrapped__Sound(const wrapped__Sound& other) = default;

    wrapped__Sound(const Sound& other){
        memcpy(&_value, &other, sizeof(Sound));
    }
    bool operator==(const wrapped__Sound& other) const{
        return memcmp(&_value, &other._value, sizeof(Sound)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"stream", "frameCount"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 2) vm->TypeError(fmt("expected 2 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__Sound)
        PY_FIELD(wrapped__Sound, "stream", _, stream)
        PY_FIELD(wrapped__Sound, "frameCount", _, frameCount)
    }
};

PyObject* py_var(VM* vm, Sound v){
    return VAR_T(wrapped__Sound, v);
}
template<>
Sound py_cast<Sound>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__Sound&>(vm, obj)._();
}
template<>
Sound _py_cast<Sound>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__Sound&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const Sound* v){
    const static std::pair<StrName, StrName> P("raylib", "Sound_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** Music ***************/
struct wrapped__Music{
    PY_CLASS(wrapped__Music, raylib, Music)

    Music _value;
    Music* _() { return &_value; }
    wrapped__Music() = default;
    wrapped__Music(const wrapped__Music& other) = default;

    wrapped__Music(const Music& other){
        memcpy(&_value, &other, sizeof(Music));
    }
    bool operator==(const wrapped__Music& other) const{
        return memcmp(&_value, &other._value, sizeof(Music)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"stream", "frameCount", "looping", "ctxType", "ctxData"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 5) vm->TypeError(fmt("expected 5 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__Music)
        PY_FIELD(wrapped__Music, "stream", _, stream)
        PY_FIELD(wrapped__Music, "frameCount", _, frameCount)
        PY_FIELD(wrapped__Music, "looping", _, looping)
        PY_FIELD(wrapped__Music, "ctxType", _, ctxType)
        PY_FIELD(wrapped__Music, "ctxData", _, ctxData)
    }
};

PyObject* py_var(VM* vm, Music v){
    return VAR_T(wrapped__Music, v);
}
template<>
Music py_cast<Music>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__Music&>(vm, obj)._();
}
template<>
Music _py_cast<Music>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__Music&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const Music* v){
    const static std::pair<StrName, StrName> P("raylib", "Music_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** VrDeviceInfo ***************/
struct wrapped__VrDeviceInfo{
    PY_CLASS(wrapped__VrDeviceInfo, raylib, VrDeviceInfo)

    VrDeviceInfo _value;
    VrDeviceInfo* _() { return &_value; }
    wrapped__VrDeviceInfo() = default;
    wrapped__VrDeviceInfo(const wrapped__VrDeviceInfo& other) = default;

    wrapped__VrDeviceInfo(const VrDeviceInfo& other){
        memcpy(&_value, &other, sizeof(VrDeviceInfo));
    }
    bool operator==(const wrapped__VrDeviceInfo& other) const{
        return memcmp(&_value, &other._value, sizeof(VrDeviceInfo)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"hResolution", "vResolution", "hScreenSize", "vScreenSize", "vScreenCenter", "eyeToScreenDistance", "lensSeparationDistance", "interpupillaryDistance", "lensDistortionValues", "chromaAbCorrection"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 10) vm->TypeError(fmt("expected 10 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__VrDeviceInfo)
        PY_FIELD(wrapped__VrDeviceInfo, "hResolution", _, hResolution)
        PY_FIELD(wrapped__VrDeviceInfo, "vResolution", _, vResolution)
        PY_FIELD(wrapped__VrDeviceInfo, "hScreenSize", _, hScreenSize)
        PY_FIELD(wrapped__VrDeviceInfo, "vScreenSize", _, vScreenSize)
        PY_FIELD(wrapped__VrDeviceInfo, "vScreenCenter", _, vScreenCenter)
        PY_FIELD(wrapped__VrDeviceInfo, "eyeToScreenDistance", _, eyeToScreenDistance)
        PY_FIELD(wrapped__VrDeviceInfo, "lensSeparationDistance", _, lensSeparationDistance)
        PY_FIELD(wrapped__VrDeviceInfo, "interpupillaryDistance", _, interpupillaryDistance)
        PY_READONLY_FIELD(wrapped__VrDeviceInfo, "lensDistortionValues", _, lensDistortionValues)
        PY_READONLY_FIELD(wrapped__VrDeviceInfo, "chromaAbCorrection", _, chromaAbCorrection)
    }
};

PyObject* py_var(VM* vm, VrDeviceInfo v){
    return VAR_T(wrapped__VrDeviceInfo, v);
}
template<>
VrDeviceInfo py_cast<VrDeviceInfo>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__VrDeviceInfo&>(vm, obj)._();
}
template<>
VrDeviceInfo _py_cast<VrDeviceInfo>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__VrDeviceInfo&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const VrDeviceInfo* v){
    const static std::pair<StrName, StrName> P("raylib", "VrDeviceInfo_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** VrStereoConfig ***************/
struct wrapped__VrStereoConfig{
    PY_CLASS(wrapped__VrStereoConfig, raylib, VrStereoConfig)

    VrStereoConfig _value;
    VrStereoConfig* _() { return &_value; }
    wrapped__VrStereoConfig() = default;
    wrapped__VrStereoConfig(const wrapped__VrStereoConfig& other) = default;

    wrapped__VrStereoConfig(const VrStereoConfig& other){
        memcpy(&_value, &other, sizeof(VrStereoConfig));
    }
    bool operator==(const wrapped__VrStereoConfig& other) const{
        return memcmp(&_value, &other._value, sizeof(VrStereoConfig)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"projection", "viewOffset", "leftLensCenter", "rightLensCenter", "leftScreenCenter", "rightScreenCenter", "scale", "scaleIn"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 8) vm->TypeError(fmt("expected 8 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__VrStereoConfig)
        PY_READONLY_FIELD(wrapped__VrStereoConfig, "projection", _, projection)
        PY_READONLY_FIELD(wrapped__VrStereoConfig, "viewOffset", _, viewOffset)
        PY_READONLY_FIELD(wrapped__VrStereoConfig, "leftLensCenter", _, leftLensCenter)
        PY_READONLY_FIELD(wrapped__VrStereoConfig, "rightLensCenter", _, rightLensCenter)
        PY_READONLY_FIELD(wrapped__VrStereoConfig, "leftScreenCenter", _, leftScreenCenter)
        PY_READONLY_FIELD(wrapped__VrStereoConfig, "rightScreenCenter", _, rightScreenCenter)
        PY_READONLY_FIELD(wrapped__VrStereoConfig, "scale", _, scale)
        PY_READONLY_FIELD(wrapped__VrStereoConfig, "scaleIn", _, scaleIn)
    }
};

PyObject* py_var(VM* vm, VrStereoConfig v){
    return VAR_T(wrapped__VrStereoConfig, v);
}
template<>
VrStereoConfig py_cast<VrStereoConfig>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__VrStereoConfig&>(vm, obj)._();
}
template<>
VrStereoConfig _py_cast<VrStereoConfig>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__VrStereoConfig&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const VrStereoConfig* v){
    const static std::pair<StrName, StrName> P("raylib", "VrStereoConfig_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** FilePathList ***************/
struct wrapped__FilePathList{
    PY_CLASS(wrapped__FilePathList, raylib, FilePathList)

    FilePathList _value;
    FilePathList* _() { return &_value; }
    wrapped__FilePathList() = default;
    wrapped__FilePathList(const wrapped__FilePathList& other) = default;

    wrapped__FilePathList(const FilePathList& other){
        memcpy(&_value, &other, sizeof(FilePathList));
    }
    bool operator==(const wrapped__FilePathList& other) const{
        return memcmp(&_value, &other._value, sizeof(FilePathList)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"capacity", "count", "paths"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 3) vm->TypeError(fmt("expected 3 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__FilePathList)
        PY_FIELD(wrapped__FilePathList, "capacity", _, capacity)
        PY_FIELD(wrapped__FilePathList, "count", _, count)
        PY_FIELD(wrapped__FilePathList, "paths", _, paths)
    }
};

PyObject* py_var(VM* vm, FilePathList v){
    return VAR_T(wrapped__FilePathList, v);
}
template<>
FilePathList py_cast<FilePathList>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__FilePathList&>(vm, obj)._();
}
template<>
FilePathList _py_cast<FilePathList>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__FilePathList&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const FilePathList* v){
    const static std::pair<StrName, StrName> P("raylib", "FilePathList_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** AutomationEvent ***************/
struct wrapped__AutomationEvent{
    PY_CLASS(wrapped__AutomationEvent, raylib, AutomationEvent)

    AutomationEvent _value;
    AutomationEvent* _() { return &_value; }
    wrapped__AutomationEvent() = default;
    wrapped__AutomationEvent(const wrapped__AutomationEvent& other) = default;

    wrapped__AutomationEvent(const AutomationEvent& other){
        memcpy(&_value, &other, sizeof(AutomationEvent));
    }
    bool operator==(const wrapped__AutomationEvent& other) const{
        return memcmp(&_value, &other._value, sizeof(AutomationEvent)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"frame", "type", "params"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 3) vm->TypeError(fmt("expected 3 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__AutomationEvent)
        PY_FIELD(wrapped__AutomationEvent, "frame", _, frame)
        PY_FIELD(wrapped__AutomationEvent, "type", _, type)
        PY_READONLY_FIELD(wrapped__AutomationEvent, "params", _, params)
    }
};

PyObject* py_var(VM* vm, AutomationEvent v){
    return VAR_T(wrapped__AutomationEvent, v);
}
template<>
AutomationEvent py_cast<AutomationEvent>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__AutomationEvent&>(vm, obj)._();
}
template<>
AutomationEvent _py_cast<AutomationEvent>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__AutomationEvent&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const AutomationEvent* v){
    const static std::pair<StrName, StrName> P("raylib", "AutomationEvent_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
/*************** AutomationEventList ***************/
struct wrapped__AutomationEventList{
    PY_CLASS(wrapped__AutomationEventList, raylib, AutomationEventList)

    AutomationEventList _value;
    AutomationEventList* _() { return &_value; }
    wrapped__AutomationEventList() = default;
    wrapped__AutomationEventList(const wrapped__AutomationEventList& other) = default;

    wrapped__AutomationEventList(const AutomationEventList& other){
        memcpy(&_value, &other, sizeof(AutomationEventList));
    }
    bool operator==(const wrapped__AutomationEventList& other) const{
        return memcmp(&_value, &other._value, sizeof(AutomationEventList)) == 0;
    }

    static void _register(VM* vm, PyObject* mod, PyObject* type){
        vm->bind_method<-1>(type, "__init__", [](VM* vm, ArgsView args){
            static const StrName _fields_[] = {"capacity", "count", "events"};
            if(args.size()==1) return vm->None;
            if(args.size()-1 != 3) vm->TypeError(fmt("expected 3 arguments, got ", args.size()-1));
            for(int i=1; i<args.size(); i++){
                vm->setattr(args[0], _fields_[i-1], args[i]);
            }
            return vm->None;
        });
        PY_STRUCT_LIKE(wrapped__AutomationEventList)
        PY_FIELD(wrapped__AutomationEventList, "capacity", _, capacity)
        PY_FIELD(wrapped__AutomationEventList, "count", _, count)
        PY_FIELD(wrapped__AutomationEventList, "events", _, events)
    }
};

PyObject* py_var(VM* vm, AutomationEventList v){
    return VAR_T(wrapped__AutomationEventList, v);
}
template<>
AutomationEventList py_cast<AutomationEventList>(VM* vm, PyObject* obj){
    return *py_cast<wrapped__AutomationEventList&>(vm, obj)._();
}
template<>
AutomationEventList _py_cast<AutomationEventList>(VM* vm, PyObject* obj){
    return *_py_cast<wrapped__AutomationEventList&>(vm, obj)._();
}
PyObject* py_var(VM* vm, const AutomationEventList* v){
    const static std::pair<StrName, StrName> P("raylib", "AutomationEventList_p");
    PyObject* type = vm->_modules[P.first]->attr(P.second);
    return vm->heap.gcnew<VoidP>(PK_OBJ_GET(Type, type), v);
}
////////////////////////////////////////
void add_module_raylib(VM* vm){
    PyObject* mod = vm->new_module("raylib");

    // defines
    mod->attr().set("RAYLIB_VERSION_MAJOR", py_var(vm, 5));
    mod->attr().set("RAYLIB_VERSION_MINOR", py_var(vm, 1));
    mod->attr().set("RAYLIB_VERSION_PATCH", py_var(vm, 0));
    mod->attr().set("RAYLIB_VERSION", py_var(vm, "5.1-dev"));
    mod->attr().set("PI", py_var(vm, 3.141592653589793));
    // ConfigFlags
    _bind_enums(vm, mod, {{"FLAG_VSYNC_HINT", 64}, {"FLAG_FULLSCREEN_MODE", 2}, {"FLAG_WINDOW_RESIZABLE", 4}, {"FLAG_WINDOW_UNDECORATED", 8}, {"FLAG_WINDOW_HIDDEN", 128}, {"FLAG_WINDOW_MINIMIZED", 512}, {"FLAG_WINDOW_MAXIMIZED", 1024}, {"FLAG_WINDOW_UNFOCUSED", 2048}, {"FLAG_WINDOW_TOPMOST", 4096}, {"FLAG_WINDOW_ALWAYS_RUN", 256}, {"FLAG_WINDOW_TRANSPARENT", 16}, {"FLAG_WINDOW_HIGHDPI", 8192}, {"FLAG_WINDOW_MOUSE_PASSTHROUGH", 16384}, {"FLAG_BORDERLESS_WINDOWED_MODE", 32768}, {"FLAG_MSAA_4X_HINT", 32}, {"FLAG_INTERLACED_HINT", 65536}});
    // TraceLogLevel
    _bind_enums(vm, mod, {{"LOG_ALL", 0}, {"LOG_TRACE", 1}, {"LOG_DEBUG", 2}, {"LOG_INFO", 3}, {"LOG_WARNING", 4}, {"LOG_ERROR", 5}, {"LOG_FATAL", 6}, {"LOG_NONE", 7}});
    // KeyboardKey
    _bind_enums(vm, mod, {{"KEY_NULL", 0}, {"KEY_APOSTROPHE", 39}, {"KEY_COMMA", 44}, {"KEY_MINUS", 45}, {"KEY_PERIOD", 46}, {"KEY_SLASH", 47}, {"KEY_ZERO", 48}, {"KEY_ONE", 49}, {"KEY_TWO", 50}, {"KEY_THREE", 51}, {"KEY_FOUR", 52}, {"KEY_FIVE", 53}, {"KEY_SIX", 54}, {"KEY_SEVEN", 55}, {"KEY_EIGHT", 56}, {"KEY_NINE", 57}, {"KEY_SEMICOLON", 59}, {"KEY_EQUAL", 61}, {"KEY_A", 65}, {"KEY_B", 66}, {"KEY_C", 67}, {"KEY_D", 68}, {"KEY_E", 69}, {"KEY_F", 70}, {"KEY_G", 71}, {"KEY_H", 72}, {"KEY_I", 73}, {"KEY_J", 74}, {"KEY_K", 75}, {"KEY_L", 76}, {"KEY_M", 77}, {"KEY_N", 78}, {"KEY_O", 79}, {"KEY_P", 80}, {"KEY_Q", 81}, {"KEY_R", 82}, {"KEY_S", 83}, {"KEY_T", 84}, {"KEY_U", 85}, {"KEY_V", 86}, {"KEY_W", 87}, {"KEY_X", 88}, {"KEY_Y", 89}, {"KEY_Z", 90}, {"KEY_LEFT_BRACKET", 91}, {"KEY_BACKSLASH", 92}, {"KEY_RIGHT_BRACKET", 93}, {"KEY_GRAVE", 96}, {"KEY_SPACE", 32}, {"KEY_ESCAPE", 256}, {"KEY_ENTER", 257}, {"KEY_TAB", 258}, {"KEY_BACKSPACE", 259}, {"KEY_INSERT", 260}, {"KEY_DELETE", 261}, {"KEY_RIGHT", 262}, {"KEY_LEFT", 263}, {"KEY_DOWN", 264}, {"KEY_UP", 265}, {"KEY_PAGE_UP", 266}, {"KEY_PAGE_DOWN", 267}, {"KEY_HOME", 268}, {"KEY_END", 269}, {"KEY_CAPS_LOCK", 280}, {"KEY_SCROLL_LOCK", 281}, {"KEY_NUM_LOCK", 282}, {"KEY_PRINT_SCREEN", 283}, {"KEY_PAUSE", 284}, {"KEY_F1", 290}, {"KEY_F2", 291}, {"KEY_F3", 292}, {"KEY_F4", 293}, {"KEY_F5", 294}, {"KEY_F6", 295}, {"KEY_F7", 296}, {"KEY_F8", 297}, {"KEY_F9", 298}, {"KEY_F10", 299}, {"KEY_F11", 300}, {"KEY_F12", 301}, {"KEY_LEFT_SHIFT", 340}, {"KEY_LEFT_CONTROL", 341}, {"KEY_LEFT_ALT", 342}, {"KEY_LEFT_SUPER", 343}, {"KEY_RIGHT_SHIFT", 344}, {"KEY_RIGHT_CONTROL", 345}, {"KEY_RIGHT_ALT", 346}, {"KEY_RIGHT_SUPER", 347}, {"KEY_KB_MENU", 348}, {"KEY_KP_0", 320}, {"KEY_KP_1", 321}, {"KEY_KP_2", 322}, {"KEY_KP_3", 323}, {"KEY_KP_4", 324}, {"KEY_KP_5", 325}, {"KEY_KP_6", 326}, {"KEY_KP_7", 327}, {"KEY_KP_8", 328}, {"KEY_KP_9", 329}, {"KEY_KP_DECIMAL", 330}, {"KEY_KP_DIVIDE", 331}, {"KEY_KP_MULTIPLY", 332}, {"KEY_KP_SUBTRACT", 333}, {"KEY_KP_ADD", 334}, {"KEY_KP_ENTER", 335}, {"KEY_KP_EQUAL", 336}, {"KEY_BACK", 4}, {"KEY_MENU", 82}, {"KEY_VOLUME_UP", 24}, {"KEY_VOLUME_DOWN", 25}});
    // MouseButton
    _bind_enums(vm, mod, {{"MOUSE_BUTTON_LEFT", 0}, {"MOUSE_BUTTON_RIGHT", 1}, {"MOUSE_BUTTON_MIDDLE", 2}, {"MOUSE_BUTTON_SIDE", 3}, {"MOUSE_BUTTON_EXTRA", 4}, {"MOUSE_BUTTON_FORWARD", 5}, {"MOUSE_BUTTON_BACK", 6}});
    // MouseCursor
    _bind_enums(vm, mod, {{"MOUSE_CURSOR_DEFAULT", 0}, {"MOUSE_CURSOR_ARROW", 1}, {"MOUSE_CURSOR_IBEAM", 2}, {"MOUSE_CURSOR_CROSSHAIR", 3}, {"MOUSE_CURSOR_POINTING_HAND", 4}, {"MOUSE_CURSOR_RESIZE_EW", 5}, {"MOUSE_CURSOR_RESIZE_NS", 6}, {"MOUSE_CURSOR_RESIZE_NWSE", 7}, {"MOUSE_CURSOR_RESIZE_NESW", 8}, {"MOUSE_CURSOR_RESIZE_ALL", 9}, {"MOUSE_CURSOR_NOT_ALLOWED", 10}});
    // GamepadButton
    _bind_enums(vm, mod, {{"GAMEPAD_BUTTON_UNKNOWN", 0}, {"GAMEPAD_BUTTON_LEFT_FACE_UP", 1}, {"GAMEPAD_BUTTON_LEFT_FACE_RIGHT", 2}, {"GAMEPAD_BUTTON_LEFT_FACE_DOWN", 3}, {"GAMEPAD_BUTTON_LEFT_FACE_LEFT", 4}, {"GAMEPAD_BUTTON_RIGHT_FACE_UP", 5}, {"GAMEPAD_BUTTON_RIGHT_FACE_RIGHT", 6}, {"GAMEPAD_BUTTON_RIGHT_FACE_DOWN", 7}, {"GAMEPAD_BUTTON_RIGHT_FACE_LEFT", 8}, {"GAMEPAD_BUTTON_LEFT_TRIGGER_1", 9}, {"GAMEPAD_BUTTON_LEFT_TRIGGER_2", 10}, {"GAMEPAD_BUTTON_RIGHT_TRIGGER_1", 11}, {"GAMEPAD_BUTTON_RIGHT_TRIGGER_2", 12}, {"GAMEPAD_BUTTON_MIDDLE_LEFT", 13}, {"GAMEPAD_BUTTON_MIDDLE", 14}, {"GAMEPAD_BUTTON_MIDDLE_RIGHT", 15}, {"GAMEPAD_BUTTON_LEFT_THUMB", 16}, {"GAMEPAD_BUTTON_RIGHT_THUMB", 17}});
    // GamepadAxis
    _bind_enums(vm, mod, {{"GAMEPAD_AXIS_LEFT_X", 0}, {"GAMEPAD_AXIS_LEFT_Y", 1}, {"GAMEPAD_AXIS_RIGHT_X", 2}, {"GAMEPAD_AXIS_RIGHT_Y", 3}, {"GAMEPAD_AXIS_LEFT_TRIGGER", 4}, {"GAMEPAD_AXIS_RIGHT_TRIGGER", 5}});
    // MaterialMapIndex
    _bind_enums(vm, mod, {{"MATERIAL_MAP_ALBEDO", 0}, {"MATERIAL_MAP_METALNESS", 1}, {"MATERIAL_MAP_NORMAL", 2}, {"MATERIAL_MAP_ROUGHNESS", 3}, {"MATERIAL_MAP_OCCLUSION", 4}, {"MATERIAL_MAP_EMISSION", 5}, {"MATERIAL_MAP_HEIGHT", 6}, {"MATERIAL_MAP_CUBEMAP", 7}, {"MATERIAL_MAP_IRRADIANCE", 8}, {"MATERIAL_MAP_PREFILTER", 9}, {"MATERIAL_MAP_BRDF", 10}});
    // ShaderLocationIndex
    _bind_enums(vm, mod, {{"SHADER_LOC_VERTEX_POSITION", 0}, {"SHADER_LOC_VERTEX_TEXCOORD01", 1}, {"SHADER_LOC_VERTEX_TEXCOORD02", 2}, {"SHADER_LOC_VERTEX_NORMAL", 3}, {"SHADER_LOC_VERTEX_TANGENT", 4}, {"SHADER_LOC_VERTEX_COLOR", 5}, {"SHADER_LOC_MATRIX_MVP", 6}, {"SHADER_LOC_MATRIX_VIEW", 7}, {"SHADER_LOC_MATRIX_PROJECTION", 8}, {"SHADER_LOC_MATRIX_MODEL", 9}, {"SHADER_LOC_MATRIX_NORMAL", 10}, {"SHADER_LOC_VECTOR_VIEW", 11}, {"SHADER_LOC_COLOR_DIFFUSE", 12}, {"SHADER_LOC_COLOR_SPECULAR", 13}, {"SHADER_LOC_COLOR_AMBIENT", 14}, {"SHADER_LOC_MAP_ALBEDO", 15}, {"SHADER_LOC_MAP_METALNESS", 16}, {"SHADER_LOC_MAP_NORMAL", 17}, {"SHADER_LOC_MAP_ROUGHNESS", 18}, {"SHADER_LOC_MAP_OCCLUSION", 19}, {"SHADER_LOC_MAP_EMISSION", 20}, {"SHADER_LOC_MAP_HEIGHT", 21}, {"SHADER_LOC_MAP_CUBEMAP", 22}, {"SHADER_LOC_MAP_IRRADIANCE", 23}, {"SHADER_LOC_MAP_PREFILTER", 24}, {"SHADER_LOC_MAP_BRDF", 25}});
    // ShaderUniformDataType
    _bind_enums(vm, mod, {{"SHADER_UNIFORM_FLOAT", 0}, {"SHADER_UNIFORM_VEC2", 1}, {"SHADER_UNIFORM_VEC3", 2}, {"SHADER_UNIFORM_VEC4", 3}, {"SHADER_UNIFORM_INT", 4}, {"SHADER_UNIFORM_IVEC2", 5}, {"SHADER_UNIFORM_IVEC3", 6}, {"SHADER_UNIFORM_IVEC4", 7}, {"SHADER_UNIFORM_SAMPLER2D", 8}});
    // ShaderAttributeDataType
    _bind_enums(vm, mod, {{"SHADER_ATTRIB_FLOAT", 0}, {"SHADER_ATTRIB_VEC2", 1}, {"SHADER_ATTRIB_VEC3", 2}, {"SHADER_ATTRIB_VEC4", 3}});
    // PixelFormat
    _bind_enums(vm, mod, {{"PIXELFORMAT_UNCOMPRESSED_GRAYSCALE", 1}, {"PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA", 2}, {"PIXELFORMAT_UNCOMPRESSED_R5G6B5", 3}, {"PIXELFORMAT_UNCOMPRESSED_R8G8B8", 4}, {"PIXELFORMAT_UNCOMPRESSED_R5G5B5A1", 5}, {"PIXELFORMAT_UNCOMPRESSED_R4G4B4A4", 6}, {"PIXELFORMAT_UNCOMPRESSED_R8G8B8A8", 7}, {"PIXELFORMAT_UNCOMPRESSED_R32", 8}, {"PIXELFORMAT_UNCOMPRESSED_R32G32B32", 9}, {"PIXELFORMAT_UNCOMPRESSED_R32G32B32A32", 10}, {"PIXELFORMAT_UNCOMPRESSED_R16", 11}, {"PIXELFORMAT_UNCOMPRESSED_R16G16B16", 12}, {"PIXELFORMAT_UNCOMPRESSED_R16G16B16A16", 13}, {"PIXELFORMAT_COMPRESSED_DXT1_RGB", 14}, {"PIXELFORMAT_COMPRESSED_DXT1_RGBA", 15}, {"PIXELFORMAT_COMPRESSED_DXT3_RGBA", 16}, {"PIXELFORMAT_COMPRESSED_DXT5_RGBA", 17}, {"PIXELFORMAT_COMPRESSED_ETC1_RGB", 18}, {"PIXELFORMAT_COMPRESSED_ETC2_RGB", 19}, {"PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA", 20}, {"PIXELFORMAT_COMPRESSED_PVRT_RGB", 21}, {"PIXELFORMAT_COMPRESSED_PVRT_RGBA", 22}, {"PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA", 23}, {"PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA", 24}});
    // TextureFilter
    _bind_enums(vm, mod, {{"TEXTURE_FILTER_POINT", 0}, {"TEXTURE_FILTER_BILINEAR", 1}, {"TEXTURE_FILTER_TRILINEAR", 2}, {"TEXTURE_FILTER_ANISOTROPIC_4X", 3}, {"TEXTURE_FILTER_ANISOTROPIC_8X", 4}, {"TEXTURE_FILTER_ANISOTROPIC_16X", 5}});
    // TextureWrap
    _bind_enums(vm, mod, {{"TEXTURE_WRAP_REPEAT", 0}, {"TEXTURE_WRAP_CLAMP", 1}, {"TEXTURE_WRAP_MIRROR_REPEAT", 2}, {"TEXTURE_WRAP_MIRROR_CLAMP", 3}});
    // CubemapLayout
    _bind_enums(vm, mod, {{"CUBEMAP_LAYOUT_AUTO_DETECT", 0}, {"CUBEMAP_LAYOUT_LINE_VERTICAL", 1}, {"CUBEMAP_LAYOUT_LINE_HORIZONTAL", 2}, {"CUBEMAP_LAYOUT_CROSS_THREE_BY_FOUR", 3}, {"CUBEMAP_LAYOUT_CROSS_FOUR_BY_THREE", 4}, {"CUBEMAP_LAYOUT_PANORAMA", 5}});
    // FontType
    _bind_enums(vm, mod, {{"FONT_DEFAULT", 0}, {"FONT_BITMAP", 1}, {"FONT_SDF", 2}});
    // BlendMode
    _bind_enums(vm, mod, {{"BLEND_ALPHA", 0}, {"BLEND_ADDITIVE", 1}, {"BLEND_MULTIPLIED", 2}, {"BLEND_ADD_COLORS", 3}, {"BLEND_SUBTRACT_COLORS", 4}, {"BLEND_ALPHA_PREMULTIPLY", 5}, {"BLEND_CUSTOM", 6}, {"BLEND_CUSTOM_SEPARATE", 7}});
    // Gesture
    _bind_enums(vm, mod, {{"GESTURE_NONE", 0}, {"GESTURE_TAP", 1}, {"GESTURE_DOUBLETAP", 2}, {"GESTURE_HOLD", 4}, {"GESTURE_DRAG", 8}, {"GESTURE_SWIPE_RIGHT", 16}, {"GESTURE_SWIPE_LEFT", 32}, {"GESTURE_SWIPE_UP", 64}, {"GESTURE_SWIPE_DOWN", 128}, {"GESTURE_PINCH_IN", 256}, {"GESTURE_PINCH_OUT", 512}});
    // CameraMode
    _bind_enums(vm, mod, {{"CAMERA_CUSTOM", 0}, {"CAMERA_FREE", 1}, {"CAMERA_ORBITAL", 2}, {"CAMERA_FIRST_PERSON", 3}, {"CAMERA_THIRD_PERSON", 4}});
    // CameraProjection
    _bind_enums(vm, mod, {{"CAMERA_PERSPECTIVE", 0}, {"CAMERA_ORTHOGRAPHIC", 1}});
    // NPatchLayout
    _bind_enums(vm, mod, {{"NPATCH_NINE_PATCH", 0}, {"NPATCH_THREE_PATCH_VERTICAL", 1}, {"NPATCH_THREE_PATCH_HORIZONTAL", 2}});

    wrapped__Matrix::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "Matrix_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(Matrix)
        PY_FIELD_P(Matrix, "m0", m0)
        PY_FIELD_P(Matrix, "m4", m4)
        PY_FIELD_P(Matrix, "m8", m8)
        PY_FIELD_P(Matrix, "m12", m12)
        PY_FIELD_P(Matrix, "m1", m1)
        PY_FIELD_P(Matrix, "m5", m5)
        PY_FIELD_P(Matrix, "m9", m9)
        PY_FIELD_P(Matrix, "m13", m13)
        PY_FIELD_P(Matrix, "m2", m2)
        PY_FIELD_P(Matrix, "m6", m6)
        PY_FIELD_P(Matrix, "m10", m10)
        PY_FIELD_P(Matrix, "m14", m14)
        PY_FIELD_P(Matrix, "m3", m3)
        PY_FIELD_P(Matrix, "m7", m7)
        PY_FIELD_P(Matrix, "m11", m11)
        PY_FIELD_P(Matrix, "m15", m15)
    }
    wrapped__Color::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "Color_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(Color)
        PY_FIELD_P(Color, "r", r)
        PY_FIELD_P(Color, "g", g)
        PY_FIELD_P(Color, "b", b)
        PY_FIELD_P(Color, "a", a)
    }
    wrapped__Rectangle::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "Rectangle_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(Rectangle)
        PY_FIELD_P(Rectangle, "x", x)
        PY_FIELD_P(Rectangle, "y", y)
        PY_FIELD_P(Rectangle, "width", width)
        PY_FIELD_P(Rectangle, "height", height)
    }
    wrapped__Image::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "Image_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(Image)
        PY_FIELD_P(Image, "data", data)
        PY_FIELD_P(Image, "width", width)
        PY_FIELD_P(Image, "height", height)
        PY_FIELD_P(Image, "mipmaps", mipmaps)
        PY_FIELD_P(Image, "format", format)
    }
    wrapped__Texture::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "Texture_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(Texture)
        PY_FIELD_P(Texture, "id", id)
        PY_FIELD_P(Texture, "width", width)
        PY_FIELD_P(Texture, "height", height)
        PY_FIELD_P(Texture, "mipmaps", mipmaps)
        PY_FIELD_P(Texture, "format", format)
    }
    wrapped__RenderTexture::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "RenderTexture_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(RenderTexture)
        PY_FIELD_P(RenderTexture, "id", id)
        PY_FIELD_P(RenderTexture, "texture", texture)
        PY_FIELD_P(RenderTexture, "depth", depth)
    }
    wrapped__NPatchInfo::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "NPatchInfo_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(NPatchInfo)
        PY_FIELD_P(NPatchInfo, "source", source)
        PY_FIELD_P(NPatchInfo, "left", left)
        PY_FIELD_P(NPatchInfo, "top", top)
        PY_FIELD_P(NPatchInfo, "right", right)
        PY_FIELD_P(NPatchInfo, "bottom", bottom)
        PY_FIELD_P(NPatchInfo, "layout", layout)
    }
    wrapped__GlyphInfo::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "GlyphInfo_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(GlyphInfo)
        PY_FIELD_P(GlyphInfo, "value", value)
        PY_FIELD_P(GlyphInfo, "offsetX", offsetX)
        PY_FIELD_P(GlyphInfo, "offsetY", offsetY)
        PY_FIELD_P(GlyphInfo, "advanceX", advanceX)
        PY_FIELD_P(GlyphInfo, "image", image)
    }
    wrapped__Font::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "Font_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(Font)
        PY_FIELD_P(Font, "baseSize", baseSize)
        PY_FIELD_P(Font, "glyphCount", glyphCount)
        PY_FIELD_P(Font, "glyphPadding", glyphPadding)
        PY_FIELD_P(Font, "texture", texture)
        PY_FIELD_P(Font, "recs", recs)
        PY_FIELD_P(Font, "glyphs", glyphs)
    }
    wrapped__Camera3D::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "Camera3D_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(Camera3D)
        PY_FIELD_P(Camera3D, "position", position)
        PY_FIELD_P(Camera3D, "target", target)
        PY_FIELD_P(Camera3D, "up", up)
        PY_FIELD_P(Camera3D, "fovy", fovy)
        PY_FIELD_P(Camera3D, "projection", projection)
    }
    wrapped__Camera2D::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "Camera2D_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(Camera2D)
        PY_FIELD_P(Camera2D, "offset", offset)
        PY_FIELD_P(Camera2D, "target", target)
        PY_FIELD_P(Camera2D, "rotation", rotation)
        PY_FIELD_P(Camera2D, "zoom", zoom)
    }
    wrapped__Mesh::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "Mesh_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(Mesh)
        PY_FIELD_P(Mesh, "vertexCount", vertexCount)
        PY_FIELD_P(Mesh, "triangleCount", triangleCount)
        PY_FIELD_P(Mesh, "vertices", vertices)
        PY_FIELD_P(Mesh, "texcoords", texcoords)
        PY_FIELD_P(Mesh, "texcoords2", texcoords2)
        PY_FIELD_P(Mesh, "normals", normals)
        PY_FIELD_P(Mesh, "tangents", tangents)
        PY_FIELD_P(Mesh, "colors", colors)
        PY_FIELD_P(Mesh, "indices", indices)
        PY_FIELD_P(Mesh, "animVertices", animVertices)
        PY_FIELD_P(Mesh, "animNormals", animNormals)
        PY_FIELD_P(Mesh, "boneIds", boneIds)
        PY_FIELD_P(Mesh, "boneWeights", boneWeights)
        PY_FIELD_P(Mesh, "vaoId", vaoId)
        PY_FIELD_P(Mesh, "vboId", vboId)
    }
    wrapped__Shader::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "Shader_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(Shader)
        PY_FIELD_P(Shader, "id", id)
        PY_FIELD_P(Shader, "locs", locs)
    }
    wrapped__MaterialMap::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "MaterialMap_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(MaterialMap)
        PY_FIELD_P(MaterialMap, "texture", texture)
        PY_FIELD_P(MaterialMap, "color", color)
        PY_FIELD_P(MaterialMap, "value", value)
    }
    wrapped__Material::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "Material_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(Material)
        PY_FIELD_P(Material, "shader", shader)
        PY_FIELD_P(Material, "maps", maps)
        PY_READONLY_FIELD_P(Material, "params", params)
    }
    wrapped__Transform::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "Transform_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(Transform)
        PY_FIELD_P(Transform, "translation", translation)
        PY_FIELD_P(Transform, "rotation", rotation)
        PY_FIELD_P(Transform, "scale", scale)
    }
    wrapped__BoneInfo::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "BoneInfo_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(BoneInfo)
        PY_READONLY_FIELD_P(BoneInfo, "name", name)
        PY_FIELD_P(BoneInfo, "parent", parent)
    }
    wrapped__Model::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "Model_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(Model)
        PY_FIELD_P(Model, "transform", transform)
        PY_FIELD_P(Model, "meshCount", meshCount)
        PY_FIELD_P(Model, "materialCount", materialCount)
        PY_FIELD_P(Model, "meshes", meshes)
        PY_FIELD_P(Model, "materials", materials)
        PY_FIELD_P(Model, "meshMaterial", meshMaterial)
        PY_FIELD_P(Model, "boneCount", boneCount)
        PY_FIELD_P(Model, "bones", bones)
        PY_FIELD_P(Model, "bindPose", bindPose)
    }
    wrapped__ModelAnimation::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "ModelAnimation_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(ModelAnimation)
        PY_FIELD_P(ModelAnimation, "boneCount", boneCount)
        PY_FIELD_P(ModelAnimation, "frameCount", frameCount)
        PY_FIELD_P(ModelAnimation, "bones", bones)
        PY_FIELD_P(ModelAnimation, "framePoses", framePoses)
        PY_READONLY_FIELD_P(ModelAnimation, "name", name)
    }
    wrapped__Ray::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "Ray_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(Ray)
        PY_FIELD_P(Ray, "position", position)
        PY_FIELD_P(Ray, "direction", direction)
    }
    wrapped__RayCollision::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "RayCollision_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(RayCollision)
        PY_FIELD_P(RayCollision, "hit", hit)
        PY_FIELD_P(RayCollision, "distance", distance)
        PY_FIELD_P(RayCollision, "point", point)
        PY_FIELD_P(RayCollision, "normal", normal)
    }
    wrapped__BoundingBox::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "BoundingBox_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(BoundingBox)
        PY_FIELD_P(BoundingBox, "min", min)
        PY_FIELD_P(BoundingBox, "max", max)
    }
    wrapped__Wave::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "Wave_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(Wave)
        PY_FIELD_P(Wave, "frameCount", frameCount)
        PY_FIELD_P(Wave, "sampleRate", sampleRate)
        PY_FIELD_P(Wave, "sampleSize", sampleSize)
        PY_FIELD_P(Wave, "channels", channels)
        PY_FIELD_P(Wave, "data", data)
    }
    wrapped__AudioStream::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "AudioStream_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(AudioStream)
        PY_FIELD_P(AudioStream, "buffer", buffer)
        PY_FIELD_P(AudioStream, "processor", processor)
        PY_FIELD_P(AudioStream, "sampleRate", sampleRate)
        PY_FIELD_P(AudioStream, "sampleSize", sampleSize)
        PY_FIELD_P(AudioStream, "channels", channels)
    }
    wrapped__Sound::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "Sound_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(Sound)
        PY_FIELD_P(Sound, "stream", stream)
        PY_FIELD_P(Sound, "frameCount", frameCount)
    }
    wrapped__Music::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "Music_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(Music)
        PY_FIELD_P(Music, "stream", stream)
        PY_FIELD_P(Music, "frameCount", frameCount)
        PY_FIELD_P(Music, "looping", looping)
        PY_FIELD_P(Music, "ctxType", ctxType)
        PY_FIELD_P(Music, "ctxData", ctxData)
    }
    wrapped__VrDeviceInfo::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "VrDeviceInfo_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(VrDeviceInfo)
        PY_FIELD_P(VrDeviceInfo, "hResolution", hResolution)
        PY_FIELD_P(VrDeviceInfo, "vResolution", vResolution)
        PY_FIELD_P(VrDeviceInfo, "hScreenSize", hScreenSize)
        PY_FIELD_P(VrDeviceInfo, "vScreenSize", vScreenSize)
        PY_FIELD_P(VrDeviceInfo, "vScreenCenter", vScreenCenter)
        PY_FIELD_P(VrDeviceInfo, "eyeToScreenDistance", eyeToScreenDistance)
        PY_FIELD_P(VrDeviceInfo, "lensSeparationDistance", lensSeparationDistance)
        PY_FIELD_P(VrDeviceInfo, "interpupillaryDistance", interpupillaryDistance)
        PY_READONLY_FIELD_P(VrDeviceInfo, "lensDistortionValues", lensDistortionValues)
        PY_READONLY_FIELD_P(VrDeviceInfo, "chromaAbCorrection", chromaAbCorrection)
    }
    wrapped__VrStereoConfig::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "VrStereoConfig_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(VrStereoConfig)
        PY_READONLY_FIELD_P(VrStereoConfig, "projection", projection)
        PY_READONLY_FIELD_P(VrStereoConfig, "viewOffset", viewOffset)
        PY_READONLY_FIELD_P(VrStereoConfig, "leftLensCenter", leftLensCenter)
        PY_READONLY_FIELD_P(VrStereoConfig, "rightLensCenter", rightLensCenter)
        PY_READONLY_FIELD_P(VrStereoConfig, "leftScreenCenter", leftScreenCenter)
        PY_READONLY_FIELD_P(VrStereoConfig, "rightScreenCenter", rightScreenCenter)
        PY_READONLY_FIELD_P(VrStereoConfig, "scale", scale)
        PY_READONLY_FIELD_P(VrStereoConfig, "scaleIn", scaleIn)
    }
    wrapped__FilePathList::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "FilePathList_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(FilePathList)
        PY_FIELD_P(FilePathList, "capacity", capacity)
        PY_FIELD_P(FilePathList, "count", count)
        PY_FIELD_P(FilePathList, "paths", paths)
    }
    wrapped__AutomationEvent::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "AutomationEvent_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(AutomationEvent)
        PY_FIELD_P(AutomationEvent, "frame", frame)
        PY_FIELD_P(AutomationEvent, "type", type)
        PY_READONLY_FIELD_P(AutomationEvent, "params", params)
    }
    wrapped__AutomationEventList::register_class(vm, mod);
    {
        PyObject* type = vm->new_type_object(mod, "AutomationEventList_p", VoidP::_type(vm));
        PY_POINTER_SETGETITEM(AutomationEventList)
        PY_FIELD_P(AutomationEventList, "capacity", capacity)
        PY_FIELD_P(AutomationEventList, "count", count)
        PY_FIELD_P(AutomationEventList, "events", events)
    }

    _bind(vm, mod, "InitWindow(width: int, height: int, title: str) -> None", &InitWindow);
    _bind(vm, mod, "CloseWindow() -> None", &CloseWindow);
    _bind(vm, mod, "WindowShouldClose() -> bool", &WindowShouldClose);
    _bind(vm, mod, "IsWindowReady() -> bool", &IsWindowReady);
    _bind(vm, mod, "IsWindowFullscreen() -> bool", &IsWindowFullscreen);
    _bind(vm, mod, "IsWindowHidden() -> bool", &IsWindowHidden);
    _bind(vm, mod, "IsWindowMinimized() -> bool", &IsWindowMinimized);
    _bind(vm, mod, "IsWindowMaximized() -> bool", &IsWindowMaximized);
    _bind(vm, mod, "IsWindowFocused() -> bool", &IsWindowFocused);
    _bind(vm, mod, "IsWindowResized() -> bool", &IsWindowResized);
    _bind(vm, mod, "IsWindowState(flag: int) -> bool", &IsWindowState);
    _bind(vm, mod, "SetWindowState(flags: int) -> None", &SetWindowState);
    _bind(vm, mod, "ClearWindowState(flags: int) -> None", &ClearWindowState);
    _bind(vm, mod, "ToggleFullscreen() -> None", &ToggleFullscreen);
    _bind(vm, mod, "ToggleBorderlessWindowed() -> None", &ToggleBorderlessWindowed);
    _bind(vm, mod, "MaximizeWindow() -> None", &MaximizeWindow);
    _bind(vm, mod, "MinimizeWindow() -> None", &MinimizeWindow);
    _bind(vm, mod, "RestoreWindow() -> None", &RestoreWindow);
    _bind(vm, mod, "SetWindowIcon(image: Image) -> None", &SetWindowIcon);
    _bind(vm, mod, "SetWindowIcons(images: 'Image_p', count: int) -> None", &SetWindowIcons);
    _bind(vm, mod, "SetWindowTitle(title: str) -> None", &SetWindowTitle);
    _bind(vm, mod, "SetWindowPosition(x: int, y: int) -> None", &SetWindowPosition);
    _bind(vm, mod, "SetWindowMonitor(monitor: int) -> None", &SetWindowMonitor);
    _bind(vm, mod, "SetWindowMinSize(width: int, height: int) -> None", &SetWindowMinSize);
    _bind(vm, mod, "SetWindowMaxSize(width: int, height: int) -> None", &SetWindowMaxSize);
    _bind(vm, mod, "SetWindowSize(width: int, height: int) -> None", &SetWindowSize);
    _bind(vm, mod, "SetWindowOpacity(opacity: float) -> None", &SetWindowOpacity);
    _bind(vm, mod, "SetWindowFocused() -> None", &SetWindowFocused);
    _bind(vm, mod, "GetWindowHandle() -> void_p", &GetWindowHandle);
    _bind(vm, mod, "GetScreenWidth() -> int", &GetScreenWidth);
    _bind(vm, mod, "GetScreenHeight() -> int", &GetScreenHeight);
    _bind(vm, mod, "GetRenderWidth() -> int", &GetRenderWidth);
    _bind(vm, mod, "GetRenderHeight() -> int", &GetRenderHeight);
    _bind(vm, mod, "GetMonitorCount() -> int", &GetMonitorCount);
    _bind(vm, mod, "GetCurrentMonitor() -> int", &GetCurrentMonitor);
    _bind(vm, mod, "GetMonitorPosition(monitor: int) -> vec2", &GetMonitorPosition);
    _bind(vm, mod, "GetMonitorWidth(monitor: int) -> int", &GetMonitorWidth);
    _bind(vm, mod, "GetMonitorHeight(monitor: int) -> int", &GetMonitorHeight);
    _bind(vm, mod, "GetMonitorPhysicalWidth(monitor: int) -> int", &GetMonitorPhysicalWidth);
    _bind(vm, mod, "GetMonitorPhysicalHeight(monitor: int) -> int", &GetMonitorPhysicalHeight);
    _bind(vm, mod, "GetMonitorRefreshRate(monitor: int) -> int", &GetMonitorRefreshRate);
    _bind(vm, mod, "GetWindowPosition() -> vec2", &GetWindowPosition);
    _bind(vm, mod, "GetWindowScaleDPI() -> vec2", &GetWindowScaleDPI);
    _bind(vm, mod, "GetMonitorName(monitor: int) -> str", &GetMonitorName);
    _bind(vm, mod, "SetClipboardText(text: str) -> None", &SetClipboardText);
    _bind(vm, mod, "GetClipboardText() -> str", &GetClipboardText);
    _bind(vm, mod, "EnableEventWaiting() -> None", &EnableEventWaiting);
    _bind(vm, mod, "DisableEventWaiting() -> None", &DisableEventWaiting);
    _bind(vm, mod, "ShowCursor() -> None", &ShowCursor);
    _bind(vm, mod, "HideCursor() -> None", &HideCursor);
    _bind(vm, mod, "IsCursorHidden() -> bool", &IsCursorHidden);
    _bind(vm, mod, "EnableCursor() -> None", &EnableCursor);
    _bind(vm, mod, "DisableCursor() -> None", &DisableCursor);
    _bind(vm, mod, "IsCursorOnScreen() -> bool", &IsCursorOnScreen);
    _bind(vm, mod, "ClearBackground(color: Color) -> None", &ClearBackground);
    _bind(vm, mod, "BeginDrawing() -> None", &BeginDrawing);
    _bind(vm, mod, "EndDrawing() -> None", &EndDrawing);
    _bind(vm, mod, "BeginMode2D(camera: Camera2D) -> None", &BeginMode2D);
    _bind(vm, mod, "EndMode2D() -> None", &EndMode2D);
    _bind(vm, mod, "BeginMode3D(camera: Camera3D) -> None", &BeginMode3D);
    _bind(vm, mod, "EndMode3D() -> None", &EndMode3D);
    _bind(vm, mod, "BeginTextureMode(target: RenderTexture2D) -> None", &BeginTextureMode);
    _bind(vm, mod, "EndTextureMode() -> None", &EndTextureMode);
    _bind(vm, mod, "BeginShaderMode(shader: Shader) -> None", &BeginShaderMode);
    _bind(vm, mod, "EndShaderMode() -> None", &EndShaderMode);
    _bind(vm, mod, "BeginBlendMode(mode: int) -> None", &BeginBlendMode);
    _bind(vm, mod, "EndBlendMode() -> None", &EndBlendMode);
    _bind(vm, mod, "BeginScissorMode(x: int, y: int, width: int, height: int) -> None", &BeginScissorMode);
    _bind(vm, mod, "EndScissorMode() -> None", &EndScissorMode);
    _bind(vm, mod, "BeginVrStereoMode(config: VrStereoConfig) -> None", &BeginVrStereoMode);
    _bind(vm, mod, "EndVrStereoMode() -> None", &EndVrStereoMode);
    _bind(vm, mod, "LoadVrStereoConfig(device: VrDeviceInfo) -> VrStereoConfig", &LoadVrStereoConfig);
    _bind(vm, mod, "UnloadVrStereoConfig(config: VrStereoConfig) -> None", &UnloadVrStereoConfig);
    _bind(vm, mod, "LoadShader(vsFileName: str, fsFileName: str) -> Shader", &LoadShader);
    _bind(vm, mod, "LoadShaderFromMemory(vsCode: str, fsCode: str) -> Shader", &LoadShaderFromMemory);
    _bind(vm, mod, "IsShaderReady(shader: Shader) -> bool", &IsShaderReady);
    _bind(vm, mod, "GetShaderLocation(shader: Shader, uniformName: str) -> int", &GetShaderLocation);
    _bind(vm, mod, "GetShaderLocationAttrib(shader: Shader, attribName: str) -> int", &GetShaderLocationAttrib);
    _bind(vm, mod, "SetShaderValue(shader: Shader, locIndex: int, value: void_p, uniformType: int) -> None", &SetShaderValue);
    _bind(vm, mod, "SetShaderValueV(shader: Shader, locIndex: int, value: void_p, uniformType: int, count: int) -> None", &SetShaderValueV);
    _bind(vm, mod, "SetShaderValueMatrix(shader: Shader, locIndex: int, mat: Matrix) -> None", &SetShaderValueMatrix);
    _bind(vm, mod, "SetShaderValueTexture(shader: Shader, locIndex: int, texture: Texture2D) -> None", &SetShaderValueTexture);
    _bind(vm, mod, "UnloadShader(shader: Shader) -> None", &UnloadShader);
    _bind(vm, mod, "GetMouseRay(mousePosition: vec2, camera: Camera) -> Ray", &GetMouseRay);
    _bind(vm, mod, "GetCameraMatrix(camera: Camera) -> Matrix", &GetCameraMatrix);
    _bind(vm, mod, "GetCameraMatrix2D(camera: Camera2D) -> Matrix", &GetCameraMatrix2D);
    _bind(vm, mod, "GetWorldToScreen(position: vec3, camera: Camera) -> vec2", &GetWorldToScreen);
    _bind(vm, mod, "GetScreenToWorld2D(position: vec2, camera: Camera2D) -> vec2", &GetScreenToWorld2D);
    _bind(vm, mod, "GetWorldToScreenEx(position: vec3, camera: Camera, width: int, height: int) -> vec2", &GetWorldToScreenEx);
    _bind(vm, mod, "GetWorldToScreen2D(position: vec2, camera: Camera2D) -> vec2", &GetWorldToScreen2D);
    _bind(vm, mod, "SetTargetFPS(fps: int) -> None", &SetTargetFPS);
    _bind(vm, mod, "GetFrameTime() -> float", &GetFrameTime);
    _bind(vm, mod, "GetTime() -> float", &GetTime);
    _bind(vm, mod, "GetFPS() -> int", &GetFPS);
    _bind(vm, mod, "SwapScreenBuffer() -> None", &SwapScreenBuffer);
    _bind(vm, mod, "PollInputEvents() -> None", &PollInputEvents);
    _bind(vm, mod, "WaitTime(seconds: float) -> None", &WaitTime);
    _bind(vm, mod, "SetRandomSeed(seed: int) -> None", &SetRandomSeed);
    _bind(vm, mod, "GetRandomValue(min: int, max: int) -> int", &GetRandomValue);
    _bind(vm, mod, "LoadRandomSequence(count: int, min: int, max: int) -> int_p", &LoadRandomSequence);
    _bind(vm, mod, "UnloadRandomSequence(sequence: int_p) -> None", &UnloadRandomSequence);
    _bind(vm, mod, "TakeScreenshot(fileName: str) -> None", &TakeScreenshot);
    _bind(vm, mod, "SetConfigFlags(flags: int) -> None", &SetConfigFlags);
    _bind(vm, mod, "OpenURL(url: str) -> None", &OpenURL);
    _bind(vm, mod, "SetTraceLogLevel(logLevel: int) -> None", &SetTraceLogLevel);
    _bind(vm, mod, "MemAlloc(size: int) -> void_p", &MemAlloc);
    _bind(vm, mod, "MemRealloc(ptr: void_p, size: int) -> void_p", &MemRealloc);
    _bind(vm, mod, "MemFree(ptr: void_p) -> None", &MemFree);
    _bind(vm, mod, "LoadFileData(fileName: str, dataSize: int_p) -> uchar_p", &LoadFileData);
    _bind(vm, mod, "UnloadFileData(data: uchar_p) -> None", &UnloadFileData);
    _bind(vm, mod, "SaveFileData(fileName: str, data: void_p, dataSize: int) -> bool", &SaveFileData);
    _bind(vm, mod, "ExportDataAsCode(data: uchar_p, dataSize: int, fileName: str) -> bool", &ExportDataAsCode);
    _bind(vm, mod, "LoadFileText(fileName: str) -> char_p", &LoadFileText);
    _bind(vm, mod, "UnloadFileText(text: char_p) -> None", &UnloadFileText);
    _bind(vm, mod, "SaveFileText(fileName: str, text: char_p) -> bool", &SaveFileText);
    _bind(vm, mod, "FileExists(fileName: str) -> bool", &FileExists);
    _bind(vm, mod, "DirectoryExists(dirPath: str) -> bool", &DirectoryExists);
    _bind(vm, mod, "IsFileExtension(fileName: str, ext: str) -> bool", &IsFileExtension);
    _bind(vm, mod, "GetFileLength(fileName: str) -> int", &GetFileLength);
    _bind(vm, mod, "GetFileExtension(fileName: str) -> str", &GetFileExtension);
    _bind(vm, mod, "GetFileName(filePath: str) -> str", &GetFileName);
    _bind(vm, mod, "GetFileNameWithoutExt(filePath: str) -> str", &GetFileNameWithoutExt);
    _bind(vm, mod, "GetDirectoryPath(filePath: str) -> str", &GetDirectoryPath);
    _bind(vm, mod, "GetPrevDirectoryPath(dirPath: str) -> str", &GetPrevDirectoryPath);
    _bind(vm, mod, "GetWorkingDirectory() -> str", &GetWorkingDirectory);
    _bind(vm, mod, "GetApplicationDirectory() -> str", &GetApplicationDirectory);
    _bind(vm, mod, "ChangeDirectory(dir: str) -> bool", &ChangeDirectory);
    _bind(vm, mod, "IsPathFile(path: str) -> bool", &IsPathFile);
    _bind(vm, mod, "LoadDirectoryFiles(dirPath: str) -> FilePathList", &LoadDirectoryFiles);
    _bind(vm, mod, "LoadDirectoryFilesEx(basePath: str, filter: str, scanSubdirs: bool) -> FilePathList", &LoadDirectoryFilesEx);
    _bind(vm, mod, "UnloadDirectoryFiles(files: FilePathList) -> None", &UnloadDirectoryFiles);
    _bind(vm, mod, "IsFileDropped() -> bool", &IsFileDropped);
    _bind(vm, mod, "LoadDroppedFiles() -> FilePathList", &LoadDroppedFiles);
    _bind(vm, mod, "UnloadDroppedFiles(files: FilePathList) -> None", &UnloadDroppedFiles);
    _bind(vm, mod, "GetFileModTime(fileName: str) -> int", &GetFileModTime);
    _bind(vm, mod, "CompressData(data: uchar_p, dataSize: int, compDataSize: int_p) -> uchar_p", &CompressData);
    _bind(vm, mod, "DecompressData(compData: uchar_p, compDataSize: int, dataSize: int_p) -> uchar_p", &DecompressData);
    _bind(vm, mod, "EncodeDataBase64(data: uchar_p, dataSize: int, outputSize: int_p) -> char_p", &EncodeDataBase64);
    _bind(vm, mod, "DecodeDataBase64(data: uchar_p, outputSize: int_p) -> uchar_p", &DecodeDataBase64);
    _bind(vm, mod, "LoadAutomationEventList(fileName: str) -> AutomationEventList", &LoadAutomationEventList);
    _bind(vm, mod, "UnloadAutomationEventList(list: 'AutomationEventList_p') -> None", &UnloadAutomationEventList);
    _bind(vm, mod, "ExportAutomationEventList(list: AutomationEventList, fileName: str) -> bool", &ExportAutomationEventList);
    _bind(vm, mod, "SetAutomationEventList(list: 'AutomationEventList_p') -> None", &SetAutomationEventList);
    _bind(vm, mod, "SetAutomationEventBaseFrame(frame: int) -> None", &SetAutomationEventBaseFrame);
    _bind(vm, mod, "StartAutomationEventRecording() -> None", &StartAutomationEventRecording);
    _bind(vm, mod, "StopAutomationEventRecording() -> None", &StopAutomationEventRecording);
    _bind(vm, mod, "PlayAutomationEvent(event: AutomationEvent) -> None", &PlayAutomationEvent);
    _bind(vm, mod, "IsKeyPressed(key: int) -> bool", &IsKeyPressed);
    _bind(vm, mod, "IsKeyPressedRepeat(key: int) -> bool", &IsKeyPressedRepeat);
    _bind(vm, mod, "IsKeyDown(key: int) -> bool", &IsKeyDown);
    _bind(vm, mod, "IsKeyReleased(key: int) -> bool", &IsKeyReleased);
    _bind(vm, mod, "IsKeyUp(key: int) -> bool", &IsKeyUp);
    _bind(vm, mod, "GetKeyPressed() -> int", &GetKeyPressed);
    _bind(vm, mod, "GetCharPressed() -> int", &GetCharPressed);
    _bind(vm, mod, "SetExitKey(key: int) -> None", &SetExitKey);
    _bind(vm, mod, "IsGamepadAvailable(gamepad: int) -> bool", &IsGamepadAvailable);
    _bind(vm, mod, "GetGamepadName(gamepad: int) -> str", &GetGamepadName);
    _bind(vm, mod, "IsGamepadButtonPressed(gamepad: int, button: int) -> bool", &IsGamepadButtonPressed);
    _bind(vm, mod, "IsGamepadButtonDown(gamepad: int, button: int) -> bool", &IsGamepadButtonDown);
    _bind(vm, mod, "IsGamepadButtonReleased(gamepad: int, button: int) -> bool", &IsGamepadButtonReleased);
    _bind(vm, mod, "IsGamepadButtonUp(gamepad: int, button: int) -> bool", &IsGamepadButtonUp);
    _bind(vm, mod, "GetGamepadButtonPressed() -> int", &GetGamepadButtonPressed);
    _bind(vm, mod, "GetGamepadAxisCount(gamepad: int) -> int", &GetGamepadAxisCount);
    _bind(vm, mod, "GetGamepadAxisMovement(gamepad: int, axis: int) -> float", &GetGamepadAxisMovement);
    _bind(vm, mod, "SetGamepadMappings(mappings: str) -> int", &SetGamepadMappings);
    _bind(vm, mod, "IsMouseButtonPressed(button: int) -> bool", &IsMouseButtonPressed);
    _bind(vm, mod, "IsMouseButtonDown(button: int) -> bool", &IsMouseButtonDown);
    _bind(vm, mod, "IsMouseButtonReleased(button: int) -> bool", &IsMouseButtonReleased);
    _bind(vm, mod, "IsMouseButtonUp(button: int) -> bool", &IsMouseButtonUp);
    _bind(vm, mod, "GetMouseX() -> int", &GetMouseX);
    _bind(vm, mod, "GetMouseY() -> int", &GetMouseY);
    _bind(vm, mod, "GetMousePosition() -> vec2", &GetMousePosition);
    _bind(vm, mod, "GetMouseDelta() -> vec2", &GetMouseDelta);
    _bind(vm, mod, "SetMousePosition(x: int, y: int) -> None", &SetMousePosition);
    _bind(vm, mod, "SetMouseOffset(offsetX: int, offsetY: int) -> None", &SetMouseOffset);
    _bind(vm, mod, "SetMouseScale(scaleX: float, scaleY: float) -> None", &SetMouseScale);
    _bind(vm, mod, "GetMouseWheelMove() -> float", &GetMouseWheelMove);
    _bind(vm, mod, "GetMouseWheelMoveV() -> vec2", &GetMouseWheelMoveV);
    _bind(vm, mod, "SetMouseCursor(cursor: int) -> None", &SetMouseCursor);
    _bind(vm, mod, "GetTouchX() -> int", &GetTouchX);
    _bind(vm, mod, "GetTouchY() -> int", &GetTouchY);
    _bind(vm, mod, "GetTouchPosition(index: int) -> vec2", &GetTouchPosition);
    _bind(vm, mod, "GetTouchPointId(index: int) -> int", &GetTouchPointId);
    _bind(vm, mod, "GetTouchPointCount() -> int", &GetTouchPointCount);
    _bind(vm, mod, "SetGesturesEnabled(flags: int) -> None", &SetGesturesEnabled);
    _bind(vm, mod, "IsGestureDetected(gesture: int) -> bool", &IsGestureDetected);
    _bind(vm, mod, "GetGestureDetected() -> int", &GetGestureDetected);
    _bind(vm, mod, "GetGestureHoldDuration() -> float", &GetGestureHoldDuration);
    _bind(vm, mod, "GetGestureDragVector() -> vec2", &GetGestureDragVector);
    _bind(vm, mod, "GetGestureDragAngle() -> float", &GetGestureDragAngle);
    _bind(vm, mod, "GetGesturePinchVector() -> vec2", &GetGesturePinchVector);
    _bind(vm, mod, "GetGesturePinchAngle() -> float", &GetGesturePinchAngle);
    _bind(vm, mod, "UpdateCamera(camera: 'Camera_p', mode: int) -> None", &UpdateCamera);
    _bind(vm, mod, "UpdateCameraPro(camera: 'Camera_p', movement: vec3, rotation: vec3, zoom: float) -> None", &UpdateCameraPro);
    _bind(vm, mod, "SetShapesTexture(texture: Texture2D, source: Rectangle) -> None", &SetShapesTexture);
    _bind(vm, mod, "DrawPixel(posX: int, posY: int, color: Color) -> None", &DrawPixel);
    _bind(vm, mod, "DrawPixelV(position: vec2, color: Color) -> None", &DrawPixelV);
    _bind(vm, mod, "DrawLine(startPosX: int, startPosY: int, endPosX: int, endPosY: int, color: Color) -> None", &DrawLine);
    _bind(vm, mod, "DrawLineV(startPos: vec2, endPos: vec2, color: Color) -> None", &DrawLineV);
    _bind(vm, mod, "DrawLineEx(startPos: vec2, endPos: vec2, thick: float, color: Color) -> None", &DrawLineEx);
    _bind(vm, mod, "DrawLineStrip(points: 'vec2_p', pointCount: int, color: Color) -> None", &DrawLineStrip);
    _bind(vm, mod, "DrawLineBezier(startPos: vec2, endPos: vec2, thick: float, color: Color) -> None", &DrawLineBezier);
    _bind(vm, mod, "DrawCircle(centerX: int, centerY: int, radius: float, color: Color) -> None", &DrawCircle);
    _bind(vm, mod, "DrawCircleSector(center: vec2, radius: float, startAngle: float, endAngle: float, segments: int, color: Color) -> None", &DrawCircleSector);
    _bind(vm, mod, "DrawCircleSectorLines(center: vec2, radius: float, startAngle: float, endAngle: float, segments: int, color: Color) -> None", &DrawCircleSectorLines);
    _bind(vm, mod, "DrawCircleGradient(centerX: int, centerY: int, radius: float, color1: Color, color2: Color) -> None", &DrawCircleGradient);
    _bind(vm, mod, "DrawCircleV(center: vec2, radius: float, color: Color) -> None", &DrawCircleV);
    _bind(vm, mod, "DrawCircleLines(centerX: int, centerY: int, radius: float, color: Color) -> None", &DrawCircleLines);
    _bind(vm, mod, "DrawCircleLinesV(center: vec2, radius: float, color: Color) -> None", &DrawCircleLinesV);
    _bind(vm, mod, "DrawEllipse(centerX: int, centerY: int, radiusH: float, radiusV: float, color: Color) -> None", &DrawEllipse);
    _bind(vm, mod, "DrawEllipseLines(centerX: int, centerY: int, radiusH: float, radiusV: float, color: Color) -> None", &DrawEllipseLines);
    _bind(vm, mod, "DrawRing(center: vec2, innerRadius: float, outerRadius: float, startAngle: float, endAngle: float, segments: int, color: Color) -> None", &DrawRing);
    _bind(vm, mod, "DrawRingLines(center: vec2, innerRadius: float, outerRadius: float, startAngle: float, endAngle: float, segments: int, color: Color) -> None", &DrawRingLines);
    _bind(vm, mod, "DrawRectangle(posX: int, posY: int, width: int, height: int, color: Color) -> None", &DrawRectangle);
    _bind(vm, mod, "DrawRectangleV(position: vec2, size: vec2, color: Color) -> None", &DrawRectangleV);
    _bind(vm, mod, "DrawRectangleRec(rec: Rectangle, color: Color) -> None", &DrawRectangleRec);
    _bind(vm, mod, "DrawRectanglePro(rec: Rectangle, origin: vec2, rotation: float, color: Color) -> None", &DrawRectanglePro);
    _bind(vm, mod, "DrawRectangleGradientV(posX: int, posY: int, width: int, height: int, color1: Color, color2: Color) -> None", &DrawRectangleGradientV);
    _bind(vm, mod, "DrawRectangleGradientH(posX: int, posY: int, width: int, height: int, color1: Color, color2: Color) -> None", &DrawRectangleGradientH);
    _bind(vm, mod, "DrawRectangleGradientEx(rec: Rectangle, col1: Color, col2: Color, col3: Color, col4: Color) -> None", &DrawRectangleGradientEx);
    _bind(vm, mod, "DrawRectangleLines(posX: int, posY: int, width: int, height: int, color: Color) -> None", &DrawRectangleLines);
    _bind(vm, mod, "DrawRectangleLinesEx(rec: Rectangle, lineThick: float, color: Color) -> None", &DrawRectangleLinesEx);
    _bind(vm, mod, "DrawRectangleRounded(rec: Rectangle, roundness: float, segments: int, color: Color) -> None", &DrawRectangleRounded);
    _bind(vm, mod, "DrawRectangleRoundedLines(rec: Rectangle, roundness: float, segments: int, lineThick: float, color: Color) -> None", &DrawRectangleRoundedLines);
    _bind(vm, mod, "DrawTriangle(v1: vec2, v2: vec2, v3: vec2, color: Color) -> None", &DrawTriangle);
    _bind(vm, mod, "DrawTriangleLines(v1: vec2, v2: vec2, v3: vec2, color: Color) -> None", &DrawTriangleLines);
    _bind(vm, mod, "DrawTriangleFan(points: 'vec2_p', pointCount: int, color: Color) -> None", &DrawTriangleFan);
    _bind(vm, mod, "DrawTriangleStrip(points: 'vec2_p', pointCount: int, color: Color) -> None", &DrawTriangleStrip);
    _bind(vm, mod, "DrawPoly(center: vec2, sides: int, radius: float, rotation: float, color: Color) -> None", &DrawPoly);
    _bind(vm, mod, "DrawPolyLines(center: vec2, sides: int, radius: float, rotation: float, color: Color) -> None", &DrawPolyLines);
    _bind(vm, mod, "DrawPolyLinesEx(center: vec2, sides: int, radius: float, rotation: float, lineThick: float, color: Color) -> None", &DrawPolyLinesEx);
    _bind(vm, mod, "DrawSplineLinear(points: 'vec2_p', pointCount: int, thick: float, color: Color) -> None", &DrawSplineLinear);
    _bind(vm, mod, "DrawSplineBasis(points: 'vec2_p', pointCount: int, thick: float, color: Color) -> None", &DrawSplineBasis);
    _bind(vm, mod, "DrawSplineCatmullRom(points: 'vec2_p', pointCount: int, thick: float, color: Color) -> None", &DrawSplineCatmullRom);
    _bind(vm, mod, "DrawSplineBezierQuadratic(points: 'vec2_p', pointCount: int, thick: float, color: Color) -> None", &DrawSplineBezierQuadratic);
    _bind(vm, mod, "DrawSplineBezierCubic(points: 'vec2_p', pointCount: int, thick: float, color: Color) -> None", &DrawSplineBezierCubic);
    _bind(vm, mod, "DrawSplineSegmentLinear(p1: vec2, p2: vec2, thick: float, color: Color) -> None", &DrawSplineSegmentLinear);
    _bind(vm, mod, "DrawSplineSegmentBasis(p1: vec2, p2: vec2, p3: vec2, p4: vec2, thick: float, color: Color) -> None", &DrawSplineSegmentBasis);
    _bind(vm, mod, "DrawSplineSegmentCatmullRom(p1: vec2, p2: vec2, p3: vec2, p4: vec2, thick: float, color: Color) -> None", &DrawSplineSegmentCatmullRom);
    _bind(vm, mod, "DrawSplineSegmentBezierQuadratic(p1: vec2, c2: vec2, p3: vec2, thick: float, color: Color) -> None", &DrawSplineSegmentBezierQuadratic);
    _bind(vm, mod, "DrawSplineSegmentBezierCubic(p1: vec2, c2: vec2, c3: vec2, p4: vec2, thick: float, color: Color) -> None", &DrawSplineSegmentBezierCubic);
    _bind(vm, mod, "GetSplinePointLinear(startPos: vec2, endPos: vec2, t: float) -> vec2", &GetSplinePointLinear);
    _bind(vm, mod, "GetSplinePointBasis(p1: vec2, p2: vec2, p3: vec2, p4: vec2, t: float) -> vec2", &GetSplinePointBasis);
    _bind(vm, mod, "GetSplinePointCatmullRom(p1: vec2, p2: vec2, p3: vec2, p4: vec2, t: float) -> vec2", &GetSplinePointCatmullRom);
    _bind(vm, mod, "GetSplinePointBezierQuad(p1: vec2, c2: vec2, p3: vec2, t: float) -> vec2", &GetSplinePointBezierQuad);
    _bind(vm, mod, "GetSplinePointBezierCubic(p1: vec2, c2: vec2, c3: vec2, p4: vec2, t: float) -> vec2", &GetSplinePointBezierCubic);
    _bind(vm, mod, "CheckCollisionRecs(rec1: Rectangle, rec2: Rectangle) -> bool", &CheckCollisionRecs);
    _bind(vm, mod, "CheckCollisionCircles(center1: vec2, radius1: float, center2: vec2, radius2: float) -> bool", &CheckCollisionCircles);
    _bind(vm, mod, "CheckCollisionCircleRec(center: vec2, radius: float, rec: Rectangle) -> bool", &CheckCollisionCircleRec);
    _bind(vm, mod, "CheckCollisionPointRec(point: vec2, rec: Rectangle) -> bool", &CheckCollisionPointRec);
    _bind(vm, mod, "CheckCollisionPointCircle(point: vec2, center: vec2, radius: float) -> bool", &CheckCollisionPointCircle);
    _bind(vm, mod, "CheckCollisionPointTriangle(point: vec2, p1: vec2, p2: vec2, p3: vec2) -> bool", &CheckCollisionPointTriangle);
    _bind(vm, mod, "CheckCollisionPointPoly(point: vec2, points: 'vec2_p', pointCount: int) -> bool", &CheckCollisionPointPoly);
    _bind(vm, mod, "CheckCollisionLines(startPos1: vec2, endPos1: vec2, startPos2: vec2, endPos2: vec2, collisionPoint: 'vec2_p') -> bool", &CheckCollisionLines);
    _bind(vm, mod, "CheckCollisionPointLine(point: vec2, p1: vec2, p2: vec2, threshold: int) -> bool", &CheckCollisionPointLine);
    _bind(vm, mod, "GetCollisionRec(rec1: Rectangle, rec2: Rectangle) -> Rectangle", &GetCollisionRec);
    _bind(vm, mod, "LoadImage(fileName: str) -> Image", &LoadImage);
    _bind(vm, mod, "LoadImageRaw(fileName: str, width: int, height: int, format: int, headerSize: int) -> Image", &LoadImageRaw);
    _bind(vm, mod, "LoadImageSvg(fileNameOrString: str, width: int, height: int) -> Image", &LoadImageSvg);
    _bind(vm, mod, "LoadImageAnim(fileName: str, frames: int_p) -> Image", &LoadImageAnim);
    _bind(vm, mod, "LoadImageFromMemory(fileType: str, fileData: uchar_p, dataSize: int) -> Image", &LoadImageFromMemory);
    _bind(vm, mod, "LoadImageFromTexture(texture: Texture2D) -> Image", &LoadImageFromTexture);
    _bind(vm, mod, "LoadImageFromScreen() -> Image", &LoadImageFromScreen);
    _bind(vm, mod, "IsImageReady(image: Image) -> bool", &IsImageReady);
    _bind(vm, mod, "UnloadImage(image: Image) -> None", &UnloadImage);
    _bind(vm, mod, "ExportImage(image: Image, fileName: str) -> bool", &ExportImage);
    _bind(vm, mod, "ExportImageToMemory(image: Image, fileType: str, fileSize: int_p) -> uchar_p", &ExportImageToMemory);
    _bind(vm, mod, "ExportImageAsCode(image: Image, fileName: str) -> bool", &ExportImageAsCode);
    _bind(vm, mod, "GenImageColor(width: int, height: int, color: Color) -> Image", &GenImageColor);
    _bind(vm, mod, "GenImageGradientLinear(width: int, height: int, direction: int, start: Color, end: Color) -> Image", &GenImageGradientLinear);
    _bind(vm, mod, "GenImageGradientRadial(width: int, height: int, density: float, inner: Color, outer: Color) -> Image", &GenImageGradientRadial);
    _bind(vm, mod, "GenImageGradientSquare(width: int, height: int, density: float, inner: Color, outer: Color) -> Image", &GenImageGradientSquare);
    _bind(vm, mod, "GenImageChecked(width: int, height: int, checksX: int, checksY: int, col1: Color, col2: Color) -> Image", &GenImageChecked);
    _bind(vm, mod, "GenImageWhiteNoise(width: int, height: int, factor: float) -> Image", &GenImageWhiteNoise);
    _bind(vm, mod, "GenImagePerlinNoise(width: int, height: int, offsetX: int, offsetY: int, scale: float) -> Image", &GenImagePerlinNoise);
    _bind(vm, mod, "GenImageCellular(width: int, height: int, tileSize: int) -> Image", &GenImageCellular);
    _bind(vm, mod, "GenImageText(width: int, height: int, text: str) -> Image", &GenImageText);
    _bind(vm, mod, "ImageCopy(image: Image) -> Image", &ImageCopy);
    _bind(vm, mod, "ImageFromImage(image: Image, rec: Rectangle) -> Image", &ImageFromImage);
    _bind(vm, mod, "ImageText(text: str, fontSize: int, color: Color) -> Image", &ImageText);
    _bind(vm, mod, "ImageTextEx(font: Font, text: str, fontSize: float, spacing: float, tint: Color) -> Image", &ImageTextEx);
    _bind(vm, mod, "ImageFormat(image: 'Image_p', newFormat: int) -> None", &ImageFormat);
    _bind(vm, mod, "ImageToPOT(image: 'Image_p', fill: Color) -> None", &ImageToPOT);
    _bind(vm, mod, "ImageCrop(image: 'Image_p', crop: Rectangle) -> None", &ImageCrop);
    _bind(vm, mod, "ImageAlphaCrop(image: 'Image_p', threshold: float) -> None", &ImageAlphaCrop);
    _bind(vm, mod, "ImageAlphaClear(image: 'Image_p', color: Color, threshold: float) -> None", &ImageAlphaClear);
    _bind(vm, mod, "ImageAlphaMask(image: 'Image_p', alphaMask: Image) -> None", &ImageAlphaMask);
    _bind(vm, mod, "ImageAlphaPremultiply(image: 'Image_p') -> None", &ImageAlphaPremultiply);
    _bind(vm, mod, "ImageBlurGaussian(image: 'Image_p', blurSize: int) -> None", &ImageBlurGaussian);
    _bind(vm, mod, "ImageKernelConvolution(image: 'Image_p', kernel: float_p, kernelSize: int) -> None", &ImageKernelConvolution);
    _bind(vm, mod, "ImageResize(image: 'Image_p', newWidth: int, newHeight: int) -> None", &ImageResize);
    _bind(vm, mod, "ImageResizeNN(image: 'Image_p', newWidth: int, newHeight: int) -> None", &ImageResizeNN);
    _bind(vm, mod, "ImageResizeCanvas(image: 'Image_p', newWidth: int, newHeight: int, offsetX: int, offsetY: int, fill: Color) -> None", &ImageResizeCanvas);
    _bind(vm, mod, "ImageMipmaps(image: 'Image_p') -> None", &ImageMipmaps);
    _bind(vm, mod, "ImageDither(image: 'Image_p', rBpp: int, gBpp: int, bBpp: int, aBpp: int) -> None", &ImageDither);
    _bind(vm, mod, "ImageFlipVertical(image: 'Image_p') -> None", &ImageFlipVertical);
    _bind(vm, mod, "ImageFlipHorizontal(image: 'Image_p') -> None", &ImageFlipHorizontal);
    _bind(vm, mod, "ImageRotate(image: 'Image_p', degrees: int) -> None", &ImageRotate);
    _bind(vm, mod, "ImageRotateCW(image: 'Image_p') -> None", &ImageRotateCW);
    _bind(vm, mod, "ImageRotateCCW(image: 'Image_p') -> None", &ImageRotateCCW);
    _bind(vm, mod, "ImageColorTint(image: 'Image_p', color: Color) -> None", &ImageColorTint);
    _bind(vm, mod, "ImageColorInvert(image: 'Image_p') -> None", &ImageColorInvert);
    _bind(vm, mod, "ImageColorGrayscale(image: 'Image_p') -> None", &ImageColorGrayscale);
    _bind(vm, mod, "ImageColorContrast(image: 'Image_p', contrast: float) -> None", &ImageColorContrast);
    _bind(vm, mod, "ImageColorBrightness(image: 'Image_p', brightness: int) -> None", &ImageColorBrightness);
    _bind(vm, mod, "ImageColorReplace(image: 'Image_p', color: Color, replace: Color) -> None", &ImageColorReplace);
    _bind(vm, mod, "LoadImageColors(image: Image) -> 'Color_p'", &LoadImageColors);
    _bind(vm, mod, "LoadImagePalette(image: Image, maxPaletteSize: int, colorCount: int_p) -> 'Color_p'", &LoadImagePalette);
    _bind(vm, mod, "UnloadImageColors(colors: 'Color_p') -> None", &UnloadImageColors);
    _bind(vm, mod, "UnloadImagePalette(colors: 'Color_p') -> None", &UnloadImagePalette);
    _bind(vm, mod, "GetImageAlphaBorder(image: Image, threshold: float) -> Rectangle", &GetImageAlphaBorder);
    _bind(vm, mod, "GetImageColor(image: Image, x: int, y: int) -> Color", &GetImageColor);
    _bind(vm, mod, "ImageClearBackground(dst: 'Image_p', color: Color) -> None", &ImageClearBackground);
    _bind(vm, mod, "ImageDrawPixel(dst: 'Image_p', posX: int, posY: int, color: Color) -> None", &ImageDrawPixel);
    _bind(vm, mod, "ImageDrawPixelV(dst: 'Image_p', position: vec2, color: Color) -> None", &ImageDrawPixelV);
    _bind(vm, mod, "ImageDrawLine(dst: 'Image_p', startPosX: int, startPosY: int, endPosX: int, endPosY: int, color: Color) -> None", &ImageDrawLine);
    _bind(vm, mod, "ImageDrawLineV(dst: 'Image_p', start: vec2, end: vec2, color: Color) -> None", &ImageDrawLineV);
    _bind(vm, mod, "ImageDrawCircle(dst: 'Image_p', centerX: int, centerY: int, radius: int, color: Color) -> None", &ImageDrawCircle);
    _bind(vm, mod, "ImageDrawCircleV(dst: 'Image_p', center: vec2, radius: int, color: Color) -> None", &ImageDrawCircleV);
    _bind(vm, mod, "ImageDrawCircleLines(dst: 'Image_p', centerX: int, centerY: int, radius: int, color: Color) -> None", &ImageDrawCircleLines);
    _bind(vm, mod, "ImageDrawCircleLinesV(dst: 'Image_p', center: vec2, radius: int, color: Color) -> None", &ImageDrawCircleLinesV);
    _bind(vm, mod, "ImageDrawRectangle(dst: 'Image_p', posX: int, posY: int, width: int, height: int, color: Color) -> None", &ImageDrawRectangle);
    _bind(vm, mod, "ImageDrawRectangleV(dst: 'Image_p', position: vec2, size: vec2, color: Color) -> None", &ImageDrawRectangleV);
    _bind(vm, mod, "ImageDrawRectangleRec(dst: 'Image_p', rec: Rectangle, color: Color) -> None", &ImageDrawRectangleRec);
    _bind(vm, mod, "ImageDrawRectangleLines(dst: 'Image_p', rec: Rectangle, thick: int, color: Color) -> None", &ImageDrawRectangleLines);
    _bind(vm, mod, "ImageDraw(dst: 'Image_p', src: Image, srcRec: Rectangle, dstRec: Rectangle, tint: Color) -> None", &ImageDraw);
    _bind(vm, mod, "ImageDrawText(dst: 'Image_p', text: str, posX: int, posY: int, fontSize: int, color: Color) -> None", &ImageDrawText);
    _bind(vm, mod, "ImageDrawTextEx(dst: 'Image_p', font: Font, text: str, position: vec2, fontSize: float, spacing: float, tint: Color) -> None", &ImageDrawTextEx);
    _bind(vm, mod, "LoadTexture(fileName: str) -> Texture2D", &LoadTexture);
    _bind(vm, mod, "LoadTextureFromImage(image: Image) -> Texture2D", &LoadTextureFromImage);
    _bind(vm, mod, "LoadTextureCubemap(image: Image, layout: int) -> TextureCubemap", &LoadTextureCubemap);
    _bind(vm, mod, "LoadRenderTexture(width: int, height: int) -> RenderTexture2D", &LoadRenderTexture);
    _bind(vm, mod, "IsTextureReady(texture: Texture2D) -> bool", &IsTextureReady);
    _bind(vm, mod, "UnloadTexture(texture: Texture2D) -> None", &UnloadTexture);
    _bind(vm, mod, "IsRenderTextureReady(target: RenderTexture2D) -> bool", &IsRenderTextureReady);
    _bind(vm, mod, "UnloadRenderTexture(target: RenderTexture2D) -> None", &UnloadRenderTexture);
    _bind(vm, mod, "UpdateTexture(texture: Texture2D, pixels: void_p) -> None", &UpdateTexture);
    _bind(vm, mod, "UpdateTextureRec(texture: Texture2D, rec: Rectangle, pixels: void_p) -> None", &UpdateTextureRec);
    _bind(vm, mod, "GenTextureMipmaps(texture: 'Texture2D_p') -> None", &GenTextureMipmaps);
    _bind(vm, mod, "SetTextureFilter(texture: Texture2D, filter: int) -> None", &SetTextureFilter);
    _bind(vm, mod, "SetTextureWrap(texture: Texture2D, wrap: int) -> None", &SetTextureWrap);
    _bind(vm, mod, "DrawTexture(texture: Texture2D, posX: int, posY: int, tint: Color) -> None", &DrawTexture);
    _bind(vm, mod, "DrawTextureV(texture: Texture2D, position: vec2, tint: Color) -> None", &DrawTextureV);
    _bind(vm, mod, "DrawTextureEx(texture: Texture2D, position: vec2, rotation: float, scale: float, tint: Color) -> None", &DrawTextureEx);
    _bind(vm, mod, "DrawTextureRec(texture: Texture2D, source: Rectangle, position: vec2, tint: Color) -> None", &DrawTextureRec);
    _bind(vm, mod, "DrawTexturePro(texture: Texture2D, source: Rectangle, dest: Rectangle, origin: vec2, rotation: float, tint: Color) -> None", &DrawTexturePro);
    _bind(vm, mod, "DrawTextureNPatch(texture: Texture2D, nPatchInfo: NPatchInfo, dest: Rectangle, origin: vec2, rotation: float, tint: Color) -> None", &DrawTextureNPatch);
    _bind(vm, mod, "Fade(color: Color, alpha: float) -> Color", &Fade);
    _bind(vm, mod, "ColorToInt(color: Color) -> int", &ColorToInt);
    _bind(vm, mod, "ColorNormalize(color: Color) -> vec4", &ColorNormalize);
    _bind(vm, mod, "ColorFromNormalized(normalized: vec4) -> Color", &ColorFromNormalized);
    _bind(vm, mod, "ColorToHSV(color: Color) -> vec3", &ColorToHSV);
    _bind(vm, mod, "ColorFromHSV(hue: float, saturation: float, value: float) -> Color", &ColorFromHSV);
    _bind(vm, mod, "ColorTint(color: Color, tint: Color) -> Color", &ColorTint);
    _bind(vm, mod, "ColorBrightness(color: Color, factor: float) -> Color", &ColorBrightness);
    _bind(vm, mod, "ColorContrast(color: Color, contrast: float) -> Color", &ColorContrast);
    _bind(vm, mod, "ColorAlpha(color: Color, alpha: float) -> Color", &ColorAlpha);
    _bind(vm, mod, "ColorAlphaBlend(dst: Color, src: Color, tint: Color) -> Color", &ColorAlphaBlend);
    _bind(vm, mod, "GetColor(hexValue: int) -> Color", &GetColor);
    _bind(vm, mod, "GetPixelColor(srcPtr: void_p, format: int) -> Color", &GetPixelColor);
    _bind(vm, mod, "SetPixelColor(dstPtr: void_p, color: Color, format: int) -> None", &SetPixelColor);
    _bind(vm, mod, "GetPixelDataSize(width: int, height: int, format: int) -> int", &GetPixelDataSize);
    _bind(vm, mod, "GetFontDefault() -> Font", &GetFontDefault);
    _bind(vm, mod, "LoadFont(fileName: str) -> Font", &LoadFont);
    _bind(vm, mod, "LoadFontEx(fileName: str, fontSize: int, codepoints: int_p, codepointCount: int) -> Font", &LoadFontEx);
    _bind(vm, mod, "LoadFontFromImage(image: Image, key: Color, firstChar: int) -> Font", &LoadFontFromImage);
    _bind(vm, mod, "LoadFontFromMemory(fileType: str, fileData: uchar_p, dataSize: int, fontSize: int, codepoints: int_p, codepointCount: int) -> Font", &LoadFontFromMemory);
    _bind(vm, mod, "IsFontReady(font: Font) -> bool", &IsFontReady);
    _bind(vm, mod, "LoadFontData(fileData: uchar_p, dataSize: int, fontSize: int, codepoints: int_p, codepointCount: int, type: int) -> 'GlyphInfo_p'", &LoadFontData);
    _bind(vm, mod, "GenImageFontAtlas(glyphs: 'GlyphInfo_p', glyphRecs: void_p, glyphCount: int, fontSize: int, padding: int, packMethod: int) -> Image", &GenImageFontAtlas);
    _bind(vm, mod, "UnloadFontData(glyphs: 'GlyphInfo_p', glyphCount: int) -> None", &UnloadFontData);
    _bind(vm, mod, "UnloadFont(font: Font) -> None", &UnloadFont);
    _bind(vm, mod, "ExportFontAsCode(font: Font, fileName: str) -> bool", &ExportFontAsCode);
    _bind(vm, mod, "DrawFPS(posX: int, posY: int) -> None", &DrawFPS);
    _bind(vm, mod, "DrawText(text: str, posX: int, posY: int, fontSize: int, color: Color) -> None", &DrawText);
    _bind(vm, mod, "DrawTextEx(font: Font, text: str, position: vec2, fontSize: float, spacing: float, tint: Color) -> None", &DrawTextEx);
    _bind(vm, mod, "DrawTextPro(font: Font, text: str, position: vec2, origin: vec2, rotation: float, fontSize: float, spacing: float, tint: Color) -> None", &DrawTextPro);
    _bind(vm, mod, "DrawTextCodepoint(font: Font, codepoint: int, position: vec2, fontSize: float, tint: Color) -> None", &DrawTextCodepoint);
    _bind(vm, mod, "DrawTextCodepoints(font: Font, codepoints: int_p, codepointCount: int, position: vec2, fontSize: float, spacing: float, tint: Color) -> None", &DrawTextCodepoints);
    _bind(vm, mod, "SetTextLineSpacing(spacing: int) -> None", &SetTextLineSpacing);
    _bind(vm, mod, "MeasureText(text: str, fontSize: int) -> int", &MeasureText);
    _bind(vm, mod, "MeasureTextEx(font: Font, text: str, fontSize: float, spacing: float) -> vec2", &MeasureTextEx);
    _bind(vm, mod, "GetGlyphIndex(font: Font, codepoint: int) -> int", &GetGlyphIndex);
    _bind(vm, mod, "GetGlyphInfo(font: Font, codepoint: int) -> GlyphInfo", &GetGlyphInfo);
    _bind(vm, mod, "GetGlyphAtlasRec(font: Font, codepoint: int) -> Rectangle", &GetGlyphAtlasRec);
    _bind(vm, mod, "LoadUTF8(codepoints: int_p, length: int) -> char_p", &LoadUTF8);
    _bind(vm, mod, "UnloadUTF8(text: char_p) -> None", &UnloadUTF8);
    _bind(vm, mod, "LoadCodepoints(text: str, count: int_p) -> int_p", &LoadCodepoints);
    _bind(vm, mod, "UnloadCodepoints(codepoints: int_p) -> None", &UnloadCodepoints);
    _bind(vm, mod, "GetCodepointCount(text: str) -> int", &GetCodepointCount);
    _bind(vm, mod, "GetCodepoint(text: str, codepointSize: int_p) -> int", &GetCodepoint);
    _bind(vm, mod, "GetCodepointNext(text: str, codepointSize: int_p) -> int", &GetCodepointNext);
    _bind(vm, mod, "GetCodepointPrevious(text: str, codepointSize: int_p) -> int", &GetCodepointPrevious);
    _bind(vm, mod, "CodepointToUTF8(codepoint: int, utf8Size: int_p) -> str", &CodepointToUTF8);
    _bind(vm, mod, "TextCopy(dst: char_p, src: str) -> int", &TextCopy);
    _bind(vm, mod, "TextIsEqual(text1: str, text2: str) -> bool", &TextIsEqual);
    _bind(vm, mod, "TextLength(text: str) -> int", &TextLength);
    _bind(vm, mod, "TextSubtext(text: str, position: int, length: int) -> str", &TextSubtext);
    _bind(vm, mod, "TextReplace(text: char_p, replace: str, by: str) -> char_p", &TextReplace);
    _bind(vm, mod, "TextInsert(text: str, insert: str, position: int) -> char_p", &TextInsert);
    _bind(vm, mod, "TextJoin(textList: void_p, count: int, delimiter: str) -> str", &TextJoin);
    _bind(vm, mod, "TextSplit(text: str, delimiter: int, count: int_p) -> void_p", &TextSplit);
    _bind(vm, mod, "TextAppend(text: char_p, append: str, position: int_p) -> None", &TextAppend);
    _bind(vm, mod, "TextFindIndex(text: str, find: str) -> int", &TextFindIndex);
    _bind(vm, mod, "TextToUpper(text: str) -> str", &TextToUpper);
    _bind(vm, mod, "TextToLower(text: str) -> str", &TextToLower);
    _bind(vm, mod, "TextToPascal(text: str) -> str", &TextToPascal);
    _bind(vm, mod, "TextToInteger(text: str) -> int", &TextToInteger);
    _bind(vm, mod, "DrawLine3D(startPos: vec3, endPos: vec3, color: Color) -> None", &DrawLine3D);
    _bind(vm, mod, "DrawPoint3D(position: vec3, color: Color) -> None", &DrawPoint3D);
    _bind(vm, mod, "DrawCircle3D(center: vec3, radius: float, rotationAxis: vec3, rotationAngle: float, color: Color) -> None", &DrawCircle3D);
    _bind(vm, mod, "DrawTriangle3D(v1: vec3, v2: vec3, v3: vec3, color: Color) -> None", &DrawTriangle3D);
    _bind(vm, mod, "DrawTriangleStrip3D(points: 'vec3_p', pointCount: int, color: Color) -> None", &DrawTriangleStrip3D);
    _bind(vm, mod, "DrawCube(position: vec3, width: float, height: float, length: float, color: Color) -> None", &DrawCube);
    _bind(vm, mod, "DrawCubeV(position: vec3, size: vec3, color: Color) -> None", &DrawCubeV);
    _bind(vm, mod, "DrawCubeWires(position: vec3, width: float, height: float, length: float, color: Color) -> None", &DrawCubeWires);
    _bind(vm, mod, "DrawCubeWiresV(position: vec3, size: vec3, color: Color) -> None", &DrawCubeWiresV);
    _bind(vm, mod, "DrawSphere(centerPos: vec3, radius: float, color: Color) -> None", &DrawSphere);
    _bind(vm, mod, "DrawSphereEx(centerPos: vec3, radius: float, rings: int, slices: int, color: Color) -> None", &DrawSphereEx);
    _bind(vm, mod, "DrawSphereWires(centerPos: vec3, radius: float, rings: int, slices: int, color: Color) -> None", &DrawSphereWires);
    _bind(vm, mod, "DrawCylinder(position: vec3, radiusTop: float, radiusBottom: float, height: float, slices: int, color: Color) -> None", &DrawCylinder);
    _bind(vm, mod, "DrawCylinderEx(startPos: vec3, endPos: vec3, startRadius: float, endRadius: float, sides: int, color: Color) -> None", &DrawCylinderEx);
    _bind(vm, mod, "DrawCylinderWires(position: vec3, radiusTop: float, radiusBottom: float, height: float, slices: int, color: Color) -> None", &DrawCylinderWires);
    _bind(vm, mod, "DrawCylinderWiresEx(startPos: vec3, endPos: vec3, startRadius: float, endRadius: float, sides: int, color: Color) -> None", &DrawCylinderWiresEx);
    _bind(vm, mod, "DrawCapsule(startPos: vec3, endPos: vec3, radius: float, slices: int, rings: int, color: Color) -> None", &DrawCapsule);
    _bind(vm, mod, "DrawCapsuleWires(startPos: vec3, endPos: vec3, radius: float, slices: int, rings: int, color: Color) -> None", &DrawCapsuleWires);
    _bind(vm, mod, "DrawPlane(centerPos: vec3, size: vec2, color: Color) -> None", &DrawPlane);
    _bind(vm, mod, "DrawRay(ray: Ray, color: Color) -> None", &DrawRay);
    _bind(vm, mod, "DrawGrid(slices: int, spacing: float) -> None", &DrawGrid);
    _bind(vm, mod, "LoadModel(fileName: str) -> Model", &LoadModel);
    _bind(vm, mod, "LoadModelFromMesh(mesh: Mesh) -> Model", &LoadModelFromMesh);
    _bind(vm, mod, "IsModelReady(model: Model) -> bool", &IsModelReady);
    _bind(vm, mod, "UnloadModel(model: Model) -> None", &UnloadModel);
    _bind(vm, mod, "GetModelBoundingBox(model: Model) -> BoundingBox", &GetModelBoundingBox);
    _bind(vm, mod, "DrawModel(model: Model, position: vec3, scale: float, tint: Color) -> None", &DrawModel);
    _bind(vm, mod, "DrawModelEx(model: Model, position: vec3, rotationAxis: vec3, rotationAngle: float, scale: vec3, tint: Color) -> None", &DrawModelEx);
    _bind(vm, mod, "DrawModelWires(model: Model, position: vec3, scale: float, tint: Color) -> None", &DrawModelWires);
    _bind(vm, mod, "DrawModelWiresEx(model: Model, position: vec3, rotationAxis: vec3, rotationAngle: float, scale: vec3, tint: Color) -> None", &DrawModelWiresEx);
    _bind(vm, mod, "DrawBoundingBox(box: BoundingBox, color: Color) -> None", &DrawBoundingBox);
    _bind(vm, mod, "DrawBillboard(camera: Camera, texture: Texture2D, position: vec3, size: float, tint: Color) -> None", &DrawBillboard);
    _bind(vm, mod, "DrawBillboardRec(camera: Camera, texture: Texture2D, source: Rectangle, position: vec3, size: vec2, tint: Color) -> None", &DrawBillboardRec);
    _bind(vm, mod, "DrawBillboardPro(camera: Camera, texture: Texture2D, source: Rectangle, position: vec3, up: vec3, size: vec2, origin: vec2, rotation: float, tint: Color) -> None", &DrawBillboardPro);
    _bind(vm, mod, "UploadMesh(mesh: 'Mesh_p', dynamic: bool) -> None", &UploadMesh);
    _bind(vm, mod, "UpdateMeshBuffer(mesh: Mesh, index: int, data: void_p, dataSize: int, offset: int) -> None", &UpdateMeshBuffer);
    _bind(vm, mod, "UnloadMesh(mesh: Mesh) -> None", &UnloadMesh);
    _bind(vm, mod, "DrawMesh(mesh: Mesh, material: Material, transform: Matrix) -> None", &DrawMesh);
    _bind(vm, mod, "DrawMeshInstanced(mesh: Mesh, material: Material, transforms: 'Matrix_p', instances: int) -> None", &DrawMeshInstanced);
    _bind(vm, mod, "ExportMesh(mesh: Mesh, fileName: str) -> bool", &ExportMesh);
    _bind(vm, mod, "GetMeshBoundingBox(mesh: Mesh) -> BoundingBox", &GetMeshBoundingBox);
    _bind(vm, mod, "GenMeshTangents(mesh: 'Mesh_p') -> None", &GenMeshTangents);
    _bind(vm, mod, "GenMeshPoly(sides: int, radius: float) -> Mesh", &GenMeshPoly);
    _bind(vm, mod, "GenMeshPlane(width: float, length: float, resX: int, resZ: int) -> Mesh", &GenMeshPlane);
    _bind(vm, mod, "GenMeshCube(width: float, height: float, length: float) -> Mesh", &GenMeshCube);
    _bind(vm, mod, "GenMeshSphere(radius: float, rings: int, slices: int) -> Mesh", &GenMeshSphere);
    _bind(vm, mod, "GenMeshHemiSphere(radius: float, rings: int, slices: int) -> Mesh", &GenMeshHemiSphere);
    _bind(vm, mod, "GenMeshCylinder(radius: float, height: float, slices: int) -> Mesh", &GenMeshCylinder);
    _bind(vm, mod, "GenMeshCone(radius: float, height: float, slices: int) -> Mesh", &GenMeshCone);
    _bind(vm, mod, "GenMeshTorus(radius: float, size: float, radSeg: int, sides: int) -> Mesh", &GenMeshTorus);
    _bind(vm, mod, "GenMeshKnot(radius: float, size: float, radSeg: int, sides: int) -> Mesh", &GenMeshKnot);
    _bind(vm, mod, "GenMeshHeightmap(heightmap: Image, size: vec3) -> Mesh", &GenMeshHeightmap);
    _bind(vm, mod, "GenMeshCubicmap(cubicmap: Image, cubeSize: vec3) -> Mesh", &GenMeshCubicmap);
    _bind(vm, mod, "LoadMaterials(fileName: str, materialCount: int_p) -> 'Material_p'", &LoadMaterials);
    _bind(vm, mod, "LoadMaterialDefault() -> Material", &LoadMaterialDefault);
    _bind(vm, mod, "IsMaterialReady(material: Material) -> bool", &IsMaterialReady);
    _bind(vm, mod, "UnloadMaterial(material: Material) -> None", &UnloadMaterial);
    _bind(vm, mod, "SetMaterialTexture(material: 'Material_p', mapType: int, texture: Texture2D) -> None", &SetMaterialTexture);
    _bind(vm, mod, "SetModelMeshMaterial(model: 'Model_p', meshId: int, materialId: int) -> None", &SetModelMeshMaterial);
    _bind(vm, mod, "LoadModelAnimations(fileName: str, animCount: int_p) -> 'ModelAnimation_p'", &LoadModelAnimations);
    _bind(vm, mod, "UpdateModelAnimation(model: Model, anim: ModelAnimation, frame: int) -> None", &UpdateModelAnimation);
    _bind(vm, mod, "UnloadModelAnimation(anim: ModelAnimation) -> None", &UnloadModelAnimation);
    _bind(vm, mod, "UnloadModelAnimations(animations: 'ModelAnimation_p', animCount: int) -> None", &UnloadModelAnimations);
    _bind(vm, mod, "IsModelAnimationValid(model: Model, anim: ModelAnimation) -> bool", &IsModelAnimationValid);
    _bind(vm, mod, "CheckCollisionSpheres(center1: vec3, radius1: float, center2: vec3, radius2: float) -> bool", &CheckCollisionSpheres);
    _bind(vm, mod, "CheckCollisionBoxes(box1: BoundingBox, box2: BoundingBox) -> bool", &CheckCollisionBoxes);
    _bind(vm, mod, "CheckCollisionBoxSphere(box: BoundingBox, center: vec3, radius: float) -> bool", &CheckCollisionBoxSphere);
    _bind(vm, mod, "GetRayCollisionSphere(ray: Ray, center: vec3, radius: float) -> RayCollision", &GetRayCollisionSphere);
    _bind(vm, mod, "GetRayCollisionBox(ray: Ray, box: BoundingBox) -> RayCollision", &GetRayCollisionBox);
    _bind(vm, mod, "GetRayCollisionMesh(ray: Ray, mesh: Mesh, transform: Matrix) -> RayCollision", &GetRayCollisionMesh);
    _bind(vm, mod, "GetRayCollisionTriangle(ray: Ray, p1: vec3, p2: vec3, p3: vec3) -> RayCollision", &GetRayCollisionTriangle);
    _bind(vm, mod, "GetRayCollisionQuad(ray: Ray, p1: vec3, p2: vec3, p3: vec3, p4: vec3) -> RayCollision", &GetRayCollisionQuad);
    _bind(vm, mod, "InitAudioDevice() -> None", &InitAudioDevice);
    _bind(vm, mod, "CloseAudioDevice() -> None", &CloseAudioDevice);
    _bind(vm, mod, "IsAudioDeviceReady() -> bool", &IsAudioDeviceReady);
    _bind(vm, mod, "SetMasterVolume(volume: float) -> None", &SetMasterVolume);
    _bind(vm, mod, "GetMasterVolume() -> float", &GetMasterVolume);
    _bind(vm, mod, "LoadWave(fileName: str) -> Wave", &LoadWave);
    _bind(vm, mod, "LoadWaveFromMemory(fileType: str, fileData: uchar_p, dataSize: int) -> Wave", &LoadWaveFromMemory);
    _bind(vm, mod, "IsWaveReady(wave: Wave) -> bool", &IsWaveReady);
    _bind(vm, mod, "LoadSound(fileName: str) -> Sound", &LoadSound);
    _bind(vm, mod, "LoadSoundFromWave(wave: Wave) -> Sound", &LoadSoundFromWave);
    _bind(vm, mod, "LoadSoundAlias(source: Sound) -> Sound", &LoadSoundAlias);
    _bind(vm, mod, "IsSoundReady(sound: Sound) -> bool", &IsSoundReady);
    _bind(vm, mod, "UpdateSound(sound: Sound, data: void_p, sampleCount: int) -> None", &UpdateSound);
    _bind(vm, mod, "UnloadWave(wave: Wave) -> None", &UnloadWave);
    _bind(vm, mod, "UnloadSound(sound: Sound) -> None", &UnloadSound);
    _bind(vm, mod, "UnloadSoundAlias(alias: Sound) -> None", &UnloadSoundAlias);
    _bind(vm, mod, "ExportWave(wave: Wave, fileName: str) -> bool", &ExportWave);
    _bind(vm, mod, "ExportWaveAsCode(wave: Wave, fileName: str) -> bool", &ExportWaveAsCode);
    _bind(vm, mod, "PlaySound(sound: Sound) -> None", &PlaySound);
    _bind(vm, mod, "StopSound(sound: Sound) -> None", &StopSound);
    _bind(vm, mod, "PauseSound(sound: Sound) -> None", &PauseSound);
    _bind(vm, mod, "ResumeSound(sound: Sound) -> None", &ResumeSound);
    _bind(vm, mod, "IsSoundPlaying(sound: Sound) -> bool", &IsSoundPlaying);
    _bind(vm, mod, "SetSoundVolume(sound: Sound, volume: float) -> None", &SetSoundVolume);
    _bind(vm, mod, "SetSoundPitch(sound: Sound, pitch: float) -> None", &SetSoundPitch);
    _bind(vm, mod, "SetSoundPan(sound: Sound, pan: float) -> None", &SetSoundPan);
    _bind(vm, mod, "WaveCopy(wave: Wave) -> Wave", &WaveCopy);
    _bind(vm, mod, "WaveCrop(wave: 'Wave_p', initSample: int, finalSample: int) -> None", &WaveCrop);
    _bind(vm, mod, "WaveFormat(wave: 'Wave_p', sampleRate: int, sampleSize: int, channels: int) -> None", &WaveFormat);
    _bind(vm, mod, "LoadWaveSamples(wave: Wave) -> float_p", &LoadWaveSamples);
    _bind(vm, mod, "UnloadWaveSamples(samples: float_p) -> None", &UnloadWaveSamples);
    _bind(vm, mod, "LoadMusicStream(fileName: str) -> Music", &LoadMusicStream);
    _bind(vm, mod, "LoadMusicStreamFromMemory(fileType: str, data: uchar_p, dataSize: int) -> Music", &LoadMusicStreamFromMemory);
    _bind(vm, mod, "IsMusicReady(music: Music) -> bool", &IsMusicReady);
    _bind(vm, mod, "UnloadMusicStream(music: Music) -> None", &UnloadMusicStream);
    _bind(vm, mod, "PlayMusicStream(music: Music) -> None", &PlayMusicStream);
    _bind(vm, mod, "IsMusicStreamPlaying(music: Music) -> bool", &IsMusicStreamPlaying);
    _bind(vm, mod, "UpdateMusicStream(music: Music) -> None", &UpdateMusicStream);
    _bind(vm, mod, "StopMusicStream(music: Music) -> None", &StopMusicStream);
    _bind(vm, mod, "PauseMusicStream(music: Music) -> None", &PauseMusicStream);
    _bind(vm, mod, "ResumeMusicStream(music: Music) -> None", &ResumeMusicStream);
    _bind(vm, mod, "SeekMusicStream(music: Music, position: float) -> None", &SeekMusicStream);
    _bind(vm, mod, "SetMusicVolume(music: Music, volume: float) -> None", &SetMusicVolume);
    _bind(vm, mod, "SetMusicPitch(music: Music, pitch: float) -> None", &SetMusicPitch);
    _bind(vm, mod, "SetMusicPan(music: Music, pan: float) -> None", &SetMusicPan);
    _bind(vm, mod, "GetMusicTimeLength(music: Music) -> float", &GetMusicTimeLength);
    _bind(vm, mod, "GetMusicTimePlayed(music: Music) -> float", &GetMusicTimePlayed);
    _bind(vm, mod, "LoadAudioStream(sampleRate: int, sampleSize: int, channels: int) -> AudioStream", &LoadAudioStream);
    _bind(vm, mod, "IsAudioStreamReady(stream: AudioStream) -> bool", &IsAudioStreamReady);
    _bind(vm, mod, "UnloadAudioStream(stream: AudioStream) -> None", &UnloadAudioStream);
    _bind(vm, mod, "UpdateAudioStream(stream: AudioStream, data: void_p, frameCount: int) -> None", &UpdateAudioStream);
    _bind(vm, mod, "IsAudioStreamProcessed(stream: AudioStream) -> bool", &IsAudioStreamProcessed);
    _bind(vm, mod, "PlayAudioStream(stream: AudioStream) -> None", &PlayAudioStream);
    _bind(vm, mod, "PauseAudioStream(stream: AudioStream) -> None", &PauseAudioStream);
    _bind(vm, mod, "ResumeAudioStream(stream: AudioStream) -> None", &ResumeAudioStream);
    _bind(vm, mod, "IsAudioStreamPlaying(stream: AudioStream) -> bool", &IsAudioStreamPlaying);
    _bind(vm, mod, "StopAudioStream(stream: AudioStream) -> None", &StopAudioStream);
    _bind(vm, mod, "SetAudioStreamVolume(stream: AudioStream, volume: float) -> None", &SetAudioStreamVolume);
    _bind(vm, mod, "SetAudioStreamPitch(stream: AudioStream, pitch: float) -> None", &SetAudioStreamPitch);
    _bind(vm, mod, "SetAudioStreamPan(stream: AudioStream, pan: float) -> None", &SetAudioStreamPan);
    _bind(vm, mod, "SetAudioStreamBufferSizeDefault(size: int) -> None", &SetAudioStreamBufferSizeDefault);

    CodeObject_ co = vm->compile("from linalg import *", "raylib.py", EXEC_MODE);
    vm->_exec(co, mod);
    mod->attr().set("Quaternion", mod->attr("vec4"));
    mod->attr().set("Quaternion_p", mod->attr("vec4_p"));
    mod->attr().set("Texture2D", mod->attr("Texture"));
    mod->attr().set("Texture2D_p", mod->attr("Texture_p"));
    mod->attr().set("TextureCubemap", mod->attr("Texture"));
    mod->attr().set("TextureCubemap_p", mod->attr("Texture_p"));
    mod->attr().set("RenderTexture2D", mod->attr("RenderTexture"));
    mod->attr().set("RenderTexture2D_p", mod->attr("RenderTexture_p"));
    mod->attr().set("Camera", mod->attr("Camera3D"));
    mod->attr().set("Camera_p", mod->attr("Camera3D_p"));
}
}  // namespace pkpy