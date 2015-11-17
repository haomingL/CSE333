.SILENT:

all:
	@cd starterCode && make
	@cd wcClassCode && make
	@cd wcInlineCode && make

	@/bin/echo -e "\nstarterCode:"
	bash -c "time starterCode/wc long.txt"

	@/bin/echo -e "\nwcClassCode:"
	bash -c "time wcClassCode/wc long.txt"

	@/bin/echo -e "\nwcInlineCode:"
	bash -c "time wcInlineCode/wc long.txt"


clean:
	cd starterCode && make clean
	cd wcClassCode && make clean
	cd wcInlineCode && make clean










