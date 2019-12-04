make: project add compile

project:
	cd ~;
	if [ ! -d public_html ]; then mkdir public_html; fi;   	
	cp binary_converter.c index.html public_html;  
	chmod 755 public_html; 
	cd public_html && chmod 755 index.html && if [ ! -d cgi-bin ]; then mkdir cgi-bin; fi && chmod 755 cgi-bin;


add: 
	cd ~/public_html && git init && git add --all && git commit -m "Files added  successfully"; 


compile:
	cd ~/public_html && gcc -o binary_converter.cgi binary_converter.c && if [ ! -d cgi-bin ]; then mkdir cgi-bin; fi && mv binary_converter.cgi cgi-bin && cd cgi-bin && chmod 755 binary_converter.cgi; 
		



