CC=g++
TARGET=main

all: main.cpp
	$(CC) main.cpp -o $(TARGET)

run:
	./$(TARGET) eins eins1 eins2 eins zwei drei vier fünf sechs sieben acht neun zehn

clean:
	rm -f $(TARGET)

help:
	@echo Targets
	@echo : clean
	@echo : all 
	@echo : run
