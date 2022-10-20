arg = null
run: ${arg}.o
	./$<
${arg}.o: ${arg}.cpp
	g++ -o $@ $<

.PHONY: clean
clean:
	rm -f *.o *.out