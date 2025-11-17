# algoritmos_group01_tf
Mi proyecto de algoritmos

Integrantes :

- Santiago Villamar
- Sebastián Castillo
- Lindsey Yorget

Casos:

Mundo IA – La Máquina Suprema

Diagnóstico con Inteligencia Artificial :
 El uso de la inteligencia artificial en el ámbito médico ha transformado la forma en que se realizan diagnósticos. Los algoritmos de aprendizaje automático permiten procesar imágenes radiológicas con gran precisión, logrando en algunos casos detectar enfermedades en etapas tempranas. Esto representa un beneficio importante para los pacientes, ya que aumenta la probabilidad de un tratamiento oportuno. Sin embargo, la dependencia de la IA plantea riesgos, como la posibilidad de falsos positivos o negativos que pueden afectar la salud de los pacientes. Además, al no existir criterio humano en el proceso, la máquina no considera factores contextuales que podrían ser relevantes para el diagnóstico.
 En el videojuego, este caso puede inspirar un recurso denominado “escáner IA”, que otorga ventajas al jugador al identificar amenazas o problemas, pero que a veces falla, obligando al protagonista a cuestionar si debe confiar ciegamente en la máquina.
 (Revista Vitalia, 2023)

 Vehículos autónomos :
Los automóviles autónomos, desarrollados por empresas como Tesla y Waymo, son un ejemplo de cómo la inteligencia artificial puede tomar decisiones en tiempo real para controlar el tránsito. Estos sistemas utilizan sensores y algoritmos avanzados para interpretar el entorno y decidir acciones como frenar, girar o acelerar. Si bien su eficiencia puede reducir la tasa de accidentes causados por errores humanos, también existen riesgos asociados a fallas de programación o a situaciones imprevistas que la máquina no puede resolver adecuadamente. De hecho, algunos accidentes ocurridos en pruebas han generado debates sobre la responsabilidad legal en caso de fallos.
En el videojuego, este caso puede inspirar un enemigo “auto autónomo” que se mueve de manera rígida y predecible, representando la eficiencia de la máquina, pero también la falta de libertad y adaptabilidad.
(Revista de Iniciación Científica UTP, 2022)

Mundo Humano – La Luz del Pensamiento

Decisiones judiciales :
En el campo del derecho, muchas decisiones siguen estando exclusivamente en manos de jueces y magistrados. A diferencia de los algoritmos, los jueces aplican su criterio interpretando normas, evaluando pruebas y considerando el contexto social. Este enfoque aporta creatividad e interpretación humana, pero también implica vulnerabilidad, ya que las decisiones pueden estar influenciadas por sesgos, emociones o corrupción. La justicia basada únicamente en humanos pone de relieve tanto la riqueza del juicio crítico como sus limitaciones.
En el videojuego, este caso puede inspirar un personaje juez que actúe como aliado o adversario dependiendo de la situación, mostrando cómo las decisiones humanas pueden ser justas o arbitrarias según el contexto.

Toma de decisiones en psicología :
En la psicología clínica, los profesionales deben elegir el tipo de terapia más adecuada para cada paciente basándose en entrevistas, observación y experiencia previa. Estas decisiones son complejas, pues dependen de factores emocionales, sociales y personales que no siempre son evidentes. La creatividad del psicólogo permite adaptar el tratamiento, pero también existe vulnerabilidad, ya que una mala interpretación puede llevar a errores en la intervención. La ausencia de apoyo tecnológico hace que el peso recaiga totalmente en la intuición y formación del especialista.
En el videojuego, este caso puede inspirar un aliado “psicólogo” que aconseja al protagonista, pero cuyos consejos pueden ser útiles o confusos, obligando al jugador a reflexionar antes de actuar.
(Revista Perspectivas Psicológicas, UASD, 2021)

Mundo Colaborativo – El Puente del Futuro

Cirugías asistidas por IA :
 El sistema quirúrgico Da Vinci representa un modelo de colaboración entre humanos e inteligencia artificial. En estas cirugías, el robot realiza movimientos de gran precisión, pero siempre bajo el control y supervisión de un cirujano. Esta combinación permite operaciones más seguras y menos invasivas, aunque con un alto costo y la necesidad de un entrenamiento especializado. El caso muestra cómo la colaboración puede potenciar los resultados, pero también revela la incertidumbre que surge cuando la tecnología se convierte en un intermediario de la vida humana.
 En el videojuego, este caso puede inspirar un aliado “robot quirúrgico” que ejecuta tareas precisas, pero que solo funciona correctamente si el jugador da las órdenes adecuadas, reforzando la importancia de la coordinación entre humano y máquina.
 (Universidad Europea, 2023)

Periodismo con IA :
 En el ámbito de la comunicación, el Washington Post implementó la IA “Heliograf” para redactar noticias breves sobre elecciones o resultados deportivos. La máquina generaba borradores rápidos, mientras que los periodistas humanos revisaban, editaban y añadían contexto. Esta colaboración permitió aumentar la productividad, pero también generó debates sobre la calidad y autenticidad de la información producida. El caso refleja cómo la unión entre IA y humanos puede generar eficiencia, aunque siempre con la incertidumbre de hasta qué punto debe confiar en la máquina.
 En el videojuego, este caso puede inspirar un recurso de “información rápida” que el jugador recibe de la IA, pero que debe verificar antes de usar, mostrando el valor del pensamiento crítico frente a datos automáticos.
 (Revista Nueva Época, 2023)


 ---
title: Diagrama de clases 
---
```mermaid
classDiagram

Entidad <|-- Jugador
Entidad <|-- Auto
Entidad <|-- Secretario
Entidad <|-- Piezas

Controlador *-- ArregloRecursos
Controlador *-- ArregloEnemigos
Controlador *-- Jugador

ArregloEnemigos *-- Auto
ArregloEnemigos *-- Secretario

ArregloRecursos *-- Piezas

class Controlador {
    -arrPieza : ArregloRecursos*
    -arrEnemigos : ArregloEnemigos*
    -jugador : Jugador*
    -nivelActual : int
    -piezasObjetivo : int
    -lastSpawnMs : unsigned long
    -spawnIntervalMs : int
    -maxEnemigosNivel : int
    -alternarTipo : bool

    +configurarNivel() void
    +intentarSpawnear() void
    +jugarNivel() bool
    +mover() void
    +mostrarVidasJugador() void
    +run() void
}
class Entidad {
    #x : int
    #y : int
    #dx : int
    #dy : int
    #ancho : int
    #alto : int

    +mostrar() void
    +mover() void
    +borrar() void
    +intersectar(Entidad* b) bool
}
class Jugador {
    -vidas : int
    -spawnX : int
    -spawnY : int

    +mostrar() void
    +mover() void
    +borrar() void
    +setSpawn() void
    +puedeSerGolpeado() bool
    +recibirGolpe() bool
    +getVidas() int
    +setVidas() void
}

class Auto {
    +mostrar() void
    +borrar() void
    +mover() void
}

class Secretario {
    +mostrar() void
    +borrar() void
    +mover() void
}

class Piezas {
    +mostrar() void
    +borrar() void
    +mover() void
}
class ArregloEnemigos {
    -arrE1 : vector~Auto*~
    -arrE2 : vector~Secretario*~

    +agregarEnemigo1() void
    +agregarEnemigo2() void
    +actualizarTodos() void
    +verificarCollisionAutos(Jugador* jugador) void
    +verificarCollisionSecretario(Jugador* jugador) void
    +cantidadAutos() int
    +cantidadSecretarios() int
    +totalEnemigos() int
    +reiniciar() void
}

class ArregloRecursos {
    -piezas : vector~Pieza*~

    +agregar() void
    +borrar() void
    +mostrarTodos() void
    +collisionPiezas(Jugador* jugador) void
    +getPiezas() int
    +reiniciar() void
}
