

/**
 * @file iM3Lib_Preferences.h
 *
 * @brief BriefDescription
 *
 * @author Oscar Barciela
 * Contact: osbarciela@gmail.com
 */

#include <Arduino.h>
#include <Preferences.h>
#include <vector>

#ifndef __IM3PRE__
#define __IM3PRE__

/**
 * ClassDescription
 */
class iM3Lib_Preferences
{
public:
    iM3Lib_Preferences();

    template <typename T>
    void updatePreference(Preferences &prefs, const char *key, T value);
    void updateNetworkPreference(Preferences &prefs, const char *prefix, const IPAddress &ip);
    void updateVectorPreferences(Preferences &prefs, const std::vector<int> &container, const String &prefix);

    // Funciones auxiliares para obtener preferencias
    bool getPreference(Preferences &prefs, const char *key, bool defaultValue);
    int getPreference(Preferences &prefs, const char *key, int defaultValue);
    float getPreference(Preferences &prefs, const char *key, float defaultValue);
    String getPreference(Preferences &prefs, const char *key, const String &defaultValue);
    unsigned int getPreference(Preferences &prefs, const char *key, unsigned int defaultValue);
    long unsigned int getPreference(Preferences &prefs, const char *key, long unsigned int defaultValue);

    // Funciones auxiliares para establecer preferencias
    void putPreference(Preferences &prefs, const char *key, bool value);
    void putPreference(Preferences &prefs, const char *key, int value);
    void putPreference(Preferences &prefs, const char *key, float value);
    void putPreference(Preferences &prefs, const char *key, const String &value);
    void putPreference(Preferences &prefs, const char *key, unsigned int value);
    void putPreference(Preferences &prefs, const char *key, long unsigned int value);

private:
    Preferences preferences;
};

// Obligatorio definir esta función en el .h porque las funciones template deben estar disponibles en el arranque.

/**
 * @brief Actualiza una preferencia almacenada en la memoria no volátil (NVS).
 *
 * Esta función compara el valor actual de una preferencia con un nuevo valor proporcionado.
 * Si los valores son diferentes, actualiza la preferencia en la NVS y registra el cambio.
 * Si los valores son iguales, indica que la preferencia ya está actualizada. Esta función es genérica
 * para cualquier tipo de preferencia (int, bool, String, etc.).
 *
 * @tparam T El tipo de la preferencia (por ejemplo, int, bool, String).
 * @param key La clave de la preferencia en la NVS.
 * @param value El nuevo valor de la preferencia.
 */
template <typename T>
void iM3Lib_Preferences::updatePreference(Preferences &prefs, const char *key, T value)
{
    T currentValue = getPreference(prefs, key, T());
    Serial.print("Current value for key ");
    Serial.print(key);
    Serial.print(": ");
    Serial.println(currentValue);
    Serial.print("New value: ");
    Serial.println(value);

    if (currentValue != value)
    {
        putPreference(prefs, key, value);
        Serial.print("Updated value for key ");
        Serial.print(key);
        Serial.println(" successfully.");
    }
    else
    {
        Serial.print("Value for key ");
        Serial.print(key);
        Serial.println(" is already up-to-date.");
    }
}

#endif
