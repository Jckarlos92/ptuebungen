CC=/usr/bin/javac

all: F2C.class C2F.class MinZahlen.class DoubleVergleich.class

%.class: %.java
	$(CC) $<

F2C.class: TempConv/Fahrenheit.java
	$(CC) $<

C2F.class: TempConv/Celsius.java
	$(CC) $<

#tc: TempConv/Celsius.class TempConv/Conversion.class TempConv/Fahrenheit.class

.PHONY:
clean:
	rm -rf *.class
	rm -rf TempConv/*.class
