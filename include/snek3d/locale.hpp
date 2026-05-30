
#include <vector>

namespace Snek3D {
    struct LangKey {
        const char* key;
        const char* value;
    };
    struct Locale {
        const char* name;
        std::vector<LangKey> keys;
        const char* tr(const char* key);
    };
    void append_locale(Locale* locale);
    Locale* get_current_locale();
    void set_current_localestr(const char* name);
    const char* get_current_localestr();
    const char* tr(const char* key);
    Locale* get_locale_by_name(const char* name);
}
