# Mejoras calidad de codigo
##### Primera entrega

### Principios GRASP
-Nos aseguramos que las operaciones relacionadas con los consolidados sean realizadas aquí. Por ejemplo, si se deben agregar o actualizar consolidados, la lógica reside dentro de esta clase.
Creamos métodos especializados para obtener estadísticas del programa (como tasas de graduación o crecimiento en matrículas), dejando los cálculos relacionados con los datos más detallados en la clase Consolidado.

-Aseguramos que las operaciones relacionadas con los consolidados sean realizadas aquí. Por ejemplo, si se deben agregar o actualizar consolidados, la lógica debe residir dentro de esta clase.
-Se crearon métodos especializados para obtener estadísticas del programa (como tasas de graduación o crecimiento en matrículas), dejando los cálculos relacionados con los datos más detallados en la clase Consolidado.

-Se eliminaron métodos que simplemente devuelvan atributos a menos que sean realmente necesarios, y en su lugar se puso métodos más relevantes, como obtenerTasaAdmitidos() o obtenerTasaGraduados() para un mayor encapsulamiento.

