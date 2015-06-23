test_minifloat: test.cpp
	$(CXX) -std=c++11 $< -o $@

debug_minifloat: test.cpp
	$(CXX) -fsanitize=address -ggdb $< -o $@

test: test_minifloat
	chmod +x $<
	./$<

clean:
	-rm -rf *.o test_minifloat
