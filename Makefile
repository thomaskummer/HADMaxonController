CC = g++
CFLAGS = -I. -O3
SOURCE = main
TARGET = HADController
LIBS = -lEposCmd

all: $(TARGET)

$(TARGET): $(SOURCE).cpp
	$(CC) -o $(TARGET) $(SOURCE).cpp $(CFLAGS) $(LIBS)

clean:
	$(RM) $(TARGET)
