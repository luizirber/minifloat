test_minifloat: test.c
	$(CXX) -std=c++11 $< -o $@

debug_minifloat: test.c
	$(CXX) -fsanitize=address -ggdb $< -o $@

test: test_minifloat
	chmod +x $<
	./$<

clean:
	-rm -rf *.o test_minifloat
