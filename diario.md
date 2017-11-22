** Pego aquí el diario mierder de The Nine porque ahora forma parte de este Multicart. Pegado el 20160805 **

20160701
========

Empezamos esto. Es para la Bit Bit Jam esa de los dales Fran, pero no sé si nos dará tiempo. De todos modos, vamos a hacer este juego. Se trata de la 9ª parte de Cheril. El concepto es muy sencillo, estas son las ideas:

- Vista genital.
- Enemigos tipo 7 (en principio), con generador.
- Al entrar en cada pantalla, si esta tiene generadores, en cuanto el personaje sale del borde se cierran las salidas.
- Las salidas vuelven a abrirse cuando todos los generadores han desaparecido.
- Hay una barra de energía que dice cuanto dispara Cheril. Cada vez que dispara decrece. Si se gasta, no se puede disparar.
- Cuando se gasta la barra de energía, aparece una recarga en forma de flor en la pantalla.
- Enemigos tipo 10, no son enemigos. Sólo caminan por la pantalla con la rutina de andador tontuelo. Están para estorbar. Si les damos, nos quita energía.
- En el mapeado habrá 9 musas (The Nine) a las que liberaremos al limpiar la pantalla en donde estén.
- Las musas son hotspots.
- Las llaves son hotspots.
- La flor es un objeto especial custom.

El motor lo voy a escribir de cero reaprovechando las rutinas, como siempre. Pensábamos usar como base el MK1, pero se nos ha quedado obsoleto. En Yun he rescrito muchas partes de MK1, pero seguía usando la neslib y el cc65 viejos. Para este proyecto, vamos con las últimas versiones. Está claro que reaprovecharé mucho código de Yun.

Tengo sábado y domingo para hacer esto. Hoy viernes no creo que pueda hacer nada más que planificar.

Hitos:

1.- Coger la paleta de "nes" de Aseprite y añadirla como alternativa en mkts.
2.- Me voy a atrever y voy a permitir cinco enemigos por pantalla, pero me cuidaré de parametrizarlo. Tengo que crear un enems.ene de prueba para una pantalla al menos con cinco enemigos (bueno, 4 + el tipo 10 de porculear).
3.- Rellenar con placeholders los gráficos que falten.
4.- compile.bat
5.- Mostrar mapa.
6.- Movimiento cheril.
7.- Con disparos.
8.- Enemigos tipo 7 y 10
9.- Colisiones
10.- Barra de energía y flor
11.- Cerrar la pantalla y desbloquearla
12.- Musas
...


Qué de cosas. Y yo con fiebre. Uf. ¿Dará tiempo? Ya dije antes que me da igual, que si no llegamos para la Jam lo hacemos tranquilamente, pero intentaré llegar. 

Creo que hoy no voy a dar para mucho más que para generar la paleta. Me encuentro francamente mal y tengo poco margen de siesta hoy.

~~

Hito 1: Paleta de Aseprite en MKTS
----------------------------------

La paleta tal cual en el archivo .gpl venía con orden mierder y he tenido que hacer fullerías capturando la pantalla en Aseprite, reordenando, y generando los códigos con un script. La implementación dentro de mkts tiene que ver con especificar "aseprite" en la linea de comandos. Con eso, todas las funciones de nes tomarán los valores de aseprite en lugar de los valores normales.

Podía haber dejado que la detección usase las dos paletas de forma indistinta, pero así me curo en salud.

Hito 2: enems.ene de prueba
---------------------------

Va a ser que mañana. Me encuentro fatal, solo quiero tirarme en la cama.

20160702
========

Vamos a por unos enemiguillos. Actualizo mapa y tilesets que hay material nuevo y me pongo al líow.

Hitos 3, 4, qué mal numerao, plátano balú.
------------------------------------------

Ya he apañao enemigos, montado el compile.bat. Ya tengo todos los gráficos, al menos temporales. Ahora tengo que escribir dos conversores nuevos:

- enexpmin.exe exporta enemigos rollo mínima expresión: 2 bytes por enemigo: T|A X|Y, con T = tipo, A = atributo, y X, Y dragones rosas sobre cielos que no entiendo. 
- rlebytemap.exe exporta los mapas de 128 tiles máximo con una mierda de compresión RLE que espero que me salve cierta parte culil. Se lee un byte, si bit 7=0 se pinta el tile correspondiente. Si bit 7=1 se pone a 0, se lee otro byte, y se pinta el tile tantas veces como diga el otro byte. Y ya. A ver si así bajo de 192 bytes por pantalla. Lo malo es que luego hay 2 bytes más del puntero a cada pantalla en el índice, pero la vida es dura y con venas.

Voy al lío. No me da tiempo ni de coña. Estoy lento, lentisimo.

20160705
========

Al final no hubo cojones. No hubo siestas largas, yo estaba febril, lento, y todo me salió mal. Lo terminaremos por nuestra cuenta, eso sí. En este tiempo está todo hecho hasta el hito 8. Luego vendrán las colisiones, pero por el momento estoy resolviendo un cambio ágil de pantalla. Apuntado me dejo, para el final, introducir alguna forma de ordenar los sprites por coordenada Y para resolver el tema del pseudo-3D.

~

Ya se puede uno pasear por la pantalla y además los enemigos le pegan a Cheril. Ahora a contraatacar: hagamos que esas balas hagan púpares.

~

Estoy apuntando poco porque tengo poco rato y quiero aprovechar, pero ya dispara, los enemigos sufren, todo muere y tal, reacciones guays, las balas quitan energía, sale la flor para recargar, etc, etc.

Ahora voy a refinar la entrada a las pantallas para que se cierren cuando hay enemigos.

~~

En un día más o así se quedó perfecto, sin glitches, y listo para terminar. Se habló de hacer otra fase en un barco pirata pero salieron padrastros varios en el deo. Luego, a las semanas, se habló de no tirar esto y meterlo en un Multicart (esta vez, sin fliparse) y fue entonces cuando surgió el nuevo proyecto...

... Y terminamos flipándonos, como siempre.

20160729
========

Otra diversión ¡OTRA DIVERSIÓN! Miles de diversiones, siempre hay alguna diversión para los Mojones mientras tienen abiertos mil proyectos. ¡Así funciona esto! ¡Cómo mola! XD

En fin. 

Cheril the Nine es muy chulo pero es muy corto, así que para poder sacarlo sin que a mi se me levanten las venas de los brazos vamos a meterlo en un multicart aprovechando que ya tenemos otra vez bastante material descartado y diversa mierda que nos gustaría probar (tímidamente) pero que probablemente no pasaría de experimento.

Luego haré un briefing de lo que hay y de cómo podría usarse, pero quiero empezar con un port de Monono.

Antes, de todos modos, vamos a especificar unas cosas que cumplirán todas las ROMs incluidas salvo la de Cheril the Nine, a saber:

- Juegos con el motor MK1 (en realidad, la nueva encarnación para el cc65/neslib modernos que se empezó a adaptar para Cheril the Nine).
- COMM_POOL activo para comunicarse con el menú.
- Dos tilesets por ROM, compatibles, para poder cambiar uno por otro via COMM_POOL. Cada tileset podrá tener su juego de paletas (asignaciones de paletas, quiero referirme) y sus propios comportamientos, aunque al compartir mapa esto tendrá sus limitaciones (ya veremos).

La idea es poder tener al menos dos juegos distintos por ROM. Como voy a usar Mapper 113 tengo 16 CHR-ROM para usar si quiero hacer portadas en algunos juegos. En principio usaremos 4 ROMs + el menú + algo que esconda de las 8 que hay disponibles. 

MONONO
------

Monono es un juego chulo y raro y además lo hemos elegido porque el tileset ya estaba pasado de cuando, a principios de 2015, estuvimos haciendo las pruebas previas de scroll vertical para lo que luego se convertiría en un juego de Maritrini que, por el momento (y muy probablemente, para siempre) está abandonado y cogiendo polvo y pelusas.

El tema es que Monono es lo suficientemente antiguo como para que los recursos originales sean un desorden bestial - creo que no empezamos a tomarnos en serio de verdad toda esta mierda hasta que lanzamos la Churrera para todos. Monono es Horace Goes to the Tower espejado y con otro motor de movimiento. Conservo el .fmp con el mapa original de Monono para expandir y retocar, pero los enemigos no. En aquellos entonces la vuelta la hacía sobre el .h generado, misteriosamente, así que habrá que volver hasta el enems.ene de Horace, expandirlo, y luego voltearlo. 

Por lo pronto voy a hacer acopio de extrusores y mierdores, expando los assets, y luego comienzo clonando Cheril the Nine y sustituyendo / añadiendo las partes necesarias. Por lo pronto el mapa es de 16 tiles sin adornos (como es lógico en un juego de Churrera 3.99 pre-release), pero ahora no tengo claro si ocupará menos en packed RLE o en unpacked RLE, tengo que verlo. 

Antes que nada, a obtener un .map/.fmp y un .ene usables.

~~

Monono tiene tiles empujables mierder de los de toda la vida. No sé muy bien como gestionar esto. Tengo ocupados 6 (player) + 3 * 4 (enemigos) + 4 (hotspot) sprites en pantalla, fijos = 22. Creo que hay de sobra. Voy a mirar el mapa a ver donde hay más tiles empujables.

Esto mola porque 

1.- Me libera un tile en el tileset con el que jugar para el juego #2. 
2.- Los bloques que se empujan se moverán al pixel.
3.- Empujarlos contra una pared harán que se vayan al lado contrario.

No mola porque

4.- Hay que gestionar las colisiones con ellos. Laterales incluso.

Creo que esto debería funcionar así:

- Mover monono.
- Gestionar bloques. ¿colisiona monono con alguno? Mover bloque y ajustar monono, o solo ajustar monono si la colisión es vertical. 

Tengo que hacer que la colisión vertical "mande" sobre la horizontal, para que sólo se pueda empujar si colisionamos de verdad desde un lado, y no en diagonales raras que hagan cosas raras.

Pero son pajas, voy a ver de cuantos bloques por pantalla estamos hablando...

No. No es viable. Entre que no me quiero currar mucho esto y que hay pantallas que están llenas hasta los topes de cajas, creo que me quedo con las cajas mierder de toda la vida y a tomar por el ass. Voy a terminar de retocar el mapa para ver cuanto ocupa con las diferentes compresiones.

~~

El mapa de monono tiene 3x10 pantallas. Resultante = 48x120 tiles. 
Unpacked: 5760 bytes. 
Packed: 2880 bytes.
RLE Unpacked: 2458 bytes
RLE Packed: 2489 bytes. WTF.

Pues sí, amigos, misteriosamente ocupa menos si uso valores de a byte. Sea, porque así el código para pintar la pantalla es más compacto y rápido.

~~ 

Vamos a los enemigos. Primero expandiré, luego giraré. Y seguro que los hotspots se van a tomar por culo, pero eso ya me importa menos (no sé en qué punto de la historia cambién el formato de los hotspots en los archivos .ene, pero nunca atino!).

Al expandir he usado level0.bmp y level0.map para escribir en la cabecera del .ene, lo apuntow para acordarmew. W. Ah, y los hotspots al carajo. Están con dos bytes... A lo mejor es el momento de adaptar esto y hacerlo flexible. Voy a ello, que, total... Le añado a enexpander2.exe un parámetro 2bytes para que LEA 2bytes (seguirá escribiendo un .ene de 3 bytes por hotspot).

Ahora sí lo ha leído e interpretado bien. He generado horace_expanded.ene. Ahora voy a darle la vuelta.

~~

flipenemsnes.exe, por suerte, lee 3 bytes, así que todo va guay. Vamos al lío. Voy a ver si todo está guay. level0.ene generado.

Por cierto, creo que ya a siendo hora de que me plantee hacer un colocador nuevo, en freebasic, sin que se cuelgue ni necesite un puto .DLL de allegro enorme. Debería ir buscando el tiempo. Pero qué pereza me dan estas cosas. En fin, sigo.

~~

Antes de seguir aprovecho para mandar al fondo las ventanas, que se ven demasiado cantosas.

~~

OK - todo importado y listo para pulir. Los enemigos suelen ser lo que más mal da, porque al expandir la pantalla y luego arreglarla a mano nunca casa un carajo. Pero al menos es una tarea que se puede hacer en modo automático sin tener que pensar demasiado. 

Antes voy a ir montando el proyecto, el compile.bat, toda la hostia de siempre. El neslib del lala está completo y tiene los cambios para 113. Tengo que acordarme de hacer bien los .define... Qué hostias, me copio todo el /dev del The Nine y sigo desde ahí, total, es lo que hay que hacer XD

~~

Se me va la cheta. Tengo que hacer los sprites antes, cullons.

20160730
========

Sprites hechos y MUY poco más. He importado el código de Cheril The Nine, he añadido un montón de #ifdef con nuevas directivas para desactivar todo lo que NO necesito del original, y ya estoy listo para empezar con esto.

Iré por hitos. Necesito varias cosas, así, de cabeza:

- Bloques que se empujan. Sí, los mierder. Tengo que añadir la detección al motor de movimiento y la función que los mueve usando la menor cantidad de código posible (no sé por qué apunto esto, si PARA CUALQUIER COSA tengo que intentar usar la menor cantidad de código posible - probablemente sea porque detesto esta funcionalidad).
- Enemigos lineales. Pillarlos directamente del Lala, vaya.
- Motor de salto tipo Monono. No recuerdo muy bien la lógica que tenía detrás. Leeré el código de MK1 de Spectrum - aunque no sé si lo llegué a portar "por inercia" cuando estaba haciendo MK1 de Nes (Cheril).
- Motor de propulsión de Jet Paco.
- Un custom (marcado, por supuesto) para que esté activo uno u otro motor según el valor de una variable COMM_POOL.
- Tengo que diseñar, ahora que lo menciono, todo el rollo del COMM_POOL. Sólo lo usaré para indicar qué juego tengo que activar de cada ROM y además para hacer un checksum para que cuando se haga RESET se vuelva al menú, pero me gusta tener estas cosas bien atadas al principio y dejarlas implementadas cuanto antes.
- Quitar del mapa un tile, creo que el de la ventana. Ese lo usaré para el modo Jet Paco a modo de pincho. Revisar la colisión con los tiles que matan, que creo que habrá que añadirla (the nine no tiene, si mal no recuerdo).

Muchas cosas. En cuanto tenga un poco de tranquilidad iré una por una. Lo primero será, de todos modos, dejar preparado el compile.bat. 

Pero creo que lo suyo es que termine todos los gráficos. El tileset del modo Jetpaco (Jet Puri a partir de ahora), por ejemplo. Que sea compatible, pero con una bola de pinchos en vez de ventana.

20160731
========

Estoy viendo que quiza va siendo hora de extender el intérprete de mkts para admitir todos los tipos básicos, o al menos añadir "chars" y "mapped". Creo que es lo mejor para hacerlo ya super cómodo y automático del todo y para, además, reaprovechar los patrones al máximo.

Volvamos a la especificación y añadamos algunas cosas más.

~~

¡Estupendo! Ahora mkts es capaz de convertir en modo chars, mapped y sprites desde el script. Lo chulo de esto es que puedo procesar todo un banco de gráficos en una sóla llamada a mkts, lo que garantiza el máximo reaprovechamiento, además de menos archivos. Ahora mismo lo genero todo a un spritedata.h y a un tiledata.h.

Compruebo que el tileset.chr exportado está completo, copio un par de cosas que faltan en /utils, arreglo un par de cosas de compile.bat, limpio los directorios, y chapo por hoy.

20160801
========

Vamos a recordar el algoritmo de salto acumulativo de Monono. Así estaba hecho:

- Todas las cosas que pongan vy a 0 (detección de pgotten al principio del bucle, o colisión con el suelo) no deben poner pvy a 0 si está activo pj.
- Al detectar un nuevo salto, pvy = -pvy - PLAYER_JUMP_VY_INITIAL.

Esto me parece bastante poco robusto, pero bueno, se intentará a ver.

Tengo que diseñar el COMM_POOL. Ya sabemos que tenemos 16 espacios. Puedo meter en el 0xF un checksum que sea la suma de todos los anterires. Voy a programar esas funciones en un archivo especial que incluya en todos los juegos.

Por ahora creo que esto es suficiente:

```c
    #define COMM_REG                (COMM_POOL[0x0])
    #define COMM_GAME_SELECT        (COMM_POOL[0x1])
    #define COMM_GAME_FLAGS         (COMM_POOL[0x2])
    #define COMM_CHECKSUM           (COMM_POOL[0xf])
```

También voy a empezar a crear la lista de PRG y CHR ROMs que llevará esto (8 PRG, 16 CHR). Esta lista la iré copiando cada vez que se amplíe.

```
    PRG WHAT                                CHR WHAT                                CHR WHAT
    0   Menu                                0   Menu                                8 Jet Puri extra
    1   Monono / Jet Puri                   1   Monono / Jet Puri                   9
    2                                       2                                       A
    3                                       3                                       B
    4                                       4                                       C
    5                                       5                                       D
    6                                       6                                       E
    7                                       7                                       F
```

La idea es tener el CHR 8-F para cosas extra. Por ejemplo, quiero un dibujo de Jet Puri para un cutscene / final.

~~

Tenemos el choco de los valores negativos. Mejor que me vaya poniendo ya con una solución para esto. Lo suyo sería tener al menos una "casilla" de desfase, de forma que el "mapa" visible empiece en y = 16 (yt = 1) para todas las entidades, sin importar si tengo marcador arriba o abajo, o lo que sea.

Lógicamente, esto será así:

- Y puede ir de 0 a 13. La pantalla se pinta centrada, de Y = 1 - 12.
- La pantalla se pinta en pantalla a partir de la coordenada TOP_ADJUST (debe ser par, por el tema atributos).
- Los sprites deben tener un ajuste igual a (TOP_ADJUST-1) * 8 - 1, que debe sumarse a las coordenadas y.

Lo suyo sería que Jet Puri Prologue y Monono tuviesen diferentes valores para estos tiestos. Voy a convertir, por tanto, TOP_ADJUST y SPRITE_ADJUST en variables.

~~

Al final he hecho eso, y me he puesto con el movimiento del Monono. Lo he hecho de manera más sencilla, con menos código y menos insertos guarreadores, usando una variable auxiliar. Funciona guay. La colisión también funciona.

Ahora voy a meter los enemigos lineales (sacados de Lala) y las plataformas móviles, a ver si dejo eso listo esta mañana y tal.

Tengo que hacer un tontiscript (o usar el que tenía por sabe dios donde) para hacer estos cambios en los .ene:

```
    1-3 -> 0x10-0x13
    4 -> 0x20
    6 -> 0x30
    7 -> 0x70
```

~~ 

Pero qué feo está quedando, joder, pero funciona. Las plataformas móviles funcionan. Habrá que rediseñar media fase para que esto sea jugable, de todos modos. En fin, al final no hay forma de hacer nada sin trabajar XD

Voy a descansar un poquito y luego sigo.

~~

Tengo que hacer que detecte colisiones y que parpadée un poco, con cierto rebote. Hecho.

~~ 

Bueno, veamos los cerrojos y tiles que se empujan. Tengo que inventarme una forma de resolver los tiles que se empujan de una manera realmente sencilla, sin ir a lo loco. Quiero que quede bonito y funcional y que ocupe poco.

Estoy llamando a process_block (x, y) con dos coordenadas. ¿puedo usar una lectura del pad para saber adonde vamos? ¿Sería lo más sencillo? ¿Cómo lo hago en MK1 NES o MK2 Spectrum? Voy a repasar código viejo. Puah, es una cacota. Pasando. Voy a ver con lo del pad...

~~

Bue, parece que funciona. Dios mío, esto está quedando fatal XD Pero hace risa. Ahora a meter las llaves. Lala que te crió - aunque a lo mejor se puede hacer usando menos RAM. Por alguna razón, esto copia en RAM la posición del cerrojo, que ya está en ROM, y no veo por qué no podría leerse de ahí. Sólo necesito llevar un registro de los que están abiertos.

~~ 

Tengo que corregir varias cosas para hacer esto mejor: 

- Poner 2 tiles de desfase vertical en lugar de 1, se jugará mejor en la fila de arriba.
- Corregir el tema de subirse lateralmente a los tiles plataforma. Vamos, lo de siempre XD.
- Joder, creo que voy a tener que rehacer el mapa. Es un despropósito.

20160802
========

Las llaves no funcionan. Voy a mirar esto cuanto antes. Aunque no vendría mal tener ya un puto marcador XD Pero bueno, poco a poco. Voy a mirar a ver qué veo. Funciona la detección, pero no sé si es que no se registra bien o que luego no se lee bien al volver a entrar en la pantalla. Veamos en fceux...

Se registra bien, pero luego no se interpreta bien. Revisemos eso.  - Hm, faltaba reiniciar el puto puntero. Vaya torpe. Probemos . . . 

Ya está perfe. También estaba mal el cálculo de la coordenada para borrar la mandanga.

~~

Y ahora la patata caliente: los tiles que matan. Lo suyo sería que propulsaran hacia arriba en Monono o que invirtiesen los valores de movimiento en el modo Jet Paco. Habrá que seleccionar entre uno y otro comportamiento dependiendo del juego mediante un custom. Como ahora todavía sigo con monono, ese será el comportamiento que programe.

La detección la voy a hacer muy tonta: en el suelo.

~~

Voy a arreglar ahora lo de los tiles plataforma, que eso ya funciona.

~~

Listo. Creo que es el momento, si no me equivoco, de hacer un puto mapa nuevo. Pero no debería ser complicado con este tileset. Puedo hacer una torre central que ir ascendiendo y pantallas a los lados que ir resolviendo. Así será mucho más jugable. Y ya vuelvo a estar yo medio flipándome y currándome un juego que supuestamente no me iba a currar. Si es que esto manda cojones.

Pero antes a lo mejor mola intentar darle un pulidico rápido y si eso montar el sonic mal.

~~ 

¿Qué coño? Se me va la anchoa. Antes de nada voy a terminar esto, joder, que me falta todo el motor de Jet Pac! El marcador, mucha mierda. Se me va la anchoa en canoa de proa, de verdad.

~~

He empezado de todas formas con el mapa nuevo. Le estoy dando una estructura super chula: hay una columna central que da acceso a todas las habitaciones. En cada habitación habrá una llave y un plátano (tengo que hacerlas de varias pantallas, por tanto). Al principio cogemos la primera llave. Así podemos hacer la fase en el orden que queramos.

También se me ha ocurrido una cosa para el Sonic Mal: darle una sorpresa a estos y meter:

- Monos que disparan cocos (obviously, usando otros gráficos).
- Que Sonic se haga bola y ruede al pulsar abajo mientras anda: esto elimina la fricción.
- Que Sonic se haga bola y salte.
- Que los enemigos mueran si hay colisión en estado bola.

Todo eso es una tontería de meter en el motor y va a hacer mucha risa.

Ayer dijimos algunas ideas más:

- En el menú, entre los títulos, aparecerá LEGEND OF ZELDA 3 y NINJAJAR PROLOGUE, y ambas entradas lanzarán Cheril of the Bosque, si bien la segunda lo hará con una paleta diferente (denoche) y Cheril disfrazada de Ninjajar.
- Un juego que se llame ZX JUAN en el que hay que ir de A a B en el menor tiempo posible porque te haces pis. Si te matan o te meas, empiezas de cero.

Y los que ya estaban medio pensados:

- PANTANOW.
- Algo con el material de Lala Lah.

Por otro lado, he probado DOS tilesets para el modo Jet Puri de esta primera ROM y ninguno de los dos me gusta un carajo.

20160803
========

Tengo que revisar:

- Flick screen vertical. [X]
- Relacionado: En modo Jet Puri, en la fila superior, nos salimos de la pantalla sin ningún tipo de control. [X]
- Revisar behs de las plataformas, hay algunas que no deberían ser tratados como tipo 4 sino como tipo 8. [X]

Tengo que hacer:

- Persistencia de posiciones de enemigos (x, y, mx, my). [X]
- Marcador, al menos para Monono. [X]

```
    0               1
    0123456789abcdef0123456789abcdef
     KEYS: x            BANANAS: xx
     LIVES: xx
```

~~

Ya tengo todos los tiestos escamondaos (los de arriba) y creo que tengo medio decidido un tileset para Jet Puri. A estas alturas del cuento sólo me queda (¡sólo! XD) terminar el mapa de Monono, y luego hacerle los añadidos para el modo Jet Puri. Y creo que voy a meter enemigos que disparan en horizontal a intervalos, porque mola y pega, que solo salgan en Jet Puri. Los puedo definir como Horizontales para que en modo Monono se conviertan en lineales y engañar al chamán, pero ya veré. Voy a diseñar lo que necesito. 

~~

El Steady Shooter.
------------------

```
    X1, Y1: Donde está.
    X2, Y2: Permite seleccionar orientación del disparo.
    P: Frecuencia, en segundos.
    T: 0x80
```

Necesito introducir los cocos en la mezcla. Es lo más sencillo. Voy a ir adaptándolos de Yun.

~~

Adaptados. Veamos la forma más sencilla de calcular la dirección. Si tenemos x1, y1, x2, y2 en el momento de crear el coco, podemos hacer así:

```c
    coco_vx = ADD_SIGN2 (x2, x1, COCO_V);
    coco_vy = ADD_SIGN2 (y2, y1, COCO_V);
```

OK! Ahora tengo ya los simple_cocos metidos en el motor, con funciones para tirar cocos tiesos o cocos dirigidos listas para usar. Ahora tendré que meter los enemigos como tales.

Voy a hacer una cosa del curro de verdad y vuelvo a esto :*P

~~

Ok - tengo que resolver cómo asignar un valor a en_s (esto es: el # del sprite) para que asigne una dirección u otra dependiendo de la relación entre x1, y1, x2 e y2. Esto además me permitiría una optimización en cantidad código y velocidad más adelante. Voy a pensar con el cuaderno y el boli.

Veamos, si definimos que 0 LEFT 1 UP 2 RIGHT 3 DOWN, podemos hacer:

```c
    rda = ADD_SIGN2 (x2, x1, 1);
    if (rda) rdb = rda + 1; else rdb = ADD_SIGN2 (y2, y1, 1) + 2;
```

Con esto rda contendría la dirección que podemos almacenar en `en_my`. En `en_mx` almacenaremos el tiempo entre disparos, en segundos.

Luego tendremos esto en precalcs:

```c
    // LEFT UP RIGHT DOWN
    const unsigned char coco_vx_precalc [] = { -COCO_V, 0, COCO_V, 0 };
    const unsigned char coco_vy_precalc [] = { 0, -COCO_V, 0, COCO_V };
```

20160804
========

Ayer dejé ya medio escamondao Monono / Jet Paco, a falta de terminar el nivel. Hoy me apetecía ponerme a montar el siguiente proyecto del Multicart:

Sonic Mal
---------

He montado todo el proyecto... Ya se sabe que eso siempre es un poco coñazo, hasta que tienes las cosas preparadas para empezar a trabajar siempre hay que andar de tramoyismo. Ya completé los gráficos que faltaba y me he preparado el terreno para hacer los "añadidos secretos" que voy a hacer sobre el concepto original de "Lala por pantallas con los gráficos de Sonic Mal" y con los que quiero dar una sorpresa a Anju y compañía:

- El salto es una bola.
- ABAJO hace bola si vamos andando.
- La bola mata.

Ahora sólo me queda meter a los monococos (he hecho un gráfico para ellos) y hacer la pantalla de título que va a ser una risa.

A ver si entre esta noche y mañana termino de apañar el tema.

20160805
========

Ya tengo el juego medio escamondao (aunque tengo que repasar el mapa y colocar más enemigos que disparan - hay que revisar bien porque la colisión vertical es de 16 pixels y hay sitios con agujeros horizontales de 1 tile de alto por los que cuesta meterse), con música y efectos y todo [TODO: ¡Recordar transferir disparos de sonidos al motor de Monono!], así que me voy a liar con la pantalla de título. Necesito el decompresor de RLE tileado de Yun. Voy a meterlo en printer.h. Voy a ir presentando las cosas y lanzando el sonido, y luego ya monto los sprites y el split del scroll. Tengo que ir añadiendo, por tanto, un "colisionador" para el split, tanto en sprites como en tiles. Creo que resolveré esto primero, que luego me da coraje "interrumpir" el dalefraneo porque necesito un gráfico.

~~

Bueno, ya tenemos la pantalla pintada y la música suena. Ahora tengo que planear la animación. Primero habrá unos frames con Sonic saliendo. Voy a hacer esto para ir calculando qué tiene que aparecer en pantalla y donde (hay un pifostio raro de sprites con extraños efectos). Primero tengo que poner la "máscara" con el cacho de fondo y luego a Sonic Mal. Calculemos donde. X está claro = 120, pero ¿e Y?. Como estoy un poco dormido, lo hago de forma empírica. Como cc65 es un compilador rápido, no importa un poco de prueba y error :D. 

Tengo que poner los sprites en 4 y 28.

~~ 

A ver, apunto cosas:

- Reorganizar bien las paletas para lograr que el @#!! texto del marcador salga bien. [X]
- Detectar game over, pantalla de game over.
- Detectar final, pantalla de final.
- Probar que es finalizable y todo eso.

~~

Voy a tener que medio mezclar el diario de The Nine con este. Cuando tenga un rato clono el proyecto, lo meto aquí dentro (en la carpeta del Multicart) y si eso meto el diario de The Nine al principio de este. 

~~

Voy a hacer una super lista:

```
    THE NINE:
        X Meter sonidos.
        X Condiciones (final / game over).
        X Pantalla de título.
        X Pantalla de Game Over.
        X Pantalla de Final.
        X Música de título.
        X Música de ingame.
        X Jingle corto para Game Over / Final.

    MONONO:
        X Condiciones (final / game over)
        x Pantalla de título.
        X Pantalla de Game Over.
        x Pantalla de Final.
        - Música de título.
        - Música de ingame.
        - Jingle corto para Game Over / Final.
        - Mapa

    JET PURI:
        X Condiciones (final / game over)
        X Pantalla de título.
        X Pantalla de Game Over.
        - Pantalla de Final.
        - Música de título.
        - Música de ingame.
        - Jingle corto para Game Over / Final.
        - Mapa (base Monono, añadir pinches)

    SONIC MAL:
        X Condiciones (final / game over)
        X Pantalla de Game Over.
        X Pantalla de Final.
        - Jingle corto para Game Over / Final.

    BOSQUE:
        X Pantalla de título.
        X Pantalla de final.
        X Música de título.
        X Música ingame.
        X Jingle corto para Game Over / Final.
```

Me tengo que quitar todo eso de arriba antes de seguir. Y estoy decidido. 

The Nine
--------

Voy a empezar montando la pantalla de título. Tengo que hacer fullería porque si puedo lograr que me entre en un solo CHR-ROM... Aunque mirando, chungo. Creo que apenas quedan 56 patrones, el marcador se come un montón. Voy a ver qué puedo hacer. Lo primero que voy a hacer es migrar la conversión a los nuevos scripts de mkts, que eso siempre aprovecha mejor.

Haciendo eso y moviendo algunos pixels he hecho que la pantalla de titulo solo ocupe algunos patrones más, pues reaprovecha un montonaco del título. Aún quedaría sitio para más. Si diseño una pantalla de final chula teniendo en cuenta lo que me queda, a lo mejor puedo meterlo todo en un CHR.

He actualizado la lista con las cosas que quedan. A The Nine sólo le queda el final. A Sonic Mal casi que lo mismo, ya que hoy empiezo las vacaciones y por alguna razón Google Drive no ha tenido a bien subir la carpeta de la OGT, así que no tengo el FTM para toquetear. Eso se quedará ahí, en suspenso.

Las pantallas de título de Jet Puri y Monono las hago con los logos que ya tengo disponibles, eso debería tenerlo mañana en un rato. Luego tengo que ver qué hago con la música de estos dos juegos.

20160807
========

De vuelta a Monono / Jet Puri, he hecho un gráfico de 64x128 para el final de Jet Puri que tendrá que ir en un CHR-ROM extra, uno de los primeros que monte. El problema es que para ponerme a meter eso tendré que ir montando ya el menú, y creo que aún es temprano. Dejaré la programación del final de Jet Puri para más adelante.

Centrémonos hoy en los finales de Monono, The Nine  y Sonic Mal. 

El final de Monono es muy sencillo: Mono, banana, texto. Voy a ello.

~

Finales de Monono y The Nine terminados. Ahora tengo que diseñar el de Sonic Mal, pero mini yo se despierta. Vaya siesta corta.

20160808
========

Final de Bosque también terminado. Ya queda nada de nada. Voy a montar Bosque porque ahora no me apetece ponerme a hacer la fase de Monono / Jet Puri. Ya dejaré eso para otro momento, no pasa nada.

Bosque es muy antiguo pero creo que lo tengo todo para hacer una versión chula usando el nuevo motor MK2. ¡Al líow!

~~

Las pantallas ocupan un copón, lo cambiaré a Packed en cuanto lo haga funcionar por primera vez. Así meto el pintador packed. He tenido que modificar los gráficos: enemigos preparados para mirar a izquierda y derecha, y cambiar los objetos de sprites a tiles.

~~ 

Tengo que implementar WALLS_STOP_ENEMIES al menos para los lineales. Además, no funciona por alguna misteriosa razón. Tengo que ver qué carajo pasa. Es como si estuviese en estado "phit" o algo así. A vewr.

Nop. Creo que lo que está mal es el tema de la animación. Estoy interpretando MAL el tema SEGURO. Resuelto. Voy a por el WALLS_STOP_ENEMIES para los lineales.

20160809
========

He metido lo de la colisión de los enemigos con el escenario y además he implementado el modo de colisión de 8x8 para el muñequito del jugador (era 8x16 hasta ahora, fijo). Ahora lo que veo es que no tenía hecha la detección del tile que se empuja en modo genital. Voy al tema.

~~ 

Hecho. Tengo que pegar un repaso porque hay enemigos o muy mal puestos o que se han convertido mal. Es muy raro.

~~

Nah, ya está. Estaban puestos with teh cullow. Ahora voy a cambiar el mapa a packed y a poner el renderer, que incluya tile extra = 16.

20160810
========

Hoy he terminado Cheril of the Bosque. Hay que arreglar mil cosas. He reparado bugs en todos los demás juegos. También he pensado hacer Pantanow reaprovechando las ideas del motor de scroll vertical (aprovechando el mirroring horizontal de la ROM) de Maritrini para un juego rollo Ikari Warriors.

También quiero hacer otro más de MK2 básico o con scripting, probablemente Trabajo Basura. Lo consultaré con la almohada.

En The Nine, tengo que reparar el sonido del disparo, y hacer que suene otro cuando no nos queda energía.

20160811
========

Voy a intentar reparar Cheril todo lo que pueda. Voy a mirar unas cosas en el original y ahora vuelvo...

Listo, apañadísimo, he reprogramado las colisiones con el escenario que mata y ahora es perfe. Sólo hay que ajustar la dificultad.

20160812
========

Seguimos mejorando:

- Cheril The Nine: He hecho que los tiles donde aparecen los generadores no sean traspasables (sí por los disparos / peces). Esto hace que algunas pantallas sean más sencillas (porque se generan enemigos que se encierran solos), pero también consigue que la flor nunca aparezca sobre ellos. Me gusta así. También he reparado los sonidos de disparar. Si confirmáis que este juego se puede acabar, estaría terminado.

- Cheril of the Bosque: He ajustado la dificultad reduciendo la vida a 25, y he colocado refills (5 puntos de vida) por el mapa en las zonas chungas, que no había. He cambiado algunas trayectorias de enemigos y he mejorado un montón la colisión de los enemigos lineales con el escenario (ahora salen unas trayectorias muy chulas sin querer).

20160813
========

Voy a apuntar aquí, como referencia, algunos apuntes que hice hace años sobre el scroll vertical y el buffer rotatorio para las colisiones.

Modificando Neslib
------------------

Como se trata de volcar una tira de tiles (32) justo por encima del área de visualización, y este volcado hay que hacerlo justo durante el período de VBLANK, vamos a modificar la rutina NMI que define neslib para incluir este volcado.

Para ello voy a reservar 32 bytes al principio de la RAM libre para el buffer, o sea, en $300. Tendré, entre otras cosas, que decirle a cc65 que el área de ram libre empieza 32 bytes más arriba, en $320, para que no me pise mi buffer.

Luego tendré que añadir una variable a las que define neslib para que sepa dónde tiene que copiar este buffer dentro de la VRAM. Es mucho más fácil si esta dirección la voy controlando yo desde mi rutina de scroll, en el programa principal. Además, añadiré una función a neslib precisamente para poder darle valor a dicha variable.

Por último, habrá que añadir el código ensamblador de 6502 para copiar el buffer a VRAM.

Estas son las modificaciones que hay que ir haciendo. Las estoy haciendo sobre la versión de neslib que previamente había modificado para poder usar el mapper CNROM que permite cambiar entre 4 CHR ROMs.

Código: Seleccionar todo

- Modify crt0.s, move TEMP to $1f, then add SCROLL_WRITE

```
    crt0.s@66 
    SCROLL_WRITE=$1d   ;word <-- MT
    TEMP      =$1f
```

- Modify nes.cfg, make room for SCROLL_WRITE and reserve 32 bytes in
main RAM

nes.cfg@2

```
   # First 2A bytes of the zero page are used by NES library
    ZP: start = $2A, size = $d6, type = rw, define = yes;
```

nes.cfg@27

```
    # standard 2K SRAM (-zeropage)
    # $0100 famitone, palette, cpu stack
   # $0200 oam buffer
   # $0300 scroll buffer <- MT
   # $0320..$800 ca65 stack

    RAM: start = $0320, size = $04E0, define = yes;
```

- Modify neslib.s, add code to set SCROLL_WRITE

neslib.s@21

```
   .export _set_scroll_write
```

neslib.s@770

```
; void __fastcall__ set_scroll_write (unsigned int adr);
_set_scroll_write:
   stx <SCROLL_WRITE
   sta <SCROLL_WRITE+1
   rts
```

- Modify neslib.h, add prototype

neslib.h@200

```c
// Set SCROLL_WRITE

void __fastcall__ set_scroll_write (unsigned int adr);
```

- Modify neslib.s, add code in NMI function to copy the buffer.

neslib.s@73

```
@upd1:


; Mojon Twins modification - Tile & attrib buffer to scroll (Vertical vers.)
    ; Write address to PPU_ADDR
    lda <SCROLL_WRITE
    sta PPU_ADDR
    lda <SCROLL_WRITE+1
    sta PPU_ADDR
    
    ; Now copy 32 bytes from $400
    ldx #0
@cp32:
    lda $0400,x
    sta PPU_DATA
    inx 
    cpx #$20
    bne @cp32
    
    ; Write address to PPU_ADDR
    lda <ATTRIB_WRITE
    sta PPU_ADDR
    lda <ATTRIB_WRITE+1
    sta PPU_ADDR
    
    ; Now copy 8 bytes from $420
    ldx #0
@cp08:
    lda $0420,x
    sta PPU_DATA
    inx 
    cpx #$08
    bne @cp08
; End of Mojon Twins modification   
```

Nuestra rutina de scroll
------------------------

Esto es muy cómodo: cualquier cosa que ponga yo en el buffer se copiará a VRAM en el sitio donde diga la variable `SCROLL_WRITE`. Lo único que tengo que hacer es mantener siempre `SCROLL_WRITE` justo por encima del área de visualización.

En realidad podría hacerse para que la propia función NMI calculase la posición de `SCROLL_WRITE` y tal, pero por ahora lo voy a dejar manual. Cuando el motor esté listo y vea que puedo hacerlo así, lo cambiaré.

El tema de scrollear por el mapa añade una capa más de abstracción sobre este tema. Tendré que ir recorriendo el mapa de forma que cada 8 pixels que avance el scroll saco una semi-fila de tiles (una linea de caracteres con la mitad inferior o superior de una tira de tiles). Por eso lo voy a juntar todo en la misma función. Esta función va a recibir una cantidad de pixels que scrollear, y va a llevar en sincronía la posición del scroll en el rodillo que es la pantalla y la posición del scroll en el mapa.

Lo que hará será actualizar la posición de la ventana de visualización, actualizar la dirección donde se copia el buffer, extraer una semifila de tiles del mapa y copiarla en el buffer.

```c
// Pantanow Engine v0.1
// Copyleft 2015 The Mojon Twins

// scroller.h - Scrolling functions

// map_ptr is a pointer to the map structure (8x256 bytes).

void scroll_init (void) {
    camera_position = 4096;     // Camera position in pixels
    scroll_y = 480;             // Viewport position in pixels
    map_postn = 2048;           // Map position in bytes
    map_tilepos = 256;          // Map position in tiles
    map_flipflop = 0;           // Flip, flop...
    update_flag = 1;            // Copy new data!
    gbuffer_y = 0;
}

const unsigned char attrs_adds [] = { 0xc0, 0xc8, 0xd0, 0xd8, 0xe0, 0xe8, 0xf0, 0xf8 };
void scroll_advance (unsigned char pixels) {
    // Update scroll
    scroll_y -= pixels;
    if (scroll_y < 0) scroll_y += 480;  
    scroll (0, scroll_y);
    
    // Update write address
    wtp = (scroll_y >> 3);
    if (wtp < 30) {
        set_scroll_write (0x2000 + (wtp << 5));
        set_attrib_write (0x2300 + attrs_adds [wtp >> 2]);
    } else {
        wtp -= 30;
        set_scroll_write (0x2800 + (wtp << 5));
        set_attrib_write (0x2b00 + attrs_adds [wtp >> 2]);
    }
    if ((wtp >> 1) & 1) {
        at_bm = 0x0f;
        at_sh = 4;
    } else {
        at_bm = 0xf0;
        at_sh = 0;
    }
    
    // Update buffer?
    if (camera_position & 7) {
        update_flag = 1;
    } else {
        if (update_flag) {
            update_flag = 0;
            if (map_flipflop) {
                map_flipflop = 0;
            } else {
                map_flipflop = 1;
                map_postn -= 8;
                map_tilepos --;
                gbuffer_y = (gbuffer_y - 1) & 15;
            }
            
            map_gptr = map_ptr + map_postn;
            a4 = 64 + (map_flipflop << 1);

            gpp = SCROLL_BUFFER;
            gpr = ATTRIB_BUFFER;
            gpq = SCREEN_BUFFER + (gbuffer_y << 4);
            
            for (gpit = 0; gpit < 8; gpit ++) {
                a1 = *map_gptr ++;
                
                a2 = (a1 >> 4);
                a3 = (a1 & 15);
                
                // Store in our gbuffer!
                *gpq ++ = a2;
                *gpq ++ = a3;
                
                // Modify attribute
                a5 = *gpr;
                *gpr ++ = (a5 & at_bm) | (((a3 & 12) | ((a2 & 12) >> 2)) << at_sh);
                
                // Calculate char #s
                a2 = a4 + (a2 << 2);
                a3 = a4 + (a3 << 2);
                
                // Draw half tile!
                *gpp ++ = a2;
                *gpp ++ = a2 + 1;
                *gpp ++ = a3;
                *gpp ++ = a3 + 1;               
            }
        }
    }
    
    // Update position
    camera_position -= pixels;
}
```

Con esto montado, el resultado es el del adjunto. Ahora hay que escribir un motor de juego sobre esto. Tiempo de ponerse a pensar un poco más.

Buffer Circular
---------------

Hmmm - Creo que lo tengow :) No era tan complicado, lo que pasa es que me había dado miedow. He hecho un programa en BASIC para simularlo todo y poner prints para verlo y creo que lo tengo.

Ahora lo paso al motowr y tal, y lo optimizo. Con esto sólo hay que escribir 16 bytes cada vez, y si me pico un poco intento hacer la copia en ensamblador.

Este es el programa en BASIC - funciona en Windows, of course. Es una simulación del buffer circular. Se muestra a la derecha el buffer real, es un array normal y corriente de 16x16 (en verdad es uno de 256 elementos, pero ¿quién se va a andar fijando?). La flecha que se ve es el cursor. Esto representa lo que, virtualmente, sería la primera fila del buffer.

Vamos sacando una fila del mapa y poniéndola en el buffer circular, moviendo el "cursor" hacia arriba cada vez. Este "cursor" es el principio "virtual" del buffer para el motor. A la izquierda es "lo que ve el motor". Lo estamos timando. Es como si estuviésemos haciendo scroll en el buffer, pero en verdad no. Sólo estamos cambiando su principio para que cada vez esté más arriba, a la par que le copiamos una fila del mapa.

¡Qué lío! :lol: ¡Pero va a funcionawr!

A lo mejowr podríamos publicar todos estos desvaríos cuando el juego esté terminado en plan diario de desarrollo. Ahora tenía un nombre moderner, pero no me acuerdo. Diario de desarrollo.

```BASIC
'
' En este programa voy a tratar de simular el buffer rotatorio
' para contener una version "en RAM" de la pantalla actual donde
' estamos, esto es, lo que se ve en el viewport (y un poco mas,
' los 240 pixels de alto hacen que me sobre una linea que puedo
' usar para meter la nueva y ... blaw.

Dim Shared As uByte gBuffer (255)   ' Buffer rotatorio de 16x16
Dim Shared As uByte mapa (2047)     ' Mapa

Dim As uInteger i, j, c
Dim Shared As uInteger mapY
Dim Shared As uByte gBufferY

Dim As String inpu

Sub advance () 
    Dim as uInteger i, j, k
    Dim as uByte d
        
    mapY = mapY - 1
    
    ' Copiar la fila nueva en la posicion del buffer
    gBufferY = (gBufferY - 1) And 15
    j = gBufferY * 16
    k = mapY * 8

    For i = 0 To 7
        d = mapa (k)
        k = k + 1
        gBuffer (j) = d \ 16
        j = j + 1
        gBuffer (j) = d And 15
        j = j + 1
    Next i
End Sub

Sub show ()
    ' Mostrar el buffer circular
    Dim as uInteger x, y, ry
    For y = 0 To 15
        ry = (y + gBufferY) And 15
        For x = 0 To 15
            If y = 2 And x = 2 Then Color 14 Else Color 7
            locate y + 2, x + x + 1: Print Hex (gBuffer (ry * 16 + x), 1)
        Next x
    Next y
End Sub

Sub showReal ()
    ' Mostrar el buffer circular real
    Dim as uInteger x, y, ry
    For y = 0 To 15
        For x = 0 To 15
            If y = gBufferY + 2 And x = 2 Then Color 14 Else Color 7
            locate y + 2, 40 + x + x + 1: Print Hex (gBuffer (y * 16 + x), 1)
        Next x
        Locate y + 2, 74: If y = gBufferY Then Print "<-" Else Print "  "
    Next y
End Sub

Function qtile (x as uByte, y as uByte) as uByte
    return gBuffer (16 * ((y + gBufferY) And 15) + x)
End Function

' Rellenamos el mapa
c = 0
For i = 0 to 255
    For j = 0 To 8
        mapa (i * 8 + j) = Val ("&H" & Hex (c, 1) & Hex (c, 1))
    Next j
    c = c + 1: If c = 16 Then c = 0     
Next i

mapY = 256
gBufferY = 0 ' gBufferY apunta siempre adonde se va a escribir

Cls
Locate 19, 1: Color 3
Print "El grafico de la izquierda representa el buffer 'virtual', lo que se 'cree' el"
Print "motor que hay en el buffer. Fijaos como parece que scrollea."
Print "El grafico de la derecha es el buffer real. La flecha apunta a la fila que se"
Print "considera 'la primera' y donde se va metiendo la nueva fila del mapa cada vez."
Print "fijaos como NO escrollea, ¡es una tuampa! En todo momento se lee la posicion"
Print "(2, 2) del buffer 'virtual'. Fijaos que se lee correctamente :) :picha:"
While 1
    show (): showReal ()
    
    Locate 1, 1: Print "Tile en la posicion virtual 2, 2 = " & Hex (qtile (2, 2), 1): locate 18
    Color 15:Print "ENTER Sigue, SPACE y luego ENTER: Fin";: Line Input inpu
    If inpu = " " Then End
    advance ()
Wend

Cls
Print "PANTANOWWWWWWWW!"
```

```c
// Pantanow Engine v0.1
// Copyleft 2015 The Mojon Twins

// gbuffer.h - Circular game buffer

// This buffer contains a representation of an upacked screen
// (which is more or less what's shown on screen at once)

// BEWARE!
// I've made fixed room for this buffer in RAM modifying nes.cfg

// Buffer is @300

// Need this on ZP:
// unsigned char gbuffer_y;

unsigned char qtile (signed char x, signed char y) {
    if (x < 0 || x > 15) return 8;
    y -= map_tilepos;
    if (y < 0 || y > 15) return 0;
    return SCREEN_BUFFER [x + (((y + gbuffer_y) & 15) << 4)];
}

unsigned char attr (signed char x, signed char y) {
    if (x < 0 || x > 15) return 8;
    y -= map_tilepos;
    if (y < 0 || y > 15) return 0;
    return behs [SCREEN_BUFFER [x + (((y + gbuffer_y) & 15) << 4)]];
}
```

~~

Dicho y entendido esto de nuevo, tengo que modificar mkts una vez más para que también sea capaz de exportar tilesets normales sin mapeo por columnas y por filas. Al final con la tontería del multicart vamos a dejar mkts como una patena.

Luego me pondré a jugar un rato a la consola. Me duele la cabeza.

He hecho unos gráficos para los tiles de fondo extrañísimos que consideraba un "placeholder rápido" pero que al final me han terminado gustando. ¡Lo que son las cosas!

~~

Convertidor adaptado pero bah, ya sigo.

Veamos, voy a hacer esto con las estructuras nuevas de la NESLIB. Voy a reservar cierto número de espacios fijos en el update_list para el scroll, y escribiré siempre a posiciones fijas.

```
    0, 1    Address, patrones
    2       Siempre vale 32
    3-34    Fila de patrones
    35, 36  Address, atributos
    37      Siempre vale 8
    38-45   Fila de atributos
```

Ahora que lo pienso, es tontería. Es mucho más rápido si hago los añadidos a neslib y reservo la memoria fija en el mapa de memoria, y no me afecta nada al funcionamiento del resto del multicart. Lo voy a hacer así.

~~

Perfecto. Tras un par de chorreces lo he echado a andar. Ahora tengo que ver esto con detenimiento, porque sólo avanza y hay muchos cálculos que seguro que puedo hacer secuencialmente como en isshokuta, y no calcular desde cero en cada iteración.

Voy a empezar con estas mierdas. Ahora mismo el scroll ocupa, de forma casi fija, alrededor de 40 rasters (bueno, al menos una vez cada 8 pixels, si se avanza más rápido será más).

Mi yo vago dice que lo deje así, pero mi nuevo yo dale fran de la NES dice que intente secuencializar los cambios para un scroll de avance, como debe ser.

20160814
========

He hecho los sprites de la protagonista (aún sin nombre). He tenido la idea de usar coordenadas que vayan de 0 a 256 con rotación, igualito que las colisiones con el escenario. Esto requerirá que piense un poquito a la hora de colisionar con los enemigos, pero creo que no debe tener demasiados problemas.

Voy a examinar el original y si eso meto la rutina de movimiento de MK2 NES del tirón y luego adaptow. Necesito también el bucle principal del juego. Pero estoy hoy muy cansado y vago. No sé qué hacer. Por lo pronto voy a ir importando.

20160816
========

¡Qué espesura! Me está costando horrores porque no le puedo dedicar a esto la atención que merece, pero al menos por fin tengo el scroll y el movimiento del jugador funcionando. Ahora voy a meter los proyectiles.

Había pensado dejar a los proyectiles con coordenadas "de pantalla" para ahorrar, pero luego va a resultar que voy a trasladar toda la complejidad a las colisiones, así que no mola.

Definimos, como en Nine, behs = 4 para que los traspasen los proyectiles y 8 para que no. Los muñecos no podrán traspasar ni 4 ni 8.

~~

Bueno, jugador y balas funcionando al 100%. Ahora tengo que meter a los enemigos. No tengo muy claro por donde tirar. Supongo que los enemigos se definirán usando tira.

Tengo la tira de enemigos, ordenados por "Y". Tengo un puntero a la tira de enemigos. Al avanzar, while (Y[i] <= cam_y) { lanzo i, i ++ }. Eso para lanzarlos, por ahora guay. Permite varios enemigos en la misma linea.

Luego está el tema de los coportamientos. Todos los enemigos deberían hacer esto:

- Condiciones que gobiernan mx, my.
- x = x + mx, colisión en x, acción relacionada con la colisión en x.
- y = y + my, colisión en y, acción relacionada con la colisión en y.
- Disparar si toca.

Tengo que darle vueltas a cómo organizar esto para tener varios tipos de enemigos.

Por ejemplo, tipo 1:

- ct++
- si ct = CUENTA, disparo, my = -my.
- Si colisión, ct = CUENTA.

Hmmm. No sé, esto no va a ser muy manejable.

¿Y si hago algo parecido a los scripts del isshokuta? Podría simplificar.

```
    Acción Parámetro  Condición Parámetro
    WALK   LEFT       CT=X      X=8
    WALK   RIGHT      COLLIDE   -
    SET    ON_COLLIDE -         TURN
```

No sé muy bien como manejar esto. Quizá deba dejarlo estar por ahora y pensármelo un tiempo. Como siempre en internet no habrá una mierda.

Otra opción es volver a la idea inicial y tener unas cuantas AIS atontolinás, pero todo usando el mismo manejador. Así tendría:

- Torretas, solo disparan cada X tiempo.
- Avanzar hasta que encuentran un obstáculo, cambian de dirección. Existen hasta que desaparecen en pantalla o mueren. Disparan cada X tiempo.
- Avanzan un número aleatorio de pasos, cambiar de dirección. En los obstáculos, cambiar de dirección. Existen bla bla. Disparan cada X tiempo.
- Avanzan hacia el jugador. Disparan cada X tiempo.

Disparos: más o menos hacia el jugador, con "más o menos" quiero decir en una de las 8 direcciones, la más apropiada.

Tendríamos:

- Movimiento. Torreta, avance pejiga, avance aleatorio, perseguir.
- Colisión. Qué hacen en la colisión (parar, invertir eje, elegir otra dirección)
- Disparar (cada X tiempo, aleatoriamente)

```
    MMMCCCDD XXXXSSSS
```

Donde:

```
    MMM  : Tipo de movimiento.
    CCC  : Qué hacen en la colisión.
    DD   : Cómo disparan
    XXXX : Coordenada X, en tiles.
    SSSS : Sprite, etc.
```

Esto medio me convence pero, como siempre, primero necesitaría dibujar unos enemigos.

20160817
========

Ya tengo a los enemigos dibujados e importados en los patrones y spriteset. Ahora tengo que fullear esto. Vamos a darle valores a todo esto:

```
    MMM - Tipo de movimiento

    000 - Torreta, no se mueve.
    001 - Se mueve al azar en obstáculo.
    010 - Se mueve al azar con contador en obstáculo.
    011 - Se mueve hacia tí.
    100 - Reservado ?
    101 - 001 pero desde abajo
    110 - 010 pero desde abajo
    111 - 011 pero desde abajo

    CCC - Qué hacer en la colisión

    000 - No hacer nada (parar y ya).
    001 - Invertir ejes.
    010 - Elegir otra dirección
    011 - ?
    1XX - lo mismo, pero además disparan.

    DD - Como disparan

    00 - Aleatoriamente, en la dirección en la que andan
    01 - Cada segundo, en la dirección en la que andan
    1X - lo mismo, pero hacia tí.

    XXXX - 0 a 15, coordenada X

    ---S - Sprite, etc

    ---0 - Sprite 1
    ---1 - Sprite 2
```

Voy a meter un par de mierdas en una lista, que sean torretas, para empezar.

~~

Torretas cool!

20160818
========

Antes de seguir haciendo cosas nuevas, voy a apuntar otras y a arreglar Bosque y Nine para dejarlos nickelodeón. Apuntamos:

- ROM de minijuegos mierder: "POTI POTI", "PICHACHOCHO", "MOGGY NES?", "ZX JUAN".
- ROM de balowwwn / Moggy Adventure.

Nine: 

- Bajar vidas iniciales a 40 [X]
- Revisar colisión de la paseante. [ ]
- Meter frame de paseante hostiada [X]

Bosque: 

- Revisar malos chungos. [ ]

~~ 

Volviendo con Pantanow, ya están metidas las muñecas en modo glitchy total, pero al menos ya está la base. Ahora tengo que meter los estados muriendo, disparando e idle.

~

Hay problemas con balas que se quedan en pantalla :-/ - Meh, era una chorrez.

Ahora me enfrento al punto en el que hago colisionar balas y enemigos y balas y jugador... Y creo que ya me estoy acercando muy peligrosamente al borde del tiempo de frame. O me pongo a optimizar, o esto se me va de madre.

También estoy viendo que colocar a las enemigas va a ser un poco pesadilla.

~~

20160820
========

Todo parece funcionar bien. Quiero aprovechar el tipo 100 para meter enemigos programados. Los programas irían almacenados aparte y serían del rollo avanzar dirección espacios, parar segundos, disparar, con uno especial para desaparecer.

Tendríamos entonces estos comandos:

```
    OP PARM1 PARM2

    OP: 

    00 - IDLE
    01 - ADVANCE
    10 - FIRE

    PARM1:

    000 - UP
    001 - UP RIGHT
    010 - RIGHT
    011 - DOWN RIGHT
    100 - DOWN
    101 - DOWN LEFT
    110 - LEFT
    111 - UP LEFT

    PARM2:

    IDLE: # segundos
    ADVANCE: # espacios, 0 = Infinito.
    FIRE:
    000 - DIR
    001 - PLAYER
```

~~ 

Cuando los personajes programados terminan su rutina, se convierten automáticamente en personajes de tipo 1. Ahora lo que me queda resolver es como indicar qué rutina llevan los personajes. Volvamos a la definición de personajes:

```
    MMMCCCDD XXXXSSSS

    M = 100,
    X = Necesario.
    S = Parcialmente necesario (al menos 1 bit!)
```

Puedo usar CCCDD para efectuar 32 rutinas diferentes. Voy a programar una rutina de prueba y a probar esto con un enemigo. En las rutinas, los obstáculos harán que el muñeco cambie la dirección de los ejes implicados en la misma. Esta sería la rutina de prueba:

```
    ABAJO 4
    DISPARO
    DERECHA 4
    IDLE 2
    DISPARO
    IDLE 1
    IZQUIERDA 4
    IDLE 1
    DERECHA 4
    DISPARO
    ARRIBA 4
```

Voy a hacer un compilador de esta mierda en 3 segundos...

~

Compilador hecho y funcionando. Escupe código. Ahora estoy muerto de sueño. Mañana si eso miro ya como integrarlo todo. Y creo que descansaré encargándome de empezar con la ROM de tonterías.

~~ 

20160822
========

Ni rom de tonterías ni hostias, aquí hay mucha mierda que hacer y yo tengo poco tiempo. Voy a meter lo de los enemigos programados y a tirar peos. Probaré con el tontaco que he programado:

```
    DOWN 4
    FIRE PLAYER
    RIGHT 4
    IDLE 2
    FIRE PLAYER
    IDLE 1
    LEFT 4
    IDLE 1
    RIGHT 4
    FIRE PLAYER
    UP 4
    DOWN RIGHT 4
    IDLE 5
```

Que compila en este código, que esperemos que sea correcto para evitar dolores de cabeza (eso parece, de todos modos):

```c
    const unsigned char behaviour [] = {
        0x64, 0x81, 0x54, 0x02, 0x81, 0x01, 0x74, 0x01, 0x54, 0x81, 0x44, 0x5c, 0x05
    };
```

Integremos, integremos.

~~

¡¡Hecho!! Enemigos programados integrados. Ahora ya puedo programar movimientos estúpidos y coreografiados.

~~

20160823
========

He metido más programadas y he arreglado un par de tonterías, pero ahora veo que las enemigas perseguidoras no van nada, pero nada finas. A revisar - Bueno, sí que van finas, pero tendría que ver como va el tema de cambiar de modo cuando no pueden avanzar en la dirección del jugador. Lo revisaré para poner una cota de número de espacios para desplazarse.

~~

También me he puesto con la ROM de las tontás, en principio Poti Poti. Tengo que hacer un sistema para cambiar muy fácilmente de sistema de juego, sobre todo el tema de los valores de aceleración de más mierdas y miserias.

20160824-25
===========

Poti Poti on, empiezo "RendezVous", en el que dos niñas tienen que encontrarse en el mapa jugando sucesivamente. Pero al final me veo haciendo el mapa entero de cero :-/

20160826
========

Los diarios son una mierda cuando hay poco desarrollo que hacer y mucho contenido que generarlw.

Pero mira, aquí hay algo que modificar: para que las balas no maten al que las dispara mientras no "salen" de su sprite, tenía una pencada de contador que hacía que durante cierto numero de frames las balas no matasen, pero eso era la mierda e introducía muchos problemas. Lo que voy a hacer es guardar quién disparó cada bala de forma que esa bala no mate a su propio disparador. Para ello introduzco el array bagent, que llevará el ID del enemigo, o "0xff" para el jugador.

¡Hecho! He cambiado la velocidad de las balas de 4 a 2 para los enemigos, porque decían estos que iban muy rápido, pero ahora pienso que van muy lentas. No sé, habrá que seguir ajustando cosas.

Algo que voy a tener que hacer es empezar a multiplexar... ¿Y si dejo las velocidades de las balas como estaban pero proceso solo la mitad par/impar en cada frame? Voy a probar.

~~

Va mejor, claro, y tal y cual. Me gusta, aunque seguro que hay más donde multiplexar y optimizar.

Tengo que empezar a pensar en el menú. Debería hacer algún rollo de estructura de memoria para meter título, CHR-ROM y PRG-ROM. Voy a ir creando la carpeta. 

~~

Repasemos esto: 

```
    PRG WHAT                                CHR WHAT                                CHR WHAT
    0   Menu                                0   Menu                                8 Jet Puri extra
    1   Monono / Jet Puri                   1   Monono / Jet Puri                   9 Cheril of the Bosque mapa 2 / Bits
    2   Bosque                              2   Bosque                              A
    3   Pantanow                            3   Pantanow                            B
    4   Sonic Mal                           4   Sonic Mal                           C
    5   The Nine                            5   The Nine                            D
    6   Tonterías                           6   Tonterías                           E
    7                                       7                                       F
```

~~

Otras cosas en las que me puedo dispersar:

- Completar la ROM de Bosque metiendo el modo de juego con la paleta cambiada y Ninjajar de protagonista, y luego meter otro mapa adaptado, como por ejemplo el de Moggy Adventure u otro genital que sea chulo y que ahora no recuerde. Si quiero usar otro tileset diferente tengo que usar otro CHR ROM de los extra, porque no quedan patrones. Uso el 9.

- Convertir la fase del puente de Goku Mal para hacer una fase del puente de Sonic Mal rollo Bridge Zone. Modificar la ROM, cuando esté terminada, para que muestre el mismo juego pero con las fases al reves (primero 1, luego 0), otro tileset y knuckles en vez de sonic. Por ejemplo.

20160828
========

Me puse a rellenar Bosque con el modo Ninjajar y con el modo "Cheril of the Bosque en otro Bosque", pero quiero meterle personajes y que haya que ir hablando con ellos en cierto orden que cambia en cada partida, para complicar el tema (encontrar todas las bellotas sería un objetivo secundario). Para ello necesito un buen cuadro de texto y creo que lo voy a intentar hacer con un split del scroll, a ver qué tal sale el dalefraneo :D

~~

No me sirve. Por lo que se ve, la función de Split no está completa y sólo cambia el valor X del scroll. Y mi kung fu tiene sueño, así que pasando. Buscamos otra forma - borro 8 lineas en el centro de la pantalla y luego las restauro y a tomar por culo.

20160830
========

Estuve ayer haciendo infraestructura para el tema de las cajas de texto, y me he dado cuenta de que no he pensado para nada como voy a hacer esto. A ver, lo que quiero conseguir es que haya que hablar en orden con los seis personajes. Los personajes estarán en sitios fijos del escenario (pantalla-coordenads fijas). El almacenaje en arrays y la detección rollo hotspots es lo de menos. Lo que tengo que ver es la mecánica del orden y como definirlo.

En casa encontraremos al primer personaje, que será Johnny Limite. Él llevará el 0. Los demás irán numerados del 1 al 5 tal y como aparecen en el conjunto de metasprites, para simplificar. Generar una lista de 5 numeros en RAM y barajarlos no es problema. Puedo hacer que haya un índice a esa lista con el siguiente con el que tenemos que hablar. Si hablamos con uno de los personajes y su id <> siguiente, dice "MY NAME IS ~, BUT YOU MAY BE LOOKING FOR SOMEBODY ELSE". Si su id == siguiente, se ejecuta su diálogo (más adelante) y se incrementa el índice. Si el índidce es 6, todos los personajes dicen "YOU ARE DONE WITH US. COLLECT THE NUTS!".

Ahora tengo que pensar en cómo codificar diálogos de longitud y desarrollo variable. 

~

Veamos, necesitaría un array que describiese un diálogo y luego un índice. Algo así:

```c
    const unsigned char *dialogo1 = { 0xff, texto1, 1, texto2, 1, texto3, 0xff, texto4};
```

Ahí voy intercalando ID de quien habla con índices de la tabla de textos. Luego tendré un

```c
const unsigned char * const dialogos [] = { dialogo0, dialogo1, dialogo2, ... }
```

~~

A ver, textos que necesito:

```
    XXXXXXXXXXXXXXXXXXXXXX

    General:

    JOHNNY LIMITE

    RAMIRE THE VAMPIRE

    AMADOR 

    YUN

    SIR ABABOL

    LALA

    THIS IS ...

    YOU MUST TALK TO ...

    YOU ARE DONE WITH US!
    NOW COLLECT THE NUTS!

    Limite:

    {
        L
        HI, I'M JOHNNY LIMITE
        THE SUPER HERO!

        L
        I'M A BIT PISSED OFF
        'CAUSE I DON'T HAVE A
        GAME OF MY OWN, YOU
        KNOW.

        L
        SO I'M GIVING YOU AN
        EXTRA TASK: YOU MUST
        FIND AND TALK TO MY
        FRIENDS IN ORDER!
    }

    Ramiro:

    {
        R
        GREETINGS, THIS IS
        RAMIRE THE VAMPIRE!
        AREN'T YOU AFRAID?

        C
        NOT VERY. I HOPE YOU
        DON'T FEEL BAD FOR 
        THIS...

        R
        EUH, NO, IN FACT I'M
        QUITE USED TO NOT
        BEING FRIGHTENING AT
        ALL. AW.

        C
        DON'T FEEL BAD. AT
        LEAST YOU ARE UGLY.

        R
        AND WITH THIS CAPE
        I LOOK LIKE BATMAN!
    }

    Amador:

    {
        A
        HEYA, I'M AMADOR, 
        AND I'M A LUMBERJACK
        AGAIN. WORKING IN A
        CIRCUS WASN'T FOR ME

        C
        HEY, I REMEMBER YOU
        FROM NINJAJAR!.

        A
        DID YOU APPEAR IN
        NINJAJAR? I DON'T
        REMEMBER YOU.

        C
        HE HE HE, I DID, 
        BUT I'LL SHUT UP.
        THERE'S NO 'SPOILER
        ALERT' TAG HERE!
    }

    Yun:

    {
        Y
        HEY! ARE YOU A JELLY
        FISH?

        C
        DO I LOOK LIKE A 
        JELLY FISH?

        Y
        IF YOU LOOKED LIKE A
        JELLY FISH I WOULDN'T
        BE ASKING. YOU COULD 
        BE ONE IN DISGUISE.

        C
        I AM CHERIL OF THE
        BOSQUE.

        Y
        AND I AM YUN OF THE
        MARSH. PLEASED TO
        MEET YOU.
    }

    Sir Ababol:

    {
        S
        HELLO. I'M A NOBLE
        KNIGHT AND MY NAME
        IS SIR ABABOL.

        C
        SIR ABADOL?

        S
        NO, SIR ABABOL. YAR,
        WHY CAN'T ANYBODY 
        GET THE DAMN NAME
        RIGHT?

        C
        SIR ABIDOL, U SAID?

        S
        NO, FOR GOD'S SAKE,
        IT'S SIR A B A B O L

        C
        SIR ABALON?
    }

    Lala 

    {
        L 
        HELLO CHERIL, HOW
        ARE YOU DOING?

        C
        HELLO, LALA. QUITE
        FINE. YOU LOOK GREAT
        AS ALWAYS.

        L
        THANKS. I MAY LOOK
        GREAT BUT I SURELY
        LOOK DIFFERENT IN 
        THE TITLE SCREEN.

        C
        AND WHO FUCKING
        CARES?
    }
```

Me cago en la leche migá, a ver como codifico esto XD. Debería poder llamar de forma relativamente flexible a la función que pinta el cuadro de texto, sobre todo porque hay variables rollo "SOY ..." "BUSCA A ..." (Jacqs).

¿Tener cuatro punteros es un poco penco?

Por lo pronto voy a meter todas las lineas en un archivo de texto que pasaré an un array de forma que todo tenga un padding de 21 caracteres. De ese modo, obtener la linea iésima será relativamente sencillo, y leer qué linea es mirando al archivo algo muy fácil (nº linea - 1).

~

Ya tengo toda la ristra de texto y el índice hecho. Ahora a ver cómo me las apaño para que entre todo. Por lo pronto voy a compilar no me vaya a estar pasando.

~

Mierda. Me paso 106 bytes. Esto ya lo sabía yo. Son 5 lineas de texto sin contar con que no tengo nada de la lógica programada. Ar. Voy a ver si puedo hacer que los mapas ocupen menos con alguna compresión. Si no tendré que tontificar diálogos y rehacer el índice. NOOOUouOUOuoUOUouOU!

No. Ocupan más de cualquiera de las maneras :-/

~~

Espera, voy a inventarme una fullería para sacar del binario las definiciones de metasprites del segundo set de Cheril, que no se usan... A ver... Perfecto. Así me ahorro 286 bytes. Tengo que recortar más.

~~

Espacio libre: ~452 bytes. Es bastante, ¿me cabría lo que me falta por añadir?

- Arrays de colocación de los personajes.
- Lógica de detección y variables de ubicación.
- Array de orden y shuffling.
- Render.
- Colisión y respuesta.
- Condición de acabarse el juego.

Voy a ir metiendo y veo...

~~

Colocación de señores y caballeras:

```
            n   x   y   YX
    Limite  15  12  4   4C
    Ramiro  5   5   10  A5
    Amador  30  4   4   44
    Yun     4   13  2   2D
    Ababol  29  12  1   1C
    Lala    20  8   4   48
```

~~

He metido gran parte de la lógica (aunque no toda). Ahora mismo me quedan unos 114 bytes. Tengo que liberar por otro lado porque ahí no me cabe seguro lo que falta.

Se me ocurre que podría liberar un porronazo si lograse que los sprites de los enemigos usasen los mismos patrones, ahorrándome metasprites y mierda del array. Para ello tengo que ver qué repeticiones hay y repetirlas o, más fácil, evitar que haya repeticiones. Hay patrones de sobra. Voy a ello.

~~

¡Perfecto! Con este cambio he liberado y me vuelven a quedar alrededor de 450 bytes. Creo que me da.

~~ 

Parece funcionar, pero la mierda es que había calculado mal la longitud de linea... Puse 21 pero son 19. FUCK. A reescribir y hacer entrar...

~~

Bueno, lo he terminado. Ahora habrá que echarle unas partidas para terminarlo y darlo por finiquitao.

20160831
========

Vamos a recapitular a ver qué falta:

- Bosque 1 (normal): Probado y más que probado. TERMINADO
- Bosque 2 (ninjajar): Idem. TERMINADO
- Bosque 3 (otro bosque): Falta probarlo y validarlo.
- The Nine: TERMINADO.
- Sonic Mal: Hablamos de meter una fase extra, "Bridge Zone". Sujeto a ganas que haya.
- Sonic Mal 2: Como 1 pero invirtiendo el orden de las fases, depende del anterior.
- Poti Poti: TERMINADO.
- RendezVous. Creo que el mapa está OK, hay que hacer los enemigos y programar la lógica.
- Pantanow: Terminar los enemigos de la fase.
- Desiertow: No hay nada.
- Azoteaw: No hay nada.
- Monono: Terminar de pulir una pantalla y probar.
- Jet Puri: Cuando Monono esté OK, añadir los pinchos, probar.
- El leovigildo. Que no hay nada.
- Menú.

Remember: tengo el mapa de Lala Lah y sus gráficos muertos de risa todavía, sin usar. A unas malas también se puede meter una ROM de Yun con otras fases o simplemente Yun en modo Límite.

Debería ponerme las pilas con Pantanow y terminar al menos ese.

~~

20160902
========

Días y más días en blanco. Puf. Recordemos una vez más la escaleta...

```
    PRG WHAT                                CHR WHAT                                CHR WHAT
    0   Menu                                0   Menu                                8 Jet Puri extra
    1   Monono / Jet Puri                   1   Monono / Jet Puri                   9 Cheril of the Bosque mapa 2 / Bits
    2   Bosque                              2   Bosque                              A
    3   Pantanow                            3   Pantanow                            B
    4   Sonic Mal                           4   Sonic Mal                           C
    5   The Nine                            5   The Nine                            D
    6   Tonterías                           6   Tonterías                           E
    7   Leovigildo                          7   Leovigildo                          F
```

A ver si puedo avanzar alguno de los frentes. Debería ir tirándole a los que están a punto de caramelo. Probar el Bosque en otro Bosque, terminar Monono y Jet Puri. Y luego seguir por Sonic Mal, fase 2.

~~ 

Coño, el mapa de Monono está terminado. ¡Pues otra cosa más que hay que probar! Lo bueno de Monono es que puedo probar cada sección prácticamente por separado, así que la primera prueba que es la que hago yo para hacer el juego jugable la puedo ir haciendo tranquilamente, por trozos, validando. Voy a hacer un esquema del mapa con las secciones. · es la sección principal:

```
    ···
    ···
    1·1
    1·1
    1·2
    2·2
    3·2
    3··
    4·5
    4·5
```

Creo que las secciones 1 y 2 las estuve probando y puliendo, así que las dejaré para el final. Comprobaré las secciones 3, 4 y 5 modificando simplemente el punto del mapa donde empezamos y otorgando una llave.

~~ 

3 validada. Aprovecho para la 4... validada también. Este juego es difícil de cojonatos. Puedo ofrecer la opción "continue" en la que no reinicio el mapa ni la cuenta de bananas. Lo apunto para cuando esté todo validado.

Veamos la 5...  Yeah.

20160906
========

Apenas he podido dedicar tiempo a esto en estos días. Monono está completo. Davidian me ha pasado un apunte de música pero es demasiado corta y no sabría como seguir sus pasos, es posible que la deje para la pantalla de título y emplée alguna parte para repetir durante el juego.

Completé el mapa en modo Jet Puri y lo medio probé. El movimiento no está demasiado bien ajustado. Quiero meter "humitos" que vaya dejando Jet Puri atrás mientras va volando. Unos cuantos frames desvaneciéndose hasta desaparecer. Que aparezcan cada vuelta justa de 32 ciclos o 64, más o menos (probar). Fácil de añadir.

También trabajé un poco en Rendezvous, dibujando los gráficos de los enemigos. Tendré que adaptar las gyrosaws a este juego y luego colocar enemigos en el mapa (un tipo lineal, un tipo monococo, un tipo gyrosaw, un tipo plataforma).

Este juego será un poco extraño. Tengo que definir posibles sitios donde puede empezar cada personaje. Al arrancar la ROM se elige un sitio para cada personaje. Cada vez que se inicia una partida se hace, alternativamente, con uno de los dos personajes. La posición no se reinicia al morir: en la siguiente partida el personaje que sea aparecerá en el último "safe spot" calculado para el. Las partidas serán de una sola vida: te tocan y estás muerto. Las paletas cambiarán según el personaje. Tengo que dibujar una pantalla de título sencilla. El backdrop que hay detrás del escenario se pintará con una fila de edificios y nubes que aparecerá a diferentes alturas dependiendo de donde estemos en el mapa (filas más bajas, posición más baja).

Hay bastante que programar - no me gusta hacerlo sin tener antes los recursos, pero últimamente estoy tan mal de tiempo y ocasiones que no aprovechar un par de espacios para programar aunque sea a ciegas sería un crimen.

~~ 

He metido un par de cosas más genéricas (el backdrop, la posibilidad de no dibujar el tile 0 y el safe spot). Ahora voy a ampliar los scripts de importación de gráficos y meter las nuevas paletas y patrones y tal.

20160907
========

He terminado de montar toda la mandanga necesaria para importar los tiestos de Rendezvous, darle forma a los arrays de metasprites, importar paletas, y demás tareas coñazas. Ahora tengo que colocar enemigos:

```
    $10, $11: lineales.
    $23: plataformas.
    $90: monococos.
    $B0: gyrosaws.
```

Aparte de esto, tengo que decidir cómo hacer aparecer a las dos niñas en el mapa al azar. Creo que puedo colocar a la niña #1 en la parte izquierda del mapa, en las dos primeras columnas, y a la niña #2 en la parte derecha, en las dos últimas columnas. Voy a ver el mapa a ver si es seguro que aparezcan en la misma coordenada o tengo que marcar de algún modo...

~~

Creo que no quedará raro si creo a las personajes en (1,1). - Nah, voy a poner arrays precalculadas con los posibles sitios donde salir.

~~

```c
    // CUSTOM {
    signed int ini_px [1], ini_py [1];
    unsigned char ini_n_pant [1];
    // } END_OF_CUSTOM
```

Tengo que mantener un flag del personaje activo y actualizar esas variables al terminar con los valores del safe_*. Al inicializar, tomar esos valores.

~~ 

He avanzado bastante en rendezvous, está casi completo. Tengo que revisar:

- Gyrosaws deberían ser reinicializadas cada vez y no tener en cuenta la persistencia de los enemigos (fix). [X]
- Al entrar en cada pantalla hay que ver si la niña que no esté en juego se quedó en esa pantalla y entonces definirla como activa, añadir su sprite en cada frame, y detectar colisión. [X]
- Tengo que montar una pantalla con el final del juego.
- Al cartucho le queda el mato de espacio todavía. Aún caben más paranoias :)

20160909
========

Vamos a meter a la otra niña y lanzar el final.

20160913
========

Tras días sin poder tocar ni una coma, retomamos. Veamos, niña puesta y final lanzado, pero me gustaría que se viera algo chulo. Además, me gustaría añadir frases misteriosas y lapidarias que saliesen cada vez que vamos a jugar. Otra característica es que la música será una sola y será continua, no cambiará de menú a juego ni game over ni nada.

Todo añadido, todo funcionando guay. Faltaría la música. Ahora he decidido hacer el mapa más grande.

20160914
========

No dejo de pensar que necesito que esto sea ya un multicart (aunque no haya todavía menú) para poder seguir con alguinas cosas, como por ejemplo un set alternativo para Rendezvous que haga FLASHSHSHSHSH para mayor WTF, el final de Jet Puri, y alguna cosa más que se me ocurra. Como todo esto necesita cambiar el CHR-ROM necesito la infraestructura completa, la ROM con todos los bancos y tal.

Creo que voy a trabajar ahora un rato en ese aspecto. Haré una ROM0 dummy que simplemente salte a otra combinación de CHR/PRG y así pruebo. O un selector. Sí, eso puede molar.

~~ 

Menú rollo cheat montado y funcionando. Ahora voy a montar la ROM. A ver a ver a ver. Esto va a costar.

```
    PRG WHAT                                CHR WHAT                                CHR WHAT
    0   Menu                                0   Menu                                8 Jet Puri extra
    1   Monono / Jet Puri                   1   Monono / Jet Puri                   9 Cheril of the Bosque mapa 2 / Bits
    2   Bosque                              2   Bosque                              A
    3   Pantanow                            3   Pantanow                            B
    4   Sonic Mal                           4   Sonic Mal                           C
    5   The Nine                            5   The Nine                            D
    6   Tonterías                           6   Tonterías                           E
    7   Leovigildo                          7   Leovigildo                          F
```

~~

¡Estupendo! El cartucho está montado y el driver del mapper funciona de muerte. Puedo seleccionar la combinación de PRG/CHR/GS y me cambia guay. Ahora lo que tengo que hacer es empezar a meter extras como el final de Jet puri. Voy a ello!

~

Et fini. Final de Jet Puri metido y funcionando :) Debería hacer música para este juego ya. A ver qué hago. Lo del murciano molaba pero no es suficiente, es demasiado poco. Veré qué me invento.

~~

Al final fulleé y metí fullerías varias y variadas.

20160916
========

Ayer se me ocurrió una cosa muy chula para Rendezvous aprovechando que hay todavía muchos CHR-ROM libres. Cuando se cumpla esto:

- Estás jugando.
- Llevas X muertes. (?)
- Estás en la misma pantalla que la otra niña.
- Han pasado ticks + ticks frames desde que empezó la pantalla.

Entonces se cambia a otro CHR-ROM (y paleta) con versiones "alternativas" y malrolleras de todos los gráficos. Todos los enemigos pasan a tener el mismo aspecto gore y cuando te tocan se reinicia el juego completamente.

Además podría contar los encuentros y los reintentos en el marcador. De hecho, voy a meter eso ahora mismo.

Idea para elaborar: que cambien las cosas cuando haya muchos reintentos / wins. Qué concepto más vago.

```
    0               1
    0123456789ABCDEF0123456789ABCDEF
     LIVES:xx  ATTEMPTS:xx  WINS:xx
```

 20160917
 ========

 Aquí estoy. He terminado el set alternativo, intentando que case todo (tiene que haber una correspondencia 1:1 entre patrones, y eso puede ser compliquéited). A ver qué tal. Voy a importar y a comparar. Pondré el cambio para probar en la tecla SELECT... Y, además:

```
    PRG WHAT                                CHR WHAT                                CHR WHAT
    0   Menu                                0   Menu                                8 Jet Puri extra
    1   Monono / Jet Puri                   1   Monono / Jet Puri                   9 Cheril of the Bosque mapa 2 / Bits
    2   Bosque                              2   Bosque                              A Rendezvous extra
    3   Pantanow                            3   Pantanow                            B
    4   Sonic Mal                           4   Sonic Mal                           C
    5   The Nine                            5   The Nine                            D
    6   Tonterías                           6   Tonterías                           E
    7   Leovigildo                          7   Leovigildo                          F
```

Veamos - vamos a ir haciendo una lista de las cosas que quedan para terminar, por ROM.

**ROM0**

- Hacer el menú.

**ROM1**

- Probar Monono
- Probar Jet Puri

**ROM2**

- Probar Cheril of the Bosque (En Otro Bosque)

**ROM3**

- Terminar de colocar enemigos en Pantanow.
- Gráficos, mapa, enemigos de Desiertow.
- Gráficos, mapa, enemigos de Azoteaw.

**ROM4**

- Gráficos, mapa, enemigos de Bridge Zone.

**ROM 5**

**ROM 6**

- Probar Rendezvous

**ROM 7**

- Gráficos, mapa, enemigos, programación de Leovigildo (todo, vaya).

Me doy hasta Navidades. Tengo que tener esto terminado mucho antes, de hecho, porque quiero terminar el año pasando Lala a UNROM y terminando Wo Xiang Niao Niao para el concurso.

20160927
========

He seguido ampliando cosas. Bridge zone está completo a falta de pulir y añadir una música que me ha dicho David que va a hacer él. Mirando el espacio que queda en ROM, a lo mejor me cabe Jungle Zone. Al final siempre me termino flipando, no hay manera de hacer nada sencillo. Pero mejor. Cuando termine el Multicart vamos a tener algo muy interesante y muy chulo que (espero) dará que hablar. Y tendremos un motor MK2 para hacer cosas muy sencillas que estará en un estado muy avanzado. En ese aspecto, este multicart está siendo el equivalente a la Covertape 2 de 2013. Eso mola.

Voy a examinar un momentico, por mirar, el espacio que sobra en las diferentes ROMs...

- En la ROM de Tontis hay 8 Kb libres!
- La ROM de Bosque está petada. Normal :)
- En la ROM de Sonic Mal hay 10-11Kb libres.
- En la ROM de Cheril the Nine hay 8 Kb libres.
- En la ROM de Monono / Jet Puri hay casi 8 Kb libres.

¡UF! Hay espacio libre a saco paco, me caben barcos por todos lados y puedo meter más juegos y todo. Mirando por ahí, tengo la fase y gráficos de Lala Lah, por poner un ejemplo, que no se están usando. Mirando así por encima creo que podría encasquetar Lala Lah en la ROM de Monono y tener así más juegos en el menú - siempre que me quepan los patrones, claro.

Va a ser que no. Con tanta pantalla de presentación, no queda sitio en los patrones de tiles. Aunque tengo un montón de CHR-ROM libres todavía, podría usarlos. Vamos a mirar otras ROMs. En The Nine recuerdo también que Anjuel gastó un porrón de patrones en el marcador.

Um, venga, me dejo de zarandajas: uso un nuevo set y aprovecho para hacer algún dibujito de Lala. Aunque aún no esté, modificamos la lista:

```
    PRG WHAT                                CHR WHAT                                CHR WHAT
    0   Menu                                0   Menu                                8 Jet Puri extra
    1   Monono / Jet Puri / Lah             1   Monono / Jet Puri                   9 Cheril of the Bosque mapa 2 / Bits
    2   Bosque                              2   Bosque                              A Rendezvous extra
    3   Pantanow                            3   Pantanow                            B Lah
    4   Sonic Mal                           4   Sonic Mal                           C
    5   The Nine                            5   The Nine                            D
    6   Tonterías                           6   Tonterías                           E
    7   Leovigildo                          7   Leovigildo                          F
```

Volviendo a Sonic Mal, con la idea de meter un Jungle Zone (me caben más fases pero las músicas ¡oh, las músicas! siempre ocupan un egg)

Veamos: quedan unos 39 patrones. Para jungle, necesito en principio hacer gráficos para cascada, cascada por detrás, plataforma en la cascada, bloques de tierra con césped arriba, y tronquitos. Y una roca.

Voy a intetar optimizar los otros sets un poco.

~~

Optimizando he pasado de 39 a 56 libres, lo que está de puta madre, y así me cabe jungle zone sin problemas. Necesitaré una paleta especial para hacer el ciclo, por cierto. Tiene que ser un jodido mareo.

Voy a trasladar los tiles originales de cascada (frente y fondo), tronquitos, tronquitos con pinchos, bloques de escenario con césped (a ver qué hago para no tener que usar ¡9! tiles para esto) y uno random para fondo que no vaya en el mapa y que se active solo en esta fase.

Ahora que lo pienso, mientras no gaste los patrones, el hecho de estar usando compresión RLE a byte no me limita a 16 metatiles - aunque habrá que tener cuidado y diseñarlo todo lo suficientemente sencillo como para que la compresión siga funcionando (¡y en la fase del puente funciona muy bien!)

Ahora lo que me pasa es que me parece que la fase 1 es demasiado larga y complicada, pero bueno. Voy a intentar ignorar ese parecimiento. O parecido. O parecer.

~~

Otra idea: puedo montar Mega Meghan con el código que tengo. En The Nine, usando un CHR-ROM extra, por ejemplo.

~~

20160928
========

Fueno, los gráficos están ya hechos, optimizados e importados. Todo listo para empezar a montar la fase. Al final logré hacer un tileset muy chulo usando sólo 30 patrones más. 

Tampoco dejo de pensar que para esta fase a lo mejor convendría que el RLE fuese en vertical en vez de en horizontal. Me ronda la cabeza la posibildad de montar una nueva versión de compresor que comprima vertical y horizontalmente y que luego almacene la mejor versión. También debería almacenar si cada pantalla es horizontal o vertical.

El tema es que así a lo mejor lo que gano comprimiendo lo pierdo en lógica de decidir que descompresor usar, además de tener que tener dos descompresores (o programar de forma muy inteligente).

~~

Mientras tanto voy a ver si puedo montar fácilmente Lala Lah sobre la ROM de Monono / Jet Puri. Vamos a hacer una lista de comprobación / tareas:

```
    - Tileset, componer: 
      * Fuente
      * Cuerpo
      * Título / Final
    - Spriteset, componer:
      * blau
    - Mapa.
    - Enems.
```

El mapa tiene decos, aunque puedo intentar comprimirlo con el RLE a byte a ver si ocupa menos que packed con decos, y así me ahorró código. Por lo pronto voy a ir preparando los pngs y las paletas.

~~ 

Stopped once again entre mil miradas coñazas.

~~

Me acabo de dar cuenta de que los mapas de monono y lala lah comprimen fatal en rle, así que los voy a cambiar a packmap.

20160930
========

Con un poco de trabajo, Lala Lah migrado. Tengo que dejarlo fino y retocar cosas. Ahora tengo que pensar como voy a incluir esto en el paquete. ¿Secreto haciendo algo muy raro pero que sea posible que alguien lo haga? Lo pensaré.

Por lo pronto he montado la música murciana en la ROM de Sonic Mal. Le ha quedado perfe. Ahora tengo que hacer la fase de la cascada rápido. Las fases verticales de subir se hacen en un peo.

Se me ocurrió la paranoia de emplear la ROM de Tontis (con el mapa de Rendevous) y otro CHR-ROM extra para hacer un scrap brain zone mal para Sonic Mal, pero probablemente no lo haga por agotamiento. Estoy exhausto y ni siquiera he empezado el Ramiro.

Lo que más me cansa es hacer mapas. 

Ramiro será un mapa de 16 pantallas de ancho por 2 de alto, pero no funcionarán como dos pisos sino como dos planos paralelos, de forma que se pase de uno a otro por puertas. Supuestamente en uno habrá pasillacos y en otro habitaciones pequeñas. Lo suyo es que cambiase la orientación (si la puerta siempre está al fondo, cambia la orientación de L-R a R-L del mapa), lo cual es sencillo de implementar aunque quizá sea más coñazo que diseñar (porque las tiras no van a casar y habrá que fijarse muy bien donde poner la puertas: ¡el tile 10 de la tira 1 comunica con el tile 245 de la tira 2!).

Tengo que leer el hilo que dejó Ángel en mojonia hace eones. Creo que él decía de matar a todos los bichos pero creo que puede ser más interesante si hay que ir recogiendo objetos y tal, o si me invento algo que obligue a recorrer el mapa de arriba a abajo varias veces. Buscar las bragas de la duquesa siempre es una tarea interesante. Una buena forma de obligar a hacer algo de backtracking es empezar la fase por la mitad. La tira de habitaciones anexas serviría para contener los objetos en pequeñas habitaciones o para dar un acceso alternativo a partes del nivel "pasillo" que estén bloqueadas.

Haré un esquema en papel con toda la fase y conexiones. No es muy larga, debería tenerla lista pronto. Al final el juego será chulo.

Tiraremos pelotas de tenis (hasta 3) y dejaremos a los enemigos paralizados. Para recuperar habrá recargas en las habitaciones interiores que se regenerarán ~ lo suyo es recordar la última que se recogió y no regenerar esa. Así parece que la regeneración tarda si no sabes cómo funciona internamente. Es muy buen truco y suele funcionar. ¡Engañar al Chamán!

Creo que aunque no pueda hacer nada en algún tiempo lo suyo es que vaya cogiendo los tiestos y ordenando un poco. Pillaré también el motor de Sir Ababol Remastered, que es sobre el que voy a construir este juego.

Dejo estas ideas macerar tranquilamente. Me gustaría dejar pulido el Lala Lah y hacer la fase nueva de Sonic Mal antes.

~~

Otra cosa que debería ser viable es invertir Lala Lah con otro tileset para tener PPPP. Habría que:

1.- Añadir código al interpretar los enemigos desde la ROM (y1/y2 = 11 - y1/y2).
2.- Añadir un modo de juego de gravedad y saltos inversos.
3.- Añadir código al interpretar hotspots desde la ROM (y = 11 - y).
4.- Añadir código al detectar cerrojos (y = 11 - y).

Podría ser XD Ahí lo dejo. Cuando Lah esté al 100% me lo planteo. Ahora tengo que corregir un poco el mapa.

20161003
========

Durante el poquísimo tiempo que he podido dedicarle el fin de semana he hecho los gráficos que necesito (en principio) para el menú. Creo que lo suyo es que me ponga ya a hacer el menú:

- Dejo espacios para las cosas que aún no están. Es necesario controlar bien el orden.
- Tengo 30 lineas de caracteres. 28 visibles en NTSC. 26 con seguridad.
- El rótulo tiene 32 pixels de alto, 4 lineas. Quedan 24. En principio había pensado en 8 titulos por página, así que me cabe un footer con CopyDown Xin Xin & Mojon Twins o algo así.

Voy a rellenar un poco más los menús, teniendo en cuenta la escaleta (y lo pego otra vez):

```
    PRG WHAT                                CHR WHAT                                CHR WHAT
    0   Menu                                0   Menu                                8 Jet Puri extra
    1   Monono / Jet Puri / Lah / PPPP      1   Monono / Jet Puri                   9 Cheril of the Bosque mapa 2 / Bits
    2   Bosque                              2   Bosque                              A Rendezvous extra
    3   Pantanow                            3   Pantanow                            B Lah / PPPP
    4   Sonic Mal                           4   Sonic Mal                           C
    5   The Nine                            5   The Nine                            D
    6   Tonterías                           6   Tonterías                           E
    7   Leovigildo                          7   Leovigildo                          F
```

Al menú puedo ponerle el Dune Buggy de Oliver Onions que hay por ahí a falta de algo mejor.

~~

Bueno, el menú apañao. Qué bien, lo he hecho en un peo y sin cagadas ni bloqueos. Hoy he estado ágil. Ahora tengo que ver que hago. Debería hacer una recopilación de las ideas peregrinas y cosas que sé que tengo que hacer:

- Terminar de colocar los enemigos de Pantanow y hacer al menos pantallas de título, game over, y final.
- Hacer gráficos, mapas, y enemigos de Desiertow y Azoteaw.
- Comprobar que Lala Lah se puede terminar. Terminar el pixel art para la pantalla de título. Hacer una pantalla de final muy tonta.
- Hacer gráficos para PPPP y las modificaciones necesarias en el motor.
- Hacer gráficos para un rollo monona con algún personaje gregario que haya por ahí y una paleta de colores extrema. Usaré la CHR-ROM 0x0b, o la 0x01 (quedan 33 patrones libres en el banco 0, podría optimizar los logos y pillar más).
- Hacer gráficos y mapa del barco para el Nine alternativo en el barco. Montar.
- Hacer el mapa de la jungle zone de Sonic Mal. Hacer una pantalla para elegir fase.
- Mega Meghan en la ROM de The Nine? Sería muy sencillo. Quizá más sencillo que lo de la fase del barco pirata.
- Viaje al centro de la Napia en lo que queda de tontis. Buscar sitio en los sets, a ver qué queda. Aún tengo 4 CHR libres.
- Vigirdo. JA JA JA.

Creo que lo más fácil y/o factible ahora mismo (mentira, lo que más me apetece, siempre se hace lo que más le apetece a uno) es el PPPP. Los sprites están básicamente hechos (le doy la vuelta a los de Lala Lah y no van a ocupar ni un puto patrón extra, mua ja ja), y los tiles prácticamente. Gráficos mierdew y rarow y listo.

20161005
========

Ayer no escribí, pero hice cosas: PPPP está listo, a falta de probar y de hacerle pantalla de título y final. Lala Lah necesita una pantalla del final. Creo que será con lo siguiente que me ponga. Para PPPP he hecho un sprite muy chulo. Llenaré el título de texto y haré flotar el sprite. Para el final, casi que lo mismo. Puedo poner escenas fijas tontas como en el resto de los juegos. Ya veré. Voy a ello.

~~

Bueno, todas las pantallas fijas de la ROM1 están listas. Monono / Jet Puri / Lah / PPPP está terminado a falta de probar Lah (porque PPPP es el mismo mapa, no hace falta probarlo).

Ahora a seguir cerrando cosas. Las ROMs 1 y 2 están al 100% (a falta de probar). ¿Por dónde sigo? ¿Pantanow o Sonic Mal?

20161007
========

Tengo que decidir por dónde tiro hoy, que puede que pueda (!) echar media hora. Lo malo es que todos los trabajos que faltan implican hacer gráficos, en mayor o menor medida, y eso lo tengo realmente chungo últimamente con tanta miradita. Me apetece mucho empezar Vigirdo, pero eso prefiero dejarlo para el final y dedicarle toda mi energía. O al menos dejarlo para cuando sólo me quede terminar la ROM 3 (PantanoW, etc) ;-)

Cosas que me apetecen: Monona (necesitaría pintar a la chica), Viaje al centro de la napia, el barco de Cheril the Nine. En este último además habría que hacer mapa y colocar enemigos, demasiado trabajo gráfico. Uf. El que menos trabajo tiene sería ahora mismo Monona. Voy a ver qué se me ocurre, voy a tirar de personajario.

~~

Apuntes para meter monona. Estoy cambiando el código, pongo lo que faltaría por definir:

```
    CELL_MONONA
    mypal_game_bg6
    mypal_game_fg6
    ts4_pals
    ts4_tmaps
```

Con un poco de maña y con algunas cosas por retocar, Monona está funcionando. Activada en el menú. El sprite de la protagonista, Monona la Campeona (de lucha libre) me encanta, por cierto.

20161008
========

Voy a usar la CHR-ROM de "Jet Puri Extra" para meter pantalla de título y final de Monona. Si mal no recuerdo estaba prácticamente vacía ~~ sep, me quedan 98 patrones en el banco 0 y todo el banco 1 (ahora hay de placeholder una copia del banco 1 de la CHR-ROM 1, pero no se usa). Puedo hacer dos buenos dibujos de Monona, la campeona (de lucha libre). Voy a dibujar un ratico.

~

Ni un rato he tenido. A ver si tengo fuerzas para después de la cena. He hecho uno de los dibujos pero no he diseñado la pantalla.

~

Al ponerme a montar la pantalla de título de Monona me quedé sin espacio en la ROM. Demasiadas cosas metidas a cascoporro. Tras un poco de optimización logré colarla (en el proceso tuve que pasar a RLE las pantallas de título de Monono y Jet Puri, que estaban a metatile - a mano con nesst. Definitivamente, tengo que meter soporte para convertir pantallas completas y comprimirlas en RLE con el mismo formato que Shiru de forma automática). Aún hay cosas que optimizar: estoy empeñado en meter también una pantalla del final. Hice un dibujo chulo y quiero usarlo.

20161009
========

Voy a usar un ratico que tengo para intentar afeitar unos bytes más de PRG-ROM1 para poder meter la pantalla de final de Monona Ninona Pana. ~~~~~ he liberado bastante pero la verdad es que MK2 está tan bien optimizado de entrada que cuesta. Voy a intentar meter el gráfico nuevo con lo que he liberado. Pero antes tengo que pixelar sobre el dibujet :D

20161010
========

Dibujet pixelado y metido. Ahora ya me he quedado tranquilo, la ROM1 la considero completa (a menos que se me ocurra meter música... Volver a la original de Davidian para Monono, sin mis mierdas de ampliaciones, liberando algo de espacio, y meter un loop tonto para Lah/PPPP). Mierda. Ahora quiero hacer eso. Bueno, pero lo dejo para más adelante.

- Terminar de colocar los enemigos de Pantanow y hacer al menos pantallas de título, game over, y final.
- Hacer gráficos, mapas, y enemigos de Desiertow y Azoteaw.
- Comprobar que Lala Lah / PPPP se puede terminar. 
- Arreglar las músicas de ROM1
- Hacer gráficos y mapa del barco para el Nine alternativo en el barco. Montar.
- Hacer el mapa de la jungle zone de Sonic Mal. Hacer una pantalla para elegir fase.
- Mega Meghan en la ROM de The Nine? Sería muy sencillo. Quizá más sencillo que lo de la fase del barco pirata.
- Viaje al centro de la Napia en lo que queda de tontis. Buscar sitio en los sets, a ver qué queda. Aún tengo 4 CHR libres.
- Vigirdo. JA JA JA.

También me puse a dibujar un set para Mega Meghan. Los sprites me encantan, pero el fondo no. El verde es muy poco oscuro. Quizá tenga que cambiar por el azul cyan oscuro feo ese que en realidad mola - total, es "otro planeta". Pero bueno, con lo que hay puedo montar. Voy a ver de montar y tal y luego ya vemos de mejorar.

Lo de siempre: importo paletas, gráficos, añado conversor para mapa y enemigos, meto soporte multi-juego en la ROM, behaviours, mandangas, y cuando esté todo listo me lío con los cambios de motor.

~~

Problema que hay que resolver: The Nine usa la definición mínima de enemigos (2 bytes) mientras que Mega Meghan necesita la normal (4 bytes). Por suerte sólo hay lineales además de los de tipo 7 (que habrá que modificar con un par de mierdas, quitando generadores y toda la hostia de infested). Tendré que tratar con esto.

~~ 

Fuck, este tenía un montón de patrones usados en mil mierdas. Voy a tener que empezar con uno de los CHR extras que luego tendré que reutilizar. Bueno, asignado queda el 0xC.

```
    PRG WHAT                                CHR WHAT                                CHR WHAT
    0   Menu                                0   Menu                                8 Jet Puri extra
    1   Monono / Jet Puri / Lah / PPPP      1   Monono / Jet Puri                   9 Cheril of the Bosque mapa 2 / Bits
    2   Bosque                              2   Bosque                              A Rendezvous extra
    3   Pantanow                            3   Pantanow                            B Lah / PPPP
    4   Sonic Mal                           4   Sonic Mal                           C Mega Meghan / ...
    5   The Nine                            5   The Nine                            D
    6   Tonterías                           6   Tonterías                           E
    7   Leovigildo                          7   Leovigildo                          F
```

~~

Ayvalahostia... Joder, si se me ha olvidado  hacer sprites de andar parriba y pabajo. Hostia, vaya plan. Pues no puedo seguir ahora. A otra cosa, mariposa.

Pero es que todo lo que queda implica tener abiertas cosas gráficas. Me cago en mi puta calavera. Todo por olvidarme ayer de hacer el puto sprite con las emociones del cola cao. Las emociones del cola cao ¿eso lo sigue diciendo alguien? 

~~

Veamos, montado / añadido:

- Diferencias en el movimiento.
- Hud nuevo.
- Interacción con cerrojos.
- Llaves.
- Tile que te mata.
- Hotspots diferentes.
- Más cosas.

Hay un polstergeist: en cada pantalla un tile del suelo no es traspasable. ¡Que me aspen! Tengo que revisar algunas cosas :)

~~ 

Probando he visto que el polstergeist era 100% determinista. He desactivado los enemigos (que es lo que más trabajo me dará, te lo digo ya) y parece ser que ya se puede pasar....

Espera, ahora estoy recordando: los generadores de enemigos hacen que el tile donde están se ponga sólido.

Joder, es eso. Me cago en mi vida.

~~

Voy a tener que pensar la mejor forma de hacer convivir los dos formatos diferentes de enemigos. Bim.

~~

¡Esto va viento en popa! Se mueven muy chulo. Tengo que quitar la vacilación y añadir el estado de humito cuando aparecen.

~~

Creo que los enemigos de tipo 7 ya van bastante bien. Ahora tengo que:

- Meter los de tipo lineal.
- Darle un poco de age al mapa.
- Ajustar el número de vidas y las recargas.
- Ver la dificultad.
- Meter más malas. 
- Ver que no me he cargado The Nine (¡muy importante! :*D je je je)
- Introducir la condición de terminar: todos los objetos y tocar la TARDIS.
- ????
- Profit!

20161011
========

Voy a meter en un salto los enemigos lineales. Metidos. Poioiong. Y con mejoras generales. 

Hago cosas:

- Tengo que meter, para Mega Meghan, que cuando detectemos una colisión con el tile tipo 1 estando en estado "no registro hostias", no rebote, sólo se pare. Además, reduciré la fuerza del impacto. Hecho.
- Ajustar el número de vidas y las recargas. Voy a poner en principio 5/1. Y luego vemos.
- Condición de terminar.

Tengo que reducir el espacio ocupado por los logos, el fondo del final de The Nine, y los huds. Es demasiado sitio desperdiciado donde podría meter el nivel del barco pirata y tener otra entrada en el menú. Esto implica dibujar todo en el nesst... O programar de una vez un modo automático de conversión en mkts. Aunque no me apetece nada, probablemente me pondré música y le daré al nesst. Paciencia, y poco más.

Calculando, cada hud ocupa, y sin contar el código para pintarlos, 32 bytes de paletas más 128 bytes de tabla de patrones. 288 bytes entre ambos. La pantalla de título, 64 bytes de paletas más 256 bytes de tabla de patrones. Otros 288 bytes. El final, 128 + 512 bytes. En total, 288 + 288 + 128 + 512 = 1216 bytes. Seguro que usando RLE y nesst ahorro algo. Espero, porque es un currele, lerele.

La clave es ver si, en efecto, un hud en RLE ocupa menos de 288 bytes. Hay que tener en cuenta que solo necesito nametable data sin atributos, puesto que los huds van siempre con paleta 0 en ambos juegos.

Pero como siempre, es trabajo gráfico que me cuesta hacer aquí.

~~

Ahora mismo queda meter más malas y ver la dificultad, aparte de crear pantallas de título y final. Y pasar las fijas a rle, claro.

Mejora: de 1606 bytes libres a 2256.

Sinceramente creí que iba a ganar más, pero 2256 está muy bien. Aunque aún hay que apañar música para Mega Meghan :-/ A lo mejor recortando me cabe el barco. Si no, tampoco pasa na, joé.

20161012
========

Descartamos el barco para un futuro en el que The Nine se convierta en un juego standalone. Prefiero meter más cosas en Meghan. Para darle más age, pondré que pueda perder la ropa rollo Uwol y luego recuperarla, pero sólo si te dan los enemigos. En la laba te mueres del todo. He puesto también un hotspot tipo ropa para revestirla. Tengo que retocar los enemigos y hotspots en el PONEDOR (¿dije en el diario que ahora paso de colocador porque tengo un nuevo aliado, el PONEDOWR?).

20161013
========

A ver, cosas: Mega Meghan pierde la ropa y tiene pantalla de título. Quise meterle una super chula con un dibujo de Meghan muy guay que hice hace tiempo pero se me quedó corto de patrones, así que rótulo que te crió y a otra cosa. Tengo que hacer una música y además una pantalla del final. Puedo añadir un sprite de Meghan a un texto (un sprite grande y chulo, quiero decir), como en PPPP. 

Se va amontonando el material que está sin probar. Ayer además vi glitches en los objetos de algún juego mientras sacaba capturas. Tengo que repasarlo todo y apuntar cosas básicas que veo para corregir.

Aparte de esto, quiero meter Viaje al Centro de la Napia pero que ya en la ROM de Tontis y me quedaría todo lo que no se lleve el menú de la ROM0 para meter tonterías y rellenadores del menú.

Otra cosa que no sé si apunté aquí es convertir los Sonic Mal en Espinete, el amigo de los niños, cambiando el sprite. Eso podría hacer bastante risa y me rellenaría un par de slots más en el menú, si no los tres.

Tengo que montar además el mapa de Sonic Mal 3.

- Mega Meghan: Música ingame, pantalla final
- Viaje al centro de la napia: Gráficos, conversión de mapa y enemigos, montar en Tontis.
- Sonic Mal: Mapa/Enemigos de Jungle Zone, montaje (permitir selección de nivel con COMM_GAME_SELECT).
- Espinete: Gráficos, diseño de paletas, montaje (permitir selección de juego con COMM_GAME_SELECT), música ingame (versión infame del tema de Barrio Sésamo).

En la ROM de Sonic Mal, `COMM_GAME_SELECT` será un valor que seleccione dos cosas:

```
    LLLLGGGG
```

Donde LLLL será el nivel (0 a 15, en realidad sólo 0, 1 o 2) y GGGG será el tipo de juego (por ahora, 0 = Sonic, 1 = Espinete). Para el modo Espinete debe cambiar el set gráfico, además de que no podrá hacer spin y que los valores horizontales serán más normales. Así no es sólo un sprite swap, es un juego que se juega diferente. Habrá que cambiar los anillos por otra cosa, eso sí.

GR. Tengo que hacer un porrón de gráficos y me las veo putas para hacerlos aquí. Espero que este fin de semana haya siestas tan copiosas como las que no he podido disfrutar XD Pero va a ser que no.

20161016
========

En la sombra he conseguido apañar más cosas: Espinete mal es totalmente funcional a falta de música. Mega Meghan, prácticamente igual. A ambos les falta también una pantalla para el final.

También tengo que montar Viaje al Centro de la napia. Gráficos hechos, mapas arreglados y enemigos más o menos, a falta de revisar. Voy a implementar el autoshadows de MK1 de Spectrum para este juego, quedará chuli.

~~

Al final no he podido hacer nada.

Pero apunto: ya que estoy con las músicas, tengo que acordarme de meter la música estresante en Rendezvous.

20161017
========

Entiendo que ya tengo todo lo necesario para empezar a montar Napia. El tema es que voy a tener que empezar una nueva CHR-ROM. Se me están acabando, pero igualmente se me está acabando el espacio en PRG. Con que deje una extra como reserva para el final me sobra, a lo mejor para meter algún easter egg en la ROM del menú.

```
    PRG WHAT                                CHR WHAT                                CHR WHAT
    0   Menu                                0   Menu                                8 Jet Puri extra
    1   Monono / Jet Puri / Lah / PPPP      1   Monono / Jet Puri                   9 Cheril of the Bosque mapa 2 / Bits
    2   Bosque                              2   Bosque                              A Rendezvous extra
    3   Pantanow                            3   Pantanow                            B Lah / PPPP
    4   Sonic Mal                           4   Sonic Mal                           C Mega Meghan / ...
    5   The Nine                            5   The Nine                            D Viaje al centro de la Napia
    6   Tonterías                           6   Tonterías                           E Vesta Vaal / ...
    7   Leovigildo                          7   Leovigildo                          F
```

Tras montarlo, he visto que el sprite "se pierde" un poco en los fondos elaborads (que, por cierto, quedan CHULÍSIMOS). Claro que lo estoy viendo en minichiquitito (pixel real en monitor gordo), a lo mejor con un output normal se ve bien... De todos modos me estoy planteando meter algún tipo de sprite overlay extra en baja prioridad (a enviar a la OAM al final). Tengo sprites de sobra y se verá bien. Voy a hacerlo. Un reborde. Un underlay. Pateedeefoos.

~~

Siempre rajo de él, pero voy a intentar implementar un doble salto. Es un juego de banderas, no debería ser difícil. Y quedará guay. Dejaré un humito en el sitio donde ocurra. Esas cosas les molan a los modernos, y el juego es suficientemente difícil como para necesitarlo. 

~~

Ya está todo montado y funcionando, con marco agobiante y gráficos barrocos. Habrá que jugarlo y probarlo para pulirlo, pero básicamente ya está. Ahora debería hacer pantallas de título y final. A ver qué hago. Hay mucho sitio en sprites para cosas chulas.

~~

JOJO - me ha quedado muy chulo. Y aún me queda sitio para otro spritazo para el final.

~~ 

Está quedando muy chulo. Tengo que dejarlo ya, pero quiero meter un resplandor para por debajo de los items o algo asín. Sprites a mogollonaco!. También tengo que poner un texto avisando de que hay que probar el doble salto. Tengo que modificar el mapa para que haya que usarlo más.

Pero hoy ya kaput. Y mañana, probablemente, no pueda darle fran.

20161018
========

Ideas y cosas para que el juego sea más mejor:

- Mirando detenidamente el gráfico de la pantalla de presentación, va a necesitar un par de edits. La cabeza bola (que es lo que parece) debería parecer más un casco desde atrás. 
- Añadir que se pueda saltar sobre enemigos, quizá paralizándolos un rato, o simplemente cambiando su dirección (como en Pong Pong).
- Cuando esté el motor al 100%, ver el espacio que queda en ROM y llenarlo con más pantallas. Anoche pensé en empezar en un agujero del que sólo se pueda salir con el salto doble, a modo de tutorial.

20161019
========

Ayer hice montones de fullerías, entre ellas la música de Viaje al Centro de la Napia usando sólo el canal triangle (más el noise con la batería) y quedó cojonuda :D También puse un destello bajo los objetos que queda chulo, pero en este juego es fácil que se alinéen más de 8 sprites y hay problemas. Creo que lo único que puedo hacer en este caso es rediseñar los objetos y colocarlos en un marco cuadrado, aunque me habían quedado muy chulos. Ya veremos.

~~

Voy a probar qué tal se ve si le doy preferencia al destello del hotspot antes que al borde del jugador. A lo mejor así no tengo que quitarlo.

~~

Queda bien, creo. La colisión a la derecha está chunga, con A=2 glitchea. Voy a revisar [FIXED]

Todo hecho. Voy a meter soporte para cajas de texto, tengo que mostrar un par de hints al principio. También tengo que extender el mapa. Voy a ver cuanto queda . . . 

Phuck. Con tanta mandanga lo he terminao petando. ¿Podré ahorrar espacio de alguna manera? ¿Condensando las funciones de inicialización? Voy a probar. Debería meter además que el conversor de mapas rollo rlebyte pudiese identificar pantallas repetidas y reflejarlo así en el index.

~~

Me estoy dando una pechá de trabajar para ahorrar sólo unas decenas de bytes. Esto no tiene caso, lo tengo ya demasiado exprimido. Ar.

~~

No tiene caso. Quedan unos 330 bytes, y aún no sale la pantalla del final. Me voy a centrar en eso, y luego ya veo qué puede entrar y qué no. Al menos una pantalla más con un "pit" donde empezar necesito.

~~

He montado el final y las dos pantallas extras de mapa y me faltan 139 bytes ahora. O sea, que necesito encontrar 139 bytes para que esto funcione. Creo que tendré que hacer el compresor de mapas que sea capaz de encontrar pantallas duplicadas e intentar explotarlo :)

Pero ahora se acabó.

~~

Resuelto con la modificación al exporter de mapas y haciendo que en rendezvous se repitan un par de pantallas. Ahora hay que arreglar bugs. Lo de los cerrojos de siempre, algun fallo en sprites, y recolocar enemigos en general y modificar el mapa.

A dormir!

20161021
========

Ayer pensaba que no haría nada pero terminé de apañar el Viaje. Ahora está chulo. Sólo hay que probarlo. Me encanta como ha quedado. Me gusta tanto que me estoy planteando convertirlo en un juego completo sobre una GNROM pequeña, como Lala. Pero todavía no.

Voy a revisar la lista de TODOs. Le meteré al Meghan para dejar cerrada la ROM5. Todo, pues:

- Mega Meghan: Música ingame, pantalla final
- Viaje al centro de la napia: comprobar que no me he cargado rendezvous ni potipoti.
- Sonic Mal: Mapa/Enemigos de Jungle Zone
- Espinete: música ingame (versión infame del tema de Barrio Sésamo). Final

20161022
========

Hice la música infame de Barrio Sésamo. Días a ful.

20161023
========

He terminado el mapa de Jungle de Badajoz Zone y he hecho un .ene placeholder prácticamente vacío. Voy a montar a ver cuánto espacio me queda. Miedo tengo, porque quiero:

- Añadir extensiones al renderer para que haga sustituciones automáticas de algunos tiles por otros según el contexto. Así puedo tener más age en mapas de 16 tiles. La cosa es que este juego es RleByteMap, por lo que a lo mejor los puedo meter directamente y aquí no ha pasado nada... Lo pensaré.
- Meter un nuevo tipo de enemigo que no sea más que algo que cae hasta el final de la pantalla a buena velocidad.
- La música de Jungle de Badajoz Zone, que sacaré de la partitura si puedo.
- Añadir un nuevo sprite diferente como plataforma móvil para la fase 3, aunque no es indispensable (si cabe).

~~

No me va a dar tiempo a nada. Al menos a ver si puedo montar a ver cuánto falta.

~~

PEW - ¡Qué bien! Me queda un montón de espacio. Voy con la música, que mañana en la oficina lo tendré puto para ello, pero lo tendré relativamente fácil para fullear con el tema programístico (las cosas que quiero meter).

20161024
========

Empecé a pasar la música. Es laborioso. Precisa notas muy rápidas y está en 12/8 (o mejor en 4x4 con tresillos de corcheas en cada beat). Hay trinos de semicorcheas, por lo que he tenido que hacer que cada negra sean 6 espacios en el tracker, y cada frame de la canción 96 espacios (4 compases de 4 negras). Pero tuve que abandonar por churum on cuando aún había llegado a la variación. En otro momento seguiré.

Tengo que mirar como anda el tema de meter una plataforma nueva. En teoría para el motor es fácil. Quiero ver si es compatible con el estado actual de la tabla de metasprites y modificar el tema si no, para hacer sitio (es tipo linea, que selecciona el sprite base con un nº x 4, así que si la tabla no está alineada a 4 tengo que alinearla o buscar sitio).

¡Está alineado! Se colocarían a partir del índice 24, por lo que el "t" debería ser 0x26.

Hago un tronquito chulo, y lo endiño.

~~

Para el enemigo que sean cosas cayendo lo suyo sería emplear punto fijo y que ganase velocidad, y necesita además una colisión con el suelo. Esto, al ser un movimiento tan específico y limitado, podría tontificarse y hacerse con poco código y ciclos. Pero tengo que penar qué. ¿Una piedra? ¿desde donde aparece?

Podría ser algo que saliese de la cascada y cayese con el agua, como otro tronquito. Pero en ese caso necesitaría estados y paso. Aunque la verdad es que necesito estados de todos modos :-/

Veamos, hay tres estados: saliendo, cayendo, rompiéndose. Uso dos frames, entero y roto. Contador de frames en los estados 0 y 2. Paso de 0 a 1 y de 2 a 0 tras una espera de n estados. Mostramos el sprite roto durante los N primero frames del estado 2. Paso de 1 a 2 cuando haya una colisión vertical por abajo. Es cosa fácil.

En cuanto pueda dibujar los gráficos me pongo con estas dos cosas.

Oh wait, tontolcul, tienes x1,y1,x2,y2 para definir la posición Y EL FINAL del catacrock (que es como se llamará el nuevo tipo de enemigo). No me seas zote, ahórrate las colisiones PRECALCULANDO. Ains.

Para estos enemigos, el atributo del ponedor es el número de semisegundos que se queda "apareciendo" antes de caer. 2 = 1 segundo

~

He programado todo a ciegas. Luego he hecho gráficos, los he montado, y todo funciona perfe. Joder, qué crack XD

Música prácticamente terminada. No tiene percusión, pero me gusta así. Voy a ver cuanto queda, pero Sonic Mal fase jungla está terminado al 100% y ahora me puedo poner a meterle cosas al Espinete. Decía Ignacio de meterle que tirara púas y paralizase malos. Es interesante, pero, como dice la canción "tengo pinchos en la espalda": Las púas (si cabe esto) saldrán desde la espalda.

Creo que no queda demasiado, no sé si podré poner lo de los pinchos. Se intentará, son disparos tontos en una sola dirección (horizontal) y sin colisionar con nada. Y los enemigos que se mueran o algo.

~

Bueno, pues he metido las puás de espinete. Creo que puedo dar por cerrada esta ROM a falta de probar y pulir. Voy a probar si funciona desde el menú.

~~

Mirando mirando:


- a PotiPoti le fallan los atributos de la pantalla de título y Rendezvous está bastante roto. Tengo que revisar los cambios de ahorro que hice mientras incorporaba el Napia a la mezcla a ver si lo vuelvo a hacer funcionar todo . . . Creo que lo he dejado fino de nuevo, pero tengo que revisar el mapa y además hacer que la PRIMERA PRIMERA vez que se juegue aparezcan más o menos juntas, y no en la quinta puñeta.

- En The Nine había un bug y solo se pintaban 3 de los 4 enemigos. La cosa es que el ajuste de dificultad se hizo así. No sé qué hacer con esto. 

- En Mega Meghan hay un misterioso glitch en la pantalla de título.

Y ahora me voy.

20161025
========

Debería ir haciendo "super repasos", al menos en las roms que ya están terminadas. Debería además idear un sistema de cheats que me permita probar el Cheril en otro bosque sin demasiados quebraderos de cabeza.

Por lo pronto hoy quiero hacer que la primera vez que se juegue a Rendezvous se empiece muy cerca, y luego ya empiece el random. Examinaré el mapa para ver cuál es el mejor sitio para hacer esto. Que sea obvio.

~~ 

OK - modificación a Rendezvous hecha. El glitch de la pantalla de título parece haber desaparecido. El modo chungo se activa correctamente. Habría que repasar el mapa, sobre todo la colocación de algunos enemigos... O pasar del tema. Es un multicart chino. Ya veré qué hago. Depende de las ganas que tenga.

Glitches en Poti Poti y Mega Meghan corregidos.

~

La idea además es poner Trabajo Basura y posiblemente Julieta Galáica en la ROM del menú.

~

Ahora mismo sólo queda (de memoria):

- Música ingame de Mega Meghan. Davidian creo que se está encargando de esto.
- Terminar Pantanow. Hacer Desiertow y Azoteaw. Pocas ganas no, lo siguiente.

Tengo que crear un sheet de shit para Josito si quiere hacer Trabajo Basura. Yo haré gráficos raros para la Julieta y veré qué más puedo encasquetar por las otras ROMs, aunque creo que ya está todo petanis.

20161026
========

Josito ha hecho los gráficos básicos de Trabajo Basura. Voy a empezar la integración. Empiezo como siempre expandiendo y arreglando mapa y enemigos. Tengo además que deshacer las decoraciones puestas a mano con el script.

~~

Tileset apañado. Mapa apañado. Enemigos apañados. Voy a construir el spriteset y a añadir a compile.bat la importación de todo. Luego tengo que preparar la ROM del menú para que pueda ejecutar juegos con GS != 0.

~~

Antes de empezar voy a hacer un merge con las ramas de "tontis" y "sonic mal" para juntar pichas. Quiero dejar la versión de MK2 en el menú como la más reciente.

20161030
========

Unos cuantos días sin escribir, supongo, y tal, o quizá solo uno. No tengo ganas de mirar. Terminé Trabajo Basura (Dire Job) - a falta de probarlo y tal. Ahora lo voy a montar en el menú. Sólo quedaba espacio para un juego más y ya me flipé.

Julieta Galaica fue un juego de broma y portarlo sería otra broma... Pero no mola, otro juego asì. Había que darle una vuelta de tuerca y al final me he flipao y se la he dado. Ya no me vale julieta galaica.

En un mapa sencillo, tendremos que avanzar. La protagonista, Vesta Val, tiene dos formas: atleta y guerrera. Una corre mas y salta más. La otra suelta un dragón de corto alcance que puede eliminar a su enemigos.

Los enemigos se colocan como spawners que hacen saltar a tontorrones que avanzan y giran en obstáculo (incluyendo agujero en el suelo). Ya he hecho todos los gráficos y ahora tengo que programar, teniendo en cuenta que el espacio se acaba y tengo que ser MUY conservador.

Luego de esto solo quedará terminar Pantanow / Desiertow / Azoteaw y programar Leovigildo. Estoy al límite de mis fuerzas, pero tengo la determinación de terminar esto sin recortes aparentes. Creo que Navidad es la fecha.

Y pensar que tengo que terminar Lala y PongPong para el concurso... Porque el de las hostias lo tengo abandonadísimo. Si es que no puede ser...

~~

Voy a redibujar el tileset del Julieta Galaica que vaya basura.

~~

Lo he rapiñao de la fase de cristal del Jill. Al final si algún día hacemos Jill va a tener mierda recolocada por tos laos XD

~~

Veamos. Voy a ver qué hacer:

- Mapa y colocar generadores de enemigos. Vaya, lo inicial aburrido de siempre.
- Importar todo. Ojalcuidao que ahora mismo estaba diseñando los sprites sin mirar demasiado, habrá que cambiarlos en el PNG y luego tener la paleta a mano en el motor (Ahora se usan 5 paletas en el PNG, contando las 2 del sprite principal).
- Manejador del nuevo tipo de enemigos. Definir biewn. Porque a lo mejor sí que mola que caigan. Eso precisa una coordenada y en modo real y colisiones. UGH. Al menos las colisiones son solo para abajo.
- Implementar el cambio de movimiento. En realidad tendrían que cambiar casi todas las constantes: AX, RX, MAXVX, AYJUMP, MAXVYJUMP de entrada.
- Implementar el dragón. En realidad es como el paraguas de Zazelle en Sir Ababol. Está medio hecho.
- Colisiones y mierdas.

~~

Enemigos tipo 0x5X, con X = #sprite. En los atributos, meteremos la cadencia en mediosegundos.

~~

Cosas que no sé si funcionarán: De entrada solo se podrá cambiar con la energía llena. Y la energía se llena gradualmente ella sola. Pero ¿Y si esta energía también fuera la que te quitan los malos y si se te acaba te mueres?

~~

Por ahora va funcionando todo, he metido todo lo referente al jugador, pero el juego está quedando feo con avaricia XD. Voy a meter a los generadores de malos y a tomar por saque.

~~

He seguido. Me temo que este juego no va a funcionar nada XD tengo que darle una vuelta.

20161102
========

He dado por cerrado el Vesta Vaal y es medio divertido. Seguramente lo tocaré más. Al final he metido un QR que llevará a una dirección de mojontwins donde meteremos alguna paranoia ocultista que se nos ocurra.

Además, hemos pasado de Leovigildo y en su lugar vamos a hacer un juego rollo 1983 llamado Manquer the Waiter sobre un camarero manco que solo puede llevar una cosa cada vez (y de ahí que sea manco). En principio habrá que coger un cuchillo, ir a la manteca de lomo, huntar el cuchillo, pegarlo al pan, cambiar cuchillo por pan, llevarlo al mostrador, volver a por el cuchillo... etc. 

Cosas:

- Hay que hacer N tostadas antes de que se acabe el tiempo. Por ejemplo, 1 minuto o 90 segundos por fase.
- El número de veces que haya que echarle manteca colorá al pan para que esté listo debe ser variable e incrementar con la dificultad.
- En el menú pone 1983 Mojon Twins.
- Gráficos muy clásicos, rollo Nuts & Milk o como se llame.

Mola!

~~

Quedan seis espacios en el menú, así que hay que inventarse seis mierdas muy fáciles de meter. De entrada:

- Creo que, con todo, Julieta Galáica podría caber, aunque no tenga interés algo es algo.
- En el CHR-ROM de Cheril caben cosas: juegos nuevos de sprites. El problema es que esto necesita espacio y estas roms están petadísimas.

Voy a ver si cambiando el formato de las pantallas de título de Cheril puedo hacer el suficiente espacio como para que me quepa algo más, y plantearme esto.

~~

Cheril, espacio libre: 139 bytes. JA JA JA XD A ver en qué se queda. 

```
                                                                                    139 bytes!
- Por lo pronto me puedo fumar la función un_rle_screen (!) ->                      312 bytes!
- Cambiar p_s por p_s (multiline) ->                                                343 bytes!
- Deparametrizar un par de funciones marginales en special.h ->                     350 bytes! aw.
```

Para cambiar las pantallas tendría que abrir el Nes Screen Tool y ponerme a juntar tiles, lo cual ahora mismo es imposible, así que por ahora tendré que dejarlo aquí. Voy a revisar los sprites, que siempre he podido optimizar ahí... aunque desde la última vez siempre lo hago "bien" y va optimizado desde el principio.

Lo malo de ser cada vez más pepino es que luego hay menos espacio para las optimizaciones XD todo está mondao desde un principio.

20161104
========

Hay que ver que no dejo de inventarme mierdas para posponer tener que trabajar en Pantanow y cia. Es increíble, pero asín es. Voy a intentar rediseñar las pantallas de Cheril ahora en un plis, a ver si puedo, y a ver en cuánto dejo la marca. 350 bytes libres está bien, pero siempre viene mucho mejor tener algo más.

Me cago y me queda. ¡Creo que será mucho mejor que me haga una utilidad que lo haga automáticamente, pardiez! Además dará mucho menos el cante que abrir el NESST y ponerme aponer cachitos a mano.

~~

Un pequeño problema comparando arrays pero por lo demás ¡como un tiro! Convirtiendo pantallas...

~~

Vale hecho. Ahora hay libres... Wait for it... 1926 bytes! ME CAGO Y ME FUCKING QUEDA.

Apunto cosas que he visto y no molan:

- Hay pantallas horrendas en Vesta Vaal. Tampoco tiene mucho por donde salvar, pero que por lo menos no aparezca un enemigo donde debería aparecer una plataforma, vamos hombre ya.
- Cuando se coge el objeto no se acaba el juego pero creo que sé por qué es. Si te sales del mapa las pantallas son divertidísimas, así que no me pondré muy mijita con controlar que esto no pueda pasar XD

20161107
========

Muy lentamente hice muchas cosas de Pantanow. Terminé de poner todos los enemigos de la tira, completé el soporte para multi-nivel, añadí pantallas de título y game over, medio apañé casi todo, y ahora es el momento en el que tengo que definir varias cosas:

- Resulta realista pero parece poco intuitivo que la coordenada X del disparo del personaje principal, cuando mira arriba o abajo, no esté centrada en el personaje. Esto lo voy a cambiar. [X]
- No sé si al final eso de que las enemigas se mueran por "fuego amigo" está bien o hace que el juego se resuelva solo. Quizá debería cambiarlo. [X]
- Pensar si meto vidas extra (el corazón ya está en los patrones y en el metaspriteset) [ ].
- Revisar el "disparo aleatorio", tengo que encontrar una forma mejor y más controlable. Ahora se intercalan intervalos de super cagamiento con intervalos en el que no sueltan nada [ ].
- Revisar el recorrido de las balas por la pantalla, sobre todo el comportamiento de los bordes. Por ejemplo, los enemigos no pueden disparar en vertical en los bordes [X].

Muchos ajustes. Sigo sin tener claro que este juego vaya a funcionar siquiera.

Tengo que pensar en como lanzar los disparos aleatoriamente. Quizá deba tener un contador de tiempo de forma que no se pueda soltar uno si se soltó el último antes de N frames (20, por ejemplo).

~~

He metido todo menos el corazón pero ahora mismo lo tengo chungo para probar. Luego.

~~

He podido jugar poco pero parece que va mejor. Lo que sí he hecho es el set para desiertow, y ahora que me fijo no tengo muy controlado el tema de los comportamientos multi-nivel. Para este necesito que sean levemente diferentes a los de la fase 1, y si no, peo, así que veré cómo lo puedo controlar para que no tenga mucho overhead.

Ya sé: con un puntero que cambie en cada nivel.

~~

Voy a mirar una forma muy sencilla de meter saltos en los scripts de comportamiento. O al menos un RERUN, o algo así, para que empiecen desde el principio una vez finiquitados. Voy a ver el intérprete a ver qué posibilidades hay de un RERUN, si no meteré un GOTO.

Tengo embehptr [enit] que voy incrementando cada vez que leo un nuevo comando (1 byte por comando). Hacer un goto hacia delante o hacia detrás podría ser factible si hacemos:

```
    11 AAAAAA
```

Lo que permitiría retroceder hasta 64 pasos, que creo que sería suficiente. Para hacer un RERUN tendría que almacenar de algún modo el programa que está siguiendo el enemigo en cuestión, lo que precisaría otro set de variables. El GOTO es más fácil de implementar en el motor, aunque complique el compilador, así que será la opción que tome.

El compilador ya está hecho. Procesando el script genero esto:

```
    Pencompiler v0.1 [pantanow edition]
    00            IDLE          8             00001000      08
    Creating Label HERE @ 01
    01            IDLE          4             00001100      0C
    02            LEFT          4             01000100      44
    03            FIRE          PLAYER        10000010      82
    04            IDLE          1             00001001      09
    05            RIGHT         4             01100100      64
    06            IDLE          4             00001100      0C
    07            FIRE          PLAYER        10000010      82
    08            IDLE          1             00001001      09
    09            RETURN        HERE          11001000      C8            -> 01
```

que equivale a este array:

```c
const unsigned char behaviour [] = {
    0x08, 0x0c, 0x44, 0x82, 0x09, 0x64, 0x0c, 0x82, 0x09, 0xc8, 0x00
};
```

Vamos a probar si esto funciona. Ese C8 que rule...

¡¡Funciona genial!! Qué bien, esto me va a venir de fruta madre.

20161109
========

Finales y mierdas chicas hechas entre ayer y hoy. TURRET_FRAMES bajado de 16 a 6, lo que hace más fácil reaccionar para quitarse de enmedio una vez hemos disparado. Tengo que:

- Intentar ver si se juega mejor reduciendo un poco (de 4 a 3) la velocidad de las balas enemigas.
- Cambiar el rate de 1 segundo a algo más. No se puede reaccionar.

También le estoy dando a hacer el mapa de Desiertow. Ar.

20161111
========

Mapa completo, por cierto, super chulo. Ahora es la hora de poner enemigos. Voy a empezar poniendo algunos free roamers en las partes de desierto y algunas torretas putas en la entrada de los edificios. Luego ya me meto a programar comportamientos. Ahora que tengo loops molará todo más.

~~

Moy a modificar el calculador de enemigos para que vaya escribiendo los resultados en un archivo que se le pase como parámetro, que si no es un coñazo.

~~

Sigo que no duermo (!) con lo de que te pares para disparar. Para que eso no ocurra, el valor mínimo que tengo es de 6 frames. Es jodidamente poco, vaya, joder, que son 180 milésimas de segundo. Pero se ve "torpe", no sé, quizá tenga que implementar otro protocolo para bloquear el andar basado en estados:

- Si pulso FIRE, pongo "pturret" a 1.
- Si "pturret" vale 1, no responden las direcciones.
- Si la dirección de DPAD es diferente a la anterior, "pturret" vale 0.

Creo que voy a probar algo así. Al final será para nada, pero creo que es mejor solución. Voy a aprovechar pfixct. "La dirección de DPAD" es (pad0 & 0xf0). Neceisto una variable para guardar el valor anterior.

Hecho y funcionando y no sé si será el típico efecto placebo, pero creo que se juega bastante mejor.

20161113
========

Sigo metiendo de cuando en cuando bichuines Desiertow y creo que sí que es necesario que meta recargas de vida. Quizá meter menos vidas al inicio pero luego añadir recargas.

Las recargas ocuparían un slot de enemigos, tengo que ver si esto es posible (codificar fácilmente y tal). . . .  No, voy a tener que parchear. Si el sprite es 0xF poner a pelaco el tipo "5" o algo así.

Para poner un corazón se debe atender a esto:

```
    238, 0x00, 0x7F,
    Y    PATO    X|
                  |
                  Es un corazon!
```

¡Y corazones funcionando!

20161114
========

Hemos decidido hacer Zombie Calavera Prologue en la ROM 7, teniendo cuidado de que nos quepa el del manco. El mapa de ZC va a comprimir como la puta mierda, por cierto. Hay que ver cómo me lo monto. Para poder meter los dos juegos tengo que hacer ZCP en plan básico en MK2. Mi idea original era hacerlo con el motor de Lala, pero eso impediría que compartiese ROM con el juego del manco.

En Pantanow / Desiertow / Azoteaw voy a meter que si los enemigos se van a salir de la pantalla por arriba se den la media vuelta. También tengo que revisar la colocación en Pantanow y las IAs, que son un poco mierder en general.

20161115
========

He empezado a pasar gráficos, sprite sheets, y demás mandanga. Lo tenemos compliquéited, porque el tileset ya se lleva más de 110 patrones. Estamos empeñados en un logo y un marcador chulos y nos estamos pasando, incluso habiendo añadido sólo los caracteres necesarios para los parcos mensajes que da el juego. Ayer estuvimos un ratazo reduciendo y apañando la pantalla de título. Hoy me tocará retocar marcador y ver que quepa todo.

Por otro lado, los sprites han quedado cojonudos, pero las secuencias de animación para este juego son todas diferentes: los malos no tienen dos frames en cada dirección, sino que miran siempre al frente pero tienen 4 frames de animación. La inicialización será la misma pero la selección de frame cambiará.

Además, la animación de correr se compone de 6 frames (y como es una silueta, ¡equivale a una secuencia de 12 pasos!) por lo que tendré que ver qué me invento para avanzar el frame, ya que no es potencia de 2 y no puedo hacer la fullería que tenía para elegir frames haciendo shifts y módulos.

Lo suyo es que avance más o menos rápido en el cell de animación según este avanzando más o menos rápido por el escenario. No se me ocurre la forma de hacerlo sin hacer módulo 6. Puedo usar una tabla de lookup.

Si hago x<<3 obtengo 32 valores diferentes. Hacer una tabla de 32 módulos 6 no me parece demasiado descabellado.

```c
const unsigned char mod6 [] = {
    0, 1, 2, 3, 4, 5, 
    0, 1, 2, 3, 4, 5, 
    0, 1, 2, 3, 4, 5, 
    0, 1, 2, 3, 4, 5, 
    0, 1, 2, 3, 4, 5, 
    0, 1
};
```

Esto creo que podría valer: `frame_id = mod6 [prx << 3];`

~~

Pero hoy tampoco podré hacer un carajo, parece.

20161116
========

Haciendo el tonto en el telegram, como siempre, se nos ha ocurrido otra tontería: Vamos a meter un modo dos jugadores, por turnos. El segundo jugador será la señora del protagonista (no recuerdo el nombre de ninguno), que aparecerá como una Catrina. El juego será por turnos. La risa es que la Catrina aparecerá en la pantalla que ¡¡QUE SUERTE!! está vacía, dentro de un sitio del que no puede salir. Al menos en apariencia. Sólo podrá suicidarse en unos pinchos (que tengo que añadir al tileset). Puedo poner que por un increíble glitch pueda salir de su prisión. Por ejemplo, si empezamos con inmunidad, que tirarse a los pinchos no la matará, sino que la hará rebotar lo suficiente para colarse por un saliente. Creo que es buena idea.

Ahora tengo que dibujar a la Catrina, pero a ver como lo hago en 16x16. Si uso colores no parecerá que está demasiado oculta, pero eso no me importa a estas alturas del cuento. Creo que usaré blanco para la cara y los brazos y rojo para un detalle en el pelo. De un pixel. Será una flor. Cuadrada.

Lo mejor de todo es que la idea de los dos jugadores ha sido porque Ángel ha hecho un marcador muy estrecho y cabían dos uno junto al otro XD. Me encantan estas cosas.

20161118
========

He hecho un sprite genial para el jugador 2. Voy a empezar a montar esto. Tengo que apañar antes los marcadores y terminar de escribir los conversores. Luego cogeré la versión más moderna de MK2 (la del Menú), la desapañaré de selectores específicos y customs, y empezaré el selector específico para ZCP (con la idea de meter otro juego, probablemente el del manco, en esta misma ROM).

~~

Tengo que poner el scroll a -472 para el juego para que el hud, que es de 4 caracteres de alto, se vea completo en NTSC (y el area de juego más centrada en PAL). DON'T FORGET... BUHITOS.

~~

Ya esta todo mas o menos importado. Antes de empezar quiero pensar en como manejar los dos jugadores. Aunque sea lo último que meta, quiero tenerlo pensado antes para no tener que deshacer alguna programación. Voy a divagar aquí un rato porque así siempre se me terminan ocurrendo soluciones geniales.

A ver, en el cambio de un jugador a otro debo tener en cuenta que el numero de vidas y objetos puede variar.

20161121
========

He hecho cosas pero escrito poco. Zombie Calavera "básico" está casi casi, faltan detallitos. Creo que necesito animar los hotspots para que destaquen un poco más, o colocarles detrás un halo parpadeante. Voy a probar con eso último.

Luego modificaré la pantalla de título e intentaré empezar a meter soporte para María. María no dispara, sino que planea con la falda. Necesito además meterle alguna otra habilidad o el juego estará muy descompensado. Pero bueno, ya de entrada tiene que salir de un sitio glitcheando, así que... XD

También tengo que modificar los atributos para que el hud se pinte con la paleta correcta (la 2).

~~

Título con selector y otros miniarreglos hechos.

~~

Bueno, ya está el modo María. Es un poco tosco todo, no sé. Algo me falla. Supongo que tendré que echar una partida profunda y tal para identificar qué se puede mejorar y, sobre todo, si la dificultad está bien ajustada.

Ah, y tengo que meter los relámpagos y los truenos. Necesito un sonido chulo que no sea un coñazo.

~~

Hecho y queda chulo. Al juego le falta algo de música, ya veré qué sale. Mientras tanto, veo que en Sonic puedo ahorrar algunos bytes más y, en mi cruzada por encontrar formas de rellenar del todo el menú del multicart con tonterías, voy a ponerme a ello con la idea de producir algo que haga mucha risa. La cosa es que creo que es la octava vez que le pido ayuda a los otros mojon twins y pasan de mi.

20161122
========

ZCP mucho más pulido. ¿Meto un Somari Mal en la ROM de Sonic? Para ello tengo que liberar espacio quitando el encoding mierder de la pantalla del final y ver qué puedo hacer con la pantalla de título.

~~

```
Empezamos:                      252 bytes libres.
Cambio pantalla titulo/final:   512 bytes libres.
Limpio funciones sin usar 1:    855 bytes libres.
```

20161123
========

Ayer en un ultramaraton de media hora puse a anda Somari. Es muy divertido porque le he dado la vuelta a la orientación de las fases de forma que ahora hay que ir a la derecha en el puente y hacia abajo en la jungla. En el puente da igual, pero en la jungla es saltar a tumba abierta de pantalla en pantalla, así que he puesto un cartel de "MEMORY GAME" XD

Lo malo es que me he vuelto a quedar a full y no he puesto pantalla para el final de Somari (y la pantalla de título asusta de lo cutre que es). Tengo que ver cómo liberar un poco más, pero creo que ya va a estar complicado. ¿Simplificando un poco el mapa?

~~ 

He unido cadenas de texto de varias lineas con el rollo del % y he liberado unos 80 bytes más. Estoy a 140 o así.

20161128
========

Seguimos después de la cacca. Pantanow. Enemigas colocadas. Por alguna razón las que he puesto que salgan por detrás no van.  También se me ha ocurrido poner "level stops": mientras haya enemigos activos el scroll no avanza. ¿Cómo hacer esto?

- Se mete como enemigo. Si se detecta que llega un "level stop", se pone el flag "scroll_lock" a 1.  [*]
- Si "scroll_lock" == 1, no se scrollea. [*]
- No se puede avanzar más allá de cam_pos [ya estaba *].
- Al matar un enemigo, si "enems_count" == 0 -> "scroll_lock = 1". [*]
- Tengo que meter un enems_count si no lo hay. [*]

Con esto andando, tengo que colocar los "locks" luego de lanzar varios enemigos importantes. Se deja que se maten y luego ya se libera.

Hay que tener cuidado con esto. Tendría que volver a Pantanow para meterlo, aunque quizá lo suyo es dejarlo como está ya y dejar de marear la perdiz que esto se está eternizando. Por lo pronto lo meto en Desiertow...

¡Y veo qué les pasa a las niñas que aparecen por detrás! Seguro que las creo en mal sitio y se autoeliminan directamente...

~~

Puedo sacar el numero de elementos activos mirando el índice de los slots para enemigos, pero es una tonteriez meter tanta castaña cuando una puta variable extra es tan barata.

~~

Meter un level_stop: 

```
    238, 0x00, 0x0E,
    Y    PATO    ~|
                  |
                  Es un level stop!
```

Pero antes de meter alguno voy a probar que todo sigue funcionando tal cual. ¡Y a ver si he arreglado as las niñas traseras!

~~

Esto funciona super bien. Creo que con esto puedo dar carpetazo a Pantanow. Tengo que ver si se puede acabar. Voy a trampear. Player inmune y a probar.

~~

Mientras tanto, cuando no miren mucho tengo que simplificar alguna pantalla del Sonic Mal para ahorrar más bytes. Seguro que un par de mierdas pueden salvar un montón. Veré qué pantallas ocupan más y las tontificaré.

~

```
Empezamos:                      146 bytes libres.
Tontificar level0.map:          265 bytes libres (+121).
Tontificar level1.map:          404 bytes libres (+139).
```

Lo cual está cojonut. Con eso tengo para un final para Somari.

~~

BUG TORRETAS PANTANOW :: Pasa algo raro con las torretas. Se nota en las torretas del final y en una que hay en el lab 2 de "Desiertow". Las balas salen para donde no es. ¿Pasa si estamos a ras de cam_pos? Me da la impresión de que sí. Voy a revisar todo el código torretero.

Las torretas en cuestión tienen estos datos en el strip:

```c
    138, 0x02, 0x12,
      1, 0x02, 0x72,
      1, 0x02, 0x82,
```

Las torretas que parecen ir bien son asín:

```c
    151, 0x02, 0x12,
    151, 0x02, 0x22,
```

Por lo que por los trastos de configuración no va a ser.

Um. A ver como se mueven las torretas. ¡Ingeniería inversa de mi propio código ON! Eso me pasa por dejar los desarrollos a la mitad...

Qué misterio, la dirección de disparo es la típica y parece ir bien siempre:

```c
    // Towards player
    rds = prx < enx [enit] - 32 ? -1 : (prx > enx [enit] + 32 ? 1 : 0);
    rdmx = ADD_SIGN (rds, BULLETS_VE);
    rds = pry < eny [enit] - 32 ? -1 : (pry > eny [enit] + 32 ? 1 : 0);
    rdmy = ADD_SIGN (rds, BULLETS_VE);
```

Lo cual, por cierto, es una mierda, pero bueno. Debería disparar, pero parece que lo hiciese en dirección contraria. Joder qué raro.

~~

ESPERA

Las que funcionan son estas:

```c
    233, 0x03, 0x72, 
    233, 0x03, 0x82, 
```

Ese 0x03 es 

```
    MMMCCCDD
    00000011
```

DD = 11 significa "hacia tí, cada segundo". Aunque debería funcionar, no? 10 debería significar "hacia tí, aleatorio". Fuck, eso está bien, no tiene nada que ver. Seguimos...

~~

A ver, en el que sale dentro del labby 2, o sea, 

```c
    138, 0x02, 0x12,
```

En principio izquierda y derecha no las detecta bien para nada. El sprite siempre sale ARRIBA o ABAJO - Bueno, voy a mirar mejor, porque izquierda o derecha solo sale si la alineación es total. Si, nada, no me eches cuenta, eso está bien

Pero las pelotas siempre salen hacia la izquierda, nunca a la derecha. Cuando estoy abajo si las tira para abajo, parece que la dirección vertical, en este caso, está bien, pero la horizontal no! Misterious.

Hm.

Creo que el tema es este: el 32. Eso lo casca todo. enx [enit] - 32 se va porque enx [enit] es unsigned. Lo mismo pasa con las torretas con Y = 1, que no funcionan en vertical.

Castaña, vaya tela. Lo vi. Voy a solucionarlo. Nunca aprendo. Cuidado con las restas! Hay que dar la vuelta en la desigualdad:

```c
    // Towards player
    rds = prx + 32 < enx [enit] ? -1 : (prx > enx [enit] + 32 ? 1 : 0);
    rdmx = ADD_SIGN (rds, BULLETS_VE);
    rds = pry + 32 < eny [enit] ? -1 : (pry > eny [enit] + 32 ? 1 : 0);
    rdmy = ADD_SIGN (rds, BULLETS_VE);
    ```

¡Y listo!

20161129
========

Final del Somari metido. Me quedó un dibujo chulo aunque tuve que repetirlo porque se cerró Photoshop porque sí cuando tenía hecho la mitad (el sprite de la chica a la cual pondré nombre). He hecho además que, al azar, salga un final "alternativo" con otro texto más jocoso. Debería ser complicado que te salga, sobre todo teniendo en cuenta que el juego es un poco peste y pocos se lo acabarán. Pero me encanta esconder mierda.

Hablando de mierda escondida, al final de Vesta Vaal sale un QR que te lleva a una URL de mojonia pero aún no hemos pensado qué esconder ahí. Además, en este juego, hay un glitch enorme: te puedes salir del mapa en la primera pantalla, y si logras avanzar algunas pantallas hacia la izquierda sin que se cuelgue, sale el final directamente. Muy glitch. Mola.

Ahora voy a poner puntos de stop en Pantanow y alguna recarga de vida, y daré por cerrados Pantanow y Desiertow, volveré a hacer lista de tareas (exhaustiva), y subiré al forro.

Se amontonan los juegos que hay que probar, pero veo que como no lo haga yo...

~~

También hago que los corazones no incrementen ni decrementen la cuenta de enemigos. Esto es importante! No coger un corazón no debería bloquear el scroll... DONE

20161202
========

Sacamos Lala, y ahora empieza la cuenta atrás para terminar esto. Y aún así se me siguen ocurriendo mierdas. Blip Blep y el movimiento choco. El juego del choco debería llenar un cachito que queda en ROM 1 y entonces yo ya estaré tranquilo.

También tengo que anunciar a estos que el día 25 quiero sacar el juego y que no espero más. Si sigue así tendré que encargarme yo de hacer lo que tenían que hacer o directamente desechar juegos.

~~

IDEAS: Rom de cheril, "Drunk". Aprovecho gráficos, cambio paletas. Meter un "emborrachador" de movimientos:

```
    * pvy != 0 -> px +- rand. 
    * pvy != 0 -> py +- rand.
```

Voy a ver como es el selector de Game Mode para meter esto con el menor código posible.

Es muy básico. Una variable controla el juego, otra el jugador.

- level = 0, 1 o 2. Fases bosque original (0, 1), otro bosque (2).
- pcharacter = CELL_NINJAJAR : CELL_CHERIL.

Tengo que meter un level 3 que se comporte como "level 1" pero en borracho. Muy fácil de pinchar.

~~

Ninjajar drunk hecho. Ya meteré más efectos si al final no hay nada más para esta ROM y me quedo con sitio. Voy a añadirlo al menú.

20161205
========

Aunque aún quedan bastantes cosas por hacer, voy a empezar a pulir algunas aristas. David está haciendo músicas y yo voy a dejar más jugables algunos juegos. Además ayer vi con horror que las muñecas de Pantanow/Desiertow dejaban de echar bolas, así que tengo que asegurarme que los disparos se estén desactivando correctamente.

Ángel me ha propuesto que unamos los tres pantanow/desiertow/azoteaw en un solo juego de tres fases con Sgt. Helmet. Me parece una idea cojonuda. Tenemos que pensar en un buen nombre.

Voy a echar un ojal a pantanow y luego a ajustar mega meghan.

~~

Pantanow, creo que el problema estaba en casos marginales que se daban cuando la parte comentada (es el arreglo) estaba sin comentar:

```c
    if (
        (attr ((bx [bit] + 4) >> 4, (by [bit] + 4) >> 4) & 8) ||
        (bmx [bit] < 0 && bx [bit] < rdb) ||
        (bmx [bit] > 0 && bx [bit] > 248 - rdb) ||
        (/*bmy [bit] < 0 &&*/ by [bit] < camera_position) ||
        (/*bmy [bit] > 0 &&*/ by [bit] > 240 + camera_position)
    ) {
        bullet_free (); continue;
    }
```

Esperemos que sea por eso. Ahora tengo que currarme Mega Meghan.

20161206
========

Dice Raúl que se le sigue quedando parado en pantanow y desiertow. He jugado mil veces ya con fceux y "matrix" activado para ver si cazo algo pero no consigo que se me joda. No me pasa, no sé qué hacer. Seguiré probando insisitentemente.

Lo mismo pasa con el meghan. A mí se me quedaba en negro (bueno, me pasó dos veces) al entrar en una pantalla específica. Raúl decía que se le quedaba en negro pero creo que ha sido en otra pantalla. Como en el caso de pantanow / desiertow, hace días que no consigo reproducirlo. Lo sangrante es que en este no he tocado nada ni he hecho nada por arreglarlo. Algo tiene que pasar a veces antes de entrar en la pantalla que conduce a un bucle infinito. Tengo que revisar todas las mierdas.

~~

Ya lo vi, gracias a una partida grabada de Raúl. Mirando mucho mucho mucho me di cuenta de que podría ser que se entrase en el bucle de los enemigos empezando por un enemigo de los no activos, y que los valores aleatorios de la RAM no inicializada podrían estar activándose para cosas de Cheril the Nine e intentando dibujar sprites que no estaban definidos, pintando cualquier mierda que encontrase en la ROM y llevando, muy probablemente, a un crash o un bucle infinito.

Al final de enems_load:

```c
    if (game_meghan) {
        en_dying [3] = en_gen_dying [3] = en_washit [3] = en_t [3] = 0;
    }
```

Creo que lo he reparado, pero habrá que jugar hasta ver que no vuelve a salir (!).

20161207
========

Hoy creo que day off... No me apetece hacer música, así que voy a jugar con otros proyectos, como Isshokutta o Wo Xiang Niao Niao.

20161209
========

Anoche por fin di con el bug de Mega Meghan. Era una carambola increíble que se daba solo en cierta pantalla, pero el fallo era gordo: al esquivar un enemigo eliminado a la hora de crearlos al entrar en una pantalla, saltaba 2 bytes cuando deberían ser 4. En modo The Nine, cada enemigo ocupa 2 bytes en la tabla y estaba bien... Pero en modo Meghan cada enemigo ocupa 4.

Me ha tomado días darme cuenta y repararlo.

Ayer, en la desesperación pensamos en simplemente esquivar esa pantalla modificando el mapa XD O de quitar los enemigos y meter un segundo QR. 

Arreglado el fallo, aún quería seguir metiendo el segundo QR... Pero me he puesto, he ampliado el mapa, he metido las pantallas extra, modificado todo, subido el html placeholder a mojontwins, generado el QR... Y ahora resulta que la ROM está petada y que no cabe un colín.

Vamos, es que ni siquiera cabría una música propia para Mega Meghan.

He visto que el mapa de Mega Meghan ocupa un huevo y parte del otro, y todo es porque comprime realmenet mal en RLE. Tengo que ver como meterle candela para ahorrar algo.

Pensemos, porque Churum = ON en breves minutos.

~

Tontificando:

```
* Inicial: 3219
* ->       3157 (62)
* ->       3094 (125)
* ->       3054 (165)
* ->       3000 (219)
* ->       2969 (250)
```

Creo que con esto ya da ¿no?

20161211
========

A cachos, metí el QR y terminé de pulir Meghan. Ahora estoy con Pantanow / Desiertow. Raúl me ha enviado un state con el scroll bloqueado. Voy a ver qué puede estar pasando.

```
    al 00058E ._ena
    al 0000D9 ._encount
    al 000059 ._scroll_lock
```

- Por lo pronto, el ena (enemigo activo)  de los seis enemigos vale 0.
- encount vale 0. Wat.
- scroll_lock vale 1.

Lo acabo de ver.

El desbloqueo del scroll se hace en la función que mata a un enemigo. Lo mata, decrementa la cuenta, y si vale 0 desbloquea el scroll. Pero si la activación del bloqueo se da cuando no hay ningún enemigo activo (porque los has matado a todos antes de llegar al punto de bloqueo) ¡jamás se desbloquea!

Tengo que hacer que si llega el mapa a un bloqueo de pantalla, si no hay enemigos, no la bloquée.

```c
    if (rdc == 0xe0) {
        // Scroll locker!
        if (encount) scroll_lock = 1;
    }
```

Y estos están listos.

Voy a poner cosas en el mapa que ha sugerido Raúl y a otra cosa.

~~

Probando Lah. Está mal codificado el mapa. Al subir de pantalla va adonde no es. MAP_W está mal. Seguramente no esté parametrizado y esté usando el valor de Monono / Monona / Jet Puri. Vamos al líow.

Eso es. 3 en Monono / Monona / Jet Puri, 6 en Lah / PPPP

~~

200 cosas corregidas en el mapa y doy Lala Lah y PPPP por finiquitados :)

20161212
========

Todos los juegos están probados ya menos el Cheril of the Bosque en otro bosque. Pero ese me da toda la pereza del mundo. Seguro que hay que echarle bastante rato, incluso con savestates. Lo iré dejando por ahora.

Tengo que pensar en más tonterías para rellenar menú. Tengo que pensar también en el secreto transmedia al que llevan los QR.

Hace falta un montón de música. Aún no tengo gráficos para Azoteaw.

Voy a seguir pensando idioteces para meter. Claro que puedo meter Julieta Galáica... Con la punta del pijo. Pero no me apetece nada. Además que no sé si hay espacio en algún CHR y el que falta lo quiero reservar para Commando.

También quiero ver si cabría de alguna forma un boss para estos juegos, que saldría al final de Azoteaw. Tengo que ver como va el tema de los patrones libres en sprites, pero no me hago muchas ilusiones.

~~

En la ROM "menu":

-Tileset original: menú y trabajo basura.
-Tileset alternativo: Vesta Vaal, con sitio de sobra para la julieta.

Bueh.

Tengo tileset y paleta de Julieta. Faltaría un spriteset. Pero es que me toca la moral hacer otro juego más de avanzar sin ninguna historia especial. Pero las ideas es complicado ya.

La otra opción es meter Blip Blep muy mínimal para que me quepa el dibujo del choco gayer. Pero eso es hacer un juego de cero.

~~

Idea para mierda en el menú "ALIENS" y poner el Viaje con paletas verdes. O con paletas azuladas y bichos verdes. Vaya baratada. Pero tengo que ver cuánta ROM me queda y ver si cabría. Esto era en la ROM de Tontis.

Apenas queda sitio... A ver, es un palete swap, pero molaría hacer algún cambio más. Por lo menos cambiar el título. Los gráficos va a ser que no, el charset está petado. Este juego tiene SUPER GRAFICOSSS!!

¿Las pantallas de tontis estaban ya pasadas a NesST en RLE? Voy a ver.

~~

Nah. En el caso de este juego las pantallas de título están hechas con tiles del mapeado, así que menos no pueden ocupar. Voy a revisar bien los mapas a ver si puedo ahorrar algo en algún sitio.

~~

El mapa de Rendezvous está super escamondao. El de Napia ocupa un montón, 2563 bytes, pero es que es muy complejo y super bonito. Mira, voy a intentar hacer el cambio de paleta y luego veo con cuántos bytes me quedo y tal. Eso si cabe el cambio de paleta. Voy a ver cómo está codificado el tema de la selección de juegos en este... Ok, plan sencillo. GAME_NAPIA == 2, meto 3 y lo aglutino con excepciones. El trabajo de costumbre.

20151213
========

Hasta dentro de unos días lo tendré chungo para dibujar (muy probablemente), pero bueno - al final me encargaré yo de hacer los graficos para el Cheril The Beginning. La idea principal es poner a Cheril de beberito. Debe ser un juego que puedan jugar niños pequeños, por lo que los malos no te matarán. El objetivo del juego será explorar, conseguir cocos con leche de coco, y darles besicos a los habitantes del Bosque.

Tengo que dibujar a Cheril de beberita, con un mechón verde, a los cocos, y a todos los malos con aspecto más amable. Creo que liberé un buen troncho de memoria, y lo voy a necesitar porque las definiciones de los sprites ocupan su espacio, a lo tonto, y tengo que hacer un set nuevo completo.

20151214
========

Cheril de beberita apañá. Ahora tengo que dar a los enemigos una expresión más amable y diseñar una paleta chula. Tengo que tener cuidao porque he usado DOS paletas en Cheril y eso me va a limitar un poco los enemigos.

~~

Todos los gráficos apañados, junto con la paleta de sprites. Voy a ir importando todo eso y a ver como se va quedando la ROM de espacio... 

~~

Metiendo todo y activando todo, optimizando un poco el selector de nivel, y teniendo todo listo y funcionando a falta del nuevo gameplay, quedan 829 bytes. ¡A lo mejor me da y todo para titulo / fin! XD

20151219
========

El desarrollo se va parando porque cada vez hay menos que hacer y dependo mucho del trabajo de terceros para terminar, pero básicamente todo está probado excepto otro bosque. Otro bosque funciona casi bien pero la detección del final parece que está mal, aparte de que puede que haya algo chungo en el orden aleatorio de los personajes para hablar. Necesito hacer un playthrough en fceux con el visor hex y un par de watches de variables para ver que la pequeña modificación que he hecho funciona. Entonces estará listo.

El resto de lo que queda es:

- Música ingame para Trabajo Basura.
- Música ingame para Zombie Calavera Prologue.
- Música de Pantanow / Desiertow / Azoteaw.
- Azoteaw.
- Montar Commando (Sgt Helmet). Esto pasa por que Azoteaw esté terminado, pero podría ir avanzando porque necesita gráficos y programar toda la lógica de ir pasando fases.

Voy a ver qué puedo ir apañando de la lógica de ir pasando fases del Commando.

~~

Ya está hecho, ha sido un peo. Tengo que hacer una pantalla de título para commando que no ocupe demasiado. Usaré la misma "fuente". Aún no sé cuánto ocupará la música. Con lo del boss se me fue la pitarra, porque con el sprite del título no me quedan patrones *pero* en Commando puede que pueda meterlo porque al ser otro CHR-ROM tendré sitio de sobra. Eso sí, habrá que ver si cabe en PRG la lógica necesaria.

Joer, qué coraje estar parao.

Anjuel me ha pasado su tileset incompleto. Tendré que completarlo y arreglarlo para que tenga algo de perspectiva porque ahora mismo no creo que pueda hacerlo funcionar.

20151223
========

He estado otros días a otras cosas. Pasé Lala the Magical a UNROM con (aparente) éxito.  Monté la fase de la fábrica en el Yun de SMS e hice miles de planes para este juego. Pero ahora vuelvo un ratico a este para actualizar el estado de las cosas y para ver si meto más QRs.

Esta es la lista de cosas que aún hay que hacer para dar esto por terminado:

- Probar de nuevo "Cheril of the Bosque ... En otro bosque" para ver si el arreglo que hice el último día ha corregido el problema de no poder terminarse el juego.
- Meter QR en "Trabajo Basura".
- Terminar el mapa y meter los enemigos en "Azoteaw".
- Hacer gráficos de "Commando", montar pantalla de título, comprobar que el montaje del juego que hice "a ciegas" funciona.
- Música Ingame para "Pantanow" / "Desiertow" / "Azoteaw" (la misma) [murciano].
- Música Ingame para "Trabajo Basura" [murciano]
- Música Ingame para "Zombie Calavera Prologue" [¿yo?]
- Meter QR en "Zombie Calavera Prologue".

No sé aún cómo voy a esconder un QR en ZCP, pero en Trabajo Basura lo haré haciendo que uno de los ordenadores "normales" de la última planta aparezca parpadeando y podamos interactuar con él. Una forma muy chula de meter un huevo de pascua, si me preguntas.

Veamos, el ordenador de marras está en la pantalla 0, posición de tiles (2, 9). No sé si podré reaprovechar el sprite que uso para el terminal principal del juego, creo que no... ¿Hay sitio en los patrones? Sí, de sobra. ¿Puedo hacerlo sin que me vean? Ahora no :-( Voy a asumir que es el siguiente al que uso para el terminal principal y voy a programarlo a ciegas. ssit_tb_04 es el último item (el destello del terminal), así que asumiré ssit_tb_05.

~~

Está medio hecho, pero voy a generar el QR. Veamos, las URL son ya tres:

```
    [eliminado]
```

~~

No hay patrones para el QR en Trabajo Basura, así que tendré que generarlo con el tileset de Vesta Vaal y cambiar el set. Set menú: 0x0, set Vesta Vaal: 0xE

¡Metido y funcionando! Sólo queda ZCP

20161224
========

He metido OGT en Pantanow / etc y queda chuli.

En ZCP quiero meter el QR de pascua, y para ello creo que voy a ampliar el mapa, que queda bastante ROM libre y no me apetece meter juego nuevo. Voy a ver cuanto queda y calculo cuanto meter. El mapa actual ocupa un pasote, unos 2704 bytes para 25 pantallas... Veamos.

Jodó, pepín, me quedan casi 10K, puedo hacer el mapa el doble o el triple. Pero me quedaré con el doble, y pondré pantallas vacías, que si no no terminaré nunca.

Si quiero ampliar el mapa tendré que escribir algo para reubicarme los enemigos, o extender el enresizer.exe para meter un offset inicial (ahora solo añade pantallas a la derecha y abajo).

voy a añadir cinco columnas a la izquierda para hacer un recorrido lineal, y una fila abajo del todo para el secreto.

El mapa será ahora de 10x6, y el offset del anterior deberá ser (en pantallas y tiles):

Pantallas: 5x5 -> 10x6 (5, 0).
Tiles: 80x60 -> 160x72 (80, 0). 

~~

Estoy metiendo tela de pantallas ocultas donde luego pueda esconder cosas chulas. Pero hay que ver lo lento que se va haciendo pantallas para este mapa, joder con el tileset.

~~

Bueno, he hecho un mapa enorme con panallicas secretas tontuelas (puedo meter más si me rayo), y un recorrido muy chulo para llegar a la pantalla del QR. Luego me he dado cuenta de que apenas me quedan patrones, pero creo que para el QR da (coño, son como máximo 16 combinaciones de 2x2 "bits", ¿no? Entonces tengo de sobra).

Mañana generaré un cuarto código QR y lo apañaré. Además tengo que ampliar el enresizer.exe para poder meter un offset a la hora de cambiar el tamaño y meter los enemigos de todas las pantallas nuevas.

~~

Puedo hacer que en las pantallas ocultas salgan cosas diferentes con María. Tengo que hacer lista de lo que se me vaya ocurriendo... Pero antes quiero tener la música. Orden:

- Meter mapa / enems nuevos.
- Música.
- QR.
- Secretos, interacciones en las pantallas ocultas. Diferentes para María y Santos.

~~ 

El resizer ha quedado genial y funcionado como un tiro. Estoy colocando los enemigos (casi está). Tengo que actualizar luego las pantallas de inicio y el MAP_W en el motor, norvidarse.

Y he pensado que si quiero meter secretos, lo más barato es crear más tipos de hotspots, colocarlos en el ponedows, y dejar que sea el propio motor, con hotspots.h, quien sume los sprites necesarios. Ya programaré las interacciones como customs tras la detección de colisión player <-> hotspot.

~~

TODO: Modificaciones de los valores de inicio en el motor. Pero estoy cansado. ¡Buenas noches! ¡Felices fiestas!

20161225
========

Estas son las cuatro URL para el super huevaco de pascua:

```
    [eliminado]
```

Ya está metido el QR y todo funcionando. Voy a pensar qué cosas quiero ocultar en las pantallas secretas. Creo que voy a adaptar levemente la impresión de textos que usé en "... en otro Bosque" para este.

Podría meter a Lala o Ninjajar!, aunque Johnny Limite no debería faltar.

Pero antes debería ir quitándome de enmedio temas más importantes, como Azoteaw o los gráficos de Helmet.

O la música de ZCP.

~~

Voy a montar una primera prueba de Commando. Hago la pantalla de titulo y pestiñer.

~~

He montado Commando.

- ¿Habría que cambiar los tiles? No seh.
- Meter "FASE XXX" antes de cada fase.
- [también en Pantanow / Desiertow / Azoteaw] poner la animación de pasarse la fase, que se me había olvidado que existía.
- Probar.
- Hacer Azoteaw.

Eso, y la música / secretos de ZCP, es lo único que queda (por mi parte) para terminar toda esta mierda.

Jodó, qué ganas.

20161226
========

Se me va la anchoa... Me había puesto a meter cajas de textos en ZCP y justo cuando acabo y voy a probar me acuerdo de que no me queda un puto patrón libre y, por tanto, no puedo escribir textos.

Como mucho puedo meter personajes y cosas en las pantallas secretas que den vidas o hagan paranoias... Y poco más.

20161227
========

Trabajé principalmente en pulir (un poco más) el motor de Pantanow / Desiertow / Azoteaw / Commandow, meter enemigos en Azoteaw y pulir Commandow. Pero aún quedan más enemigos que metel. También tengo que revisar un par de cosas que me dijo Raúl sobre "... en otro bosque". Y no olvidar hacer la portada del multicart y meter los secretos en la web!

20161228
========

Voy a ver si termino de meter la mierda de Azoteaw, que estoy hasta los cullons, y me pongo ya a cerrar esto. ¡Quedan pocos días!

~~

Portada hecha (al menos la parte de delante, no he hecho toda la caja). Enemigos en Azoteaw metidos. Sólo falta pulir alguna cosa que me encuentre, arreglar lo de Raúl, música de ZCP, música de Trabajo Basura.

20170619
========

Volvemos a las andadurías. Esto parece que lo terminará publicando 1985, al menos en una tirada muy corta. Para celebrarlo, quiero cambiar el título para poner 1985 Alternativo, y hacer un regalo añadiendo a la ROM de ZCP un juego extra aprovechando los gráficos. Yun oscuro?

20170721
========

Empecé Yun Oscuro hace eones y está el motor montado al 100%, pero no recordaba el coñazo que es hacer mapas con este set. Pero bueno, poco a poco.

Además estoy arreglando y mejorando un poco cosas que no me gustaban del original. Porque yo lo valgo.

20170723
========

Yun oscuro terminado y adaptado a este Multicart. Hoy me he dado cuenta que por alguna misteriosa razón Sonic Mal y CIA no funcionaba ninguno, y como no me puedo estar quieto me he puesto a restaurar a Espinete y Somari en Sonic Bad (que tiene anillos y fases diferentes).

Pero que hoy lo dejo listo y ya no toco nada más.

~~

Primer paso: separar en fases Sonic Mal y ver que se puede terminar cada fase por separado.

Segund paso: Restaurar Espinete.

Tercer paso: Restaurar Somari.

~~

Restaurando Espinete.
---------------------

Adaptaciones:

- [X] Sprite
- [X] Disparar puas
- [X] Velocidades
- [X] Desactivar spin
- [X] Ocultar anillos
- [X] Game flow (no reiniciar cada vez que mueres)
- [X] Cambiar paletas
- [X] Quitar ringos de Hud
- [X] Música
- [X] Cambiar título
- [X] Ending

Restaurando Somari.
-------------------

Adaptaciones:

- [X] Sprite.
- [X] Matar pisando.
- [X] Velocidades.
- [X] Desactivar spin
- [X] Ocultar anillos
- [X] Game flow (no reiniciar cada vez que mueres)
- [X] Cambiar paletas
- [X] Quitar ringos de Hud
- [X] Música
- [X] Cambiar título
- [X] Ending
- [X] No mostrar cartel. Mostrar seta.
- [X] inicio y final de las fases invertido.
- [X] Memory Somari Text

Y muchas más cosas que nunca apunté.
