CXX = gcc
CXXFLAGS = -Iheaders -Wall

SRC_DIR = src
HEADER_DIR = headers

SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/process.c $(SRC_DIR)/linkedList.c $(SRC_DIR)/scheduler.c 

OUTPUT  = scheduler

$(OUTPUT): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OUTPUT)
