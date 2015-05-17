SRC += $(wildcard *.cpp)
SRC_OBJ += $(subst .cpp,.o,$(SRC))

APPS = apps.a
.PHONY: $(APPS) clean

$(APPS): $(SRC_OBJ)
	ar rcs $@ $^

$(SRC_OBJ): $(SRC)
	g++ -c $^ -I../include

clean:
	rm -f *.o *.a

	
 



