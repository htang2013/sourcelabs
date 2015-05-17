SRC += $(wildcard *.cpp)
SRC_OBJ += $(subst .cpp,.o,$(SRC))

LIBS = libs.a
.PHONY: $(LIBS) clean

$(LIBS): $(SRC_OBJ)
	ar rcs $@ $^

$(SRC_OBJ): $(SRC)
	g++ -c $^

clean:
	rm -f *.o *.a

	
 



