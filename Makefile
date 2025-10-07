CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -O0 -gdwarf-4 -Wall -Wextra -Werror -pedantic -fsanitize=address,undefined,implicit-conversion,local-bounds -fno-omit-frame-pointer -fno-optimize-sibling-calls -fsanitize-address-use-after-return=always -Wno-error=unused-parameter $(INCLUDES)

exec: bin/exec
tests: bin/tests

bin/exec: ./src/driver.cc ./includes/heat_map.hpp ./src/heat_map.cc ./includes/ocean_navigation.hpp ./src/ocean_navigation.cc  
	$(CXX) $(CXXFLAGS) ./src/driver.cc   ./src/heat_map.cc ./src/ocean_navigation.cc  -o $@

bin/tests: ./tests/tests.cc ./includes/heat_map.hpp ./src/heat_map.cc ./includes/ocean_navigation.hpp ./src/ocean_navigation.cc  
	$(CXX) -std=c++20 -Iincludes -gdwarf-4 -fstandalone-debug -O0 -Wall -Wextra -pedantic ./tests/tests.cc  ./src/heat_map.cc ./src/ocean_navigation.cc  -o $@


.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -fr bin/* obj/*