
#include "iM3Lib_Preferences.h"

iM3Lib_Preferences::iM3Lib_Preferences()
{
}

/**
 * @brief Actualiza las preferencias de red almacenadas en la memoria no volátil (NVS).
 *
 * Esta función toma una dirección IP y un prefijo, y actualiza las preferencias de red
 * correspondientes en la NVS. Cada octeto de la dirección IP se almacena bajo una clave
 * generada combinando el prefijo y el índice del octeto.
 *
 * @param prefix El prefijo utilizado para las claves de las preferencias en NVS.
 * @param ip La dirección IP que se va a almacenar.
 */
void iM3Lib_Preferences::updateNetworkPreference(Preferences &prefs, const char *prefix, const IPAddress &ip)
{
    char key[10];
    for (int i = 0; i < 4; ++i)
    {
        snprintf(key, sizeof(key), "%s%d", prefix, i + 1);
        updatePreference(prefs, key, ip[i]);
    }
}

/**
 * @brief Actualiza las preferencias con los valores de un vector.
 *
 * Esta función almacena el número de elementos en el vector y luego almacena cada elemento del vector en las preferencias.
 * El prefijo proporcionado se utiliza para formar las claves de las preferencias. La última "s" del prefijo se elimina antes
 * de formar las claves para cada elemento del vector.
 *
 * @param prefs Referencia a un objeto de preferencias donde se almacenarán los valores.
 * @param container Referencia a un vector de enteros cuyos valores se almacenarán en las preferencias.
 * @param prefix Prefijo utilizado para formar las claves de las preferencias.
 */
void iM3Lib_Preferences::updateVectorPreferences(Preferences &prefs, const std::vector<int> &container, const String &prefix)
{
    // Almacenar el número de elementos en el vector
    String numKey = "num_" + prefix;
    updatePreference(prefs, numKey.c_str(), static_cast<int>(container.size()));

    // Eliminar la última "s" del prefijo
    String baseKey = prefix.substring(0, prefix.length() - 1);

    // Almacenar cada elemento del vector
    for (size_t i = 0; i < container.size(); ++i)
    {
        String key = baseKey + String(i);
        updatePreference(prefs, key.c_str(), container[i]);
    }
}

/**
 * @brief Obtiene una preferencia almacenada en la memoria no volátil (NVS) como un valor booleano.
 *
 * @param key La clave de la preferencia en la NVS.
 * @param defaultValue El valor por defecto a devolver si la preferencia no existe.
 * @return El valor booleano de la preferencia.
 */
bool iM3Lib_Preferences::getPreference(Preferences &prefs, const char *key, bool defaultValue)
{
    Serial.println("Getting preference bool " + String(key));
    return prefs.getBool(key, defaultValue);
}

/**
 * @brief Obtiene una preferencia almacenada en la memoria no volátil (NVS) como un valor entero.
 *
 * @param key La clave de la preferencia en la NVS.
 * @param defaultValue El valor por defecto a devolver si la preferencia no existe.
 * @return El valor entero de la preferencia.
 */
int iM3Lib_Preferences::getPreference(Preferences &prefs, const char *key, int defaultValue)
{
    Serial.println("Getting preference int " + String(key));
    return prefs.getInt(key, defaultValue);
}

/**
 * @brief Obtiene una preferencia almacenada en la memoria no volátil (NVS) como un valor flotante.
 *
 * @param key La clave de la preferencia en la NVS.
 * @param defaultValue El valor por defecto a devolver si la preferencia no existe.
 * @return El valor flotante de la preferencia.
 */
float iM3Lib_Preferences::getPreference(Preferences &prefs, const char *key, float defaultValue)
{
    Serial.println("Getting preference float " + String(key));
    return prefs.getFloat(key, defaultValue);
}

/**
 * @brief Obtiene una preferencia almacenada en la memoria no volátil (NVS) como una cadena de texto.
 *
 * @param key La clave de la preferencia en la NVS.
 * @param defaultValue El valor por defecto a devolver si la preferencia no existe.
 * @return El valor de la preferencia como una cadena de texto.
 */
String iM3Lib_Preferences::getPreference(Preferences &prefs, const char *key, const String &defaultValue)
{
    Serial.println("Getting preference String " + String(key));
    return prefs.getString(key, defaultValue);
}

/**
 * @brief Obtiene una preferencia almacenada en la memoria no volátil (NVS) como un valor entero sin signo.
 *
 * @param key La clave de la preferencia en la NVS.
 * @param defaultValue El valor por defecto a devolver si la preferencia no existe.
 * @return El valor entero sin signo de la preferencia.
 */
unsigned int iM3Lib_Preferences::getPreference(Preferences &prefs, const char *key, unsigned int defaultValue)
{
    Serial.println("Getting preference UInt " + String(key));
    return prefs.getUInt(key, defaultValue);
}

/**
 * @brief Obtiene una preferencia almacenada en la memoria no volátil (NVS) como un valor largo sin signo.
 *
 * @param key La clave de la preferencia en la NVS.
 * @param defaultValue El valor por defecto a devolver si la preferencia no existe.
 * @return El valor largo sin signo de la preferencia.
 */
long unsigned int iM3Lib_Preferences::getPreference(Preferences &prefs, const char *key, long unsigned int defaultValue)
{
    Serial.println("Getting preference ULong " + String(key));
    return prefs.getULong(key, defaultValue);
}

/**
 * @brief Almacena una preferencia en la memoria no volátil (NVS) como un valor booleano.
 *
 * @param key La clave de la preferencia en la NVS.
 * @param value El valor booleano a almacenar.
 */
void iM3Lib_Preferences::putPreference(Preferences &prefs, const char *key, bool value)
{
    Serial.println("Putting preference bool " + String(key));
    prefs.putBool(key, value);
}

/**
 * @brief Almacena una preferencia en la memoria no volátil (NVS) como un valor entero.
 *
 * @param key La clave de la preferencia en la NVS.
 * @param value El valor entero a almacenar.
 */
void iM3Lib_Preferences::putPreference(Preferences &prefs, const char *key, int value)
{
    Serial.println("Putting preference int " + String(key));
    prefs.putInt(key, value);
}

/**
 * @brief Almacena una preferencia en la memoria no volátil (NVS) como un valor flotante.
 *
 * @param key La clave de la preferencia en la NVS.
 * @param value El valor flotante a almacenar.
 */
void iM3Lib_Preferences::putPreference(Preferences &prefs, const char *key, float value)
{
    Serial.println("Putting preference float " + String(key));
    prefs.putFloat(key, value);
}

/**
 * @brief Almacena una preferencia en la memoria no volátil (NVS) como una cadena de texto.
 *
 * @param key La clave de la preferencia en la NVS.
 * @param value El valor de la cadena de texto a almacenar.
 */
void iM3Lib_Preferences::putPreference(Preferences &prefs, const char *key, const String &value)
{
    Serial.println("Putting preference String " + String(key));
    prefs.putString(key, value);
}

/**
 * @brief Almacena una preferencia en la memoria no volátil (NVS) como un valor entero sin signo.
 *
 * @param key La clave de la preferencia en la NVS.
 * @param value El valor entero sin signo a almacenar.
 */
void iM3Lib_Preferences::putPreference(Preferences &prefs, const char *key, unsigned int value)
{
    Serial.println("Putting preference uint " + String(key));
    prefs.putUInt(key, value);
}

/**
 * @brief Almacena una preferencia en la memoria no volátil (NVS) como un valor largo sin signo.
 *
 * @param key La clave de la preferencia en la NVS.
 * @param value El valor largo sin signo a almacenar.
 */
void iM3Lib_Preferences::putPreference(Preferences &prefs, const char *key, long unsigned int value)
{
    Serial.println("Putting preference ulong " + String(key));
    prefs.putULong(key, value);
}
