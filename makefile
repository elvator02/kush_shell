CC = gcc
EXECUTABLE = shell
SOURCE = shell.c

$(EXECUTABLE): $(SOURCE)
	$(CC) $^ -o $@
	

.PHONY: run
run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
