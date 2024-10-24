# Proyecto 2 - Juan Carlos Díaz y Santiago Figueroa

# Cambios en `GestorCsv.cpp`

## Descripción General
El archivo `GestorCsv.cpp` se actualizó para mejorar la lectura de archivos CSV, reducir la complejidad del código y hacerlo más adaptable a diferentes formatos. Se enfocó en unificar funciones similares, optimizar la detección de columnas, y mejorar el manejo de errores.

## Cambios Clave

### 1. **`leerProgramasCsv`**
   - Ahora usa un delimitador (`';'`) para extraer todos los campos en una línea.
   - Se cambió el tipo de retorno a `vector<string>` para una mayor flexibilidad en la lectura de datos.

### 2. **Nueva Función: `contarColumnas`**
   - Cuenta automáticamente el número de columnas en la primera línea del archivo, facilitando la adaptabilidad a diferentes estructuras de CSV.

### 3. **`leerArchivoUnificado`**
   - Combina las funciones previas (`leerArchivoPrimera` y `leerArchivoSegunda`) en una sola, reduciendo la redundancia.
   - Se ajusta dinámicamente al número de columnas y mejora el filtrado de códigos SNIES.

### 4. **`leerArchivo`**
   - Simplificación de la estructura de control y manejo más claro de las columnas SNIES.
   - Se mejoró el manejo de errores y se añadieron comentarios más detallados.

### 5. **Funciones de Escritura (`crearArchivo`, `crearArchivoBuscados`, `crearArchivoExtra`)**
   - Se unificó el manejo de los encabezados y la impresión de filas.
   - Se mejoró la consistencia y la claridad en la creación de archivos CSV.

# Cambios en `SNIESController.cpp`

## Descripción General
El archivo `SNIESController.cpp` se ha modificado para mejorar la organización del código, reducir su complejidad, y optimizar el manejo de los datos CSV. Se han unificado funciones y agregado validaciones para mejorar la estabilidad y adaptabilidad del sistema.

## Cambios Clave

### 1. **Constructor de `SNIESController`**
   - Se eliminó el paso de inicialización con rutas de archivos, para que las constantes de ruta sean gestionadas desde un archivo de configuración (`settings.h`).
   - Se añadió un constructor vacío para mayor flexibilidad.

### 2. **Función `procesarDatosCsv`**
   - Se simplificó la lógica de lectura de CSV al usar la nueva función `leerArchivoUnificado` de `GestorCsv`.
   - Se agregaron controles de conversión de datos (`stoi`), para manejar posibles errores de conversión de forma más robusta.
   - Se unificaron las funciones de lectura por año para evitar duplicación de código.
   - Ahora se utiliza un vector para manejar la conversión de datos SNIES de `string` a `int`.

### 3. **Lectura Unificada de Datos**
   - Se implementó la función `leerArchivoUnificado`, reemplazando las funciones previas (`leerArchivoPrimera`, `leerArchivoSegunda`, etc.) para reducir la redundancia y mejorar la estructura del código.

### 4. **Método `buscarProgramas`**
   - La búsqueda de programas académicos se mantuvo, pero se optimizó la iteración sobre el mapa `programasAcademicos`.
   - Se mejoró la claridad de las condiciones de búsqueda y la impresión de resultados.

### 5. **Función `cargarDatos`**
   - Se simplificó la creación de objetos `ProgramaAcademico` y `Consolidado` al agregar validación de columnas desde la primera fila (encabezados).
   - Se agregó un mapa para identificar las posiciones de las columnas, lo que permite manejar dinámicamente la estructura del CSV.

### 6. **Función `calcularDatosExtra`**
   - Se redujo la lógica compleja y se organizó en secciones más claras para el cálculo de la suma de estudiantes matriculados, el diferencial porcentual de NEOS, y programas sin NEOS.
   - Se simplificó la creación de la matriz final de resultados, mejorando la legibilidad del código.

### 7. **Manejo de Errores**
   - Se agregaron bloques `try-catch` para manejar errores de conversión de datos, lo que mejora la estabilidad del programa.
   - Se añadió la validación de datos antes de realizar conversiones, reduciendo el riesgo de excepciones inesperadas.

## Mejoras Generales
   - **Reducción de Complejidad:** Se eliminaron bucles y estructuras de control redundantes, lo que facilitó la comprensión del flujo del código.
   - **Adaptabilidad:** Ahora el sistema es más adaptable a cambios en la estructura de los archivos CSV, gracias al uso de funciones de lectura unificada y validación de encabezados.
  
   # Cambios en `view.h`, `ProgramaAcademico.h` y `consolidado.h`

## Descripción General
Se realizaron mejoras significativas en los archivos `view.h` y `ProgramaAcademico.h` para optimizar la gestión de datos, mejorar la claridad del código, y facilitar su integración con otros componentes del sistema. A continuación, se describen los cambios clave realizados en cada archivo.

### Cambios Clave
- **Nueva Estructura para el Cálculo de Datos:**
  - Se ajustaron los parámetros de entrada de las funciones para recibir objetos `ProgramaAcademico` y `Consolidado`, lo que mejora la cohesión y reduce la dependencia de variables globales.
    - Se añadieron métodos de impresión que formatean los resultados en tablas, separando los encabezados y los datos, lo que mejora la experiencia del usuario
    - Se declararon variables necesarias para el funcionamiento del proyecto
Las mejoras en `view.h` y `ProgramaAcademico.h` permiten un manejo más eficiente de los datos, una mejor integración entre módulos, y una presentación más clara de los resultados en la interfaz de usuario. La nueva estructura de almacenamiento y las funciones rediseñadas simplifican el código y mejoran la escalabilidad del sistema.







