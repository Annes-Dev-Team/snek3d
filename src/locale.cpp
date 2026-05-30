#include <cstring>
#include <snek3d/locale.hpp>
#include <vector>

std::vector<Snek3D::Locale*> locales = {};
Snek3D::Locale* current_locale;
const char* current_str;
void Snek3D::append_locale(Snek3D::Locale* locale) {
    locales.push_back(locale);
}
Snek3D::Locale* Snek3D::get_current_locale() {
    return current_locale;
}
const char* Snek3D::get_current_localestr() {
    return current_str;
}
const char* Snek3D::tr(const char* key) {
    auto i = Snek3D::get_locale_by_name(current_str);
    auto op = i->tr(key);
    if (op) {
        return op;
    }
    
    return key;
}

const char* Snek3D::Locale::tr(const char* key) {
    for (auto i : keys) {
        if (strcmp(i.key, key) == 0) {
            return i.value;
        }
    }
    return nullptr;
}

void Snek3D::set_current_localestr(const char* name) {
    current_str = name;
}
Snek3D::Locale* Snek3D::get_locale_by_name(const char* name) {
    for (auto i : locales) {
        if (strcmp(i->name, name) == 0) {
            return i;
        }
    }
    return nullptr;
}
