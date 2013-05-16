CC=/usr/bin/javac

all: F2C.class C2F.class MinZahlen.class DoubleVergleich.class

%.class: %.java
	$(CC) $<

.PHONY:
clean:
	rm *.class
	rm TempConv/*.class
