// for binding to other languages

typedef enum {
    CLASS_CHARMODEL
} SnekClassType;

typedef struct {
    void* data;
    SnekClassType type;
} SnekClass;

#ifdef __cplusplus
extern "C" {
#endif

SnekClass create_snek3d_class(SnekClassType type);

#ifdef __cplusplus
}
#endif
