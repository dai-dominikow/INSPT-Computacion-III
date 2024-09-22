# Integración con la Unidad 8: análisis y filtrado de señales.
En principio se pretende obtener una señal sonora (prueba de voz) con el agregado de frecuencia constante a la grabación que ensucia el muestreo. <br>
Luego, la idea es filtrar el ruido utilizando una máscara aplicada a la transformada rápida de Fourier de la señal original, para reconstruir la señal nuevamente sin el ruido.<br>
Para tal fin utilizaremos un sensor MAX9814 y una placa Arduino UNO. <br>
Adjuntas están las señales original y filtrada logradas, así como el código y esquema del microcontrolador, y el código python para transformar la data.<br>