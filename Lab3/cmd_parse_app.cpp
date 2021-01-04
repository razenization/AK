#include <stdio.h>
#include <unistd.h>
#include <map>
#include <string>
#include <getopt.h>

using namespace std;

int main(int argc, char *argv[]){
    int rez=0;
	map <string, bool> used;

	int option_index = -1;
	const char* short_options = "hvldcbV::?";
	
	const struct option long_options[] = {
        {"help",0,NULL,'h'},
        {"list",0,NULL,'l'},
        {"version",0,NULL,'v'},
		{"ffa",0,NULL,'f'},
		{"multi",0,NULL,'m'},
		{"aim",0,NULL,'a'},
		{"value",2,NULL,'V'},
        {NULL,0,NULL,0},
    };


	while ((rez = getopt_long(argc,argv,short_options,long_options, &option_index)) != -1){
		switch (rez){
		case 'h': { 
			if (used["h"] == false) {
				printf("Arg: Help\n"); 
				used["h"] = true;
				break;
			} 
			break;
		}
		case 'v': {
			if (used["v"] == false) {
				printf("Arg: version\n"); 
				used["v"] = true;
				break;
			}
			break;
		}
		case 'l': {
			if (used["l"] == false) {
				printf("Arg: List\n"); 
				used["l"] = true;
				break;
			}
			break;
		}
		case 'd': {
			if (used["f"] == false) {
				printf("Arg: FFA\n"); 
				used["f"] = true;
				break;
			}
			break;
		}
		case 'c': {
			if (used["m"] == false) {
				printf("Arg: MULTI\n"); 
				used["m"] = true;
				break;
			}
			break;
		}
		case 'b': {
			if (used["a"] == false) {
				printf("Arg: AIM\n"); 
				used["a"] = true;
				break;
			}
			break;
		}
		case 'V': {
			if (used["V"] == false) {
				if (optarg == NULL) {
					printf("Arg: value\n"); 
					used["V"] = true;
				} else {
					printf("Arg: %s value\n", optarg); 
					used["V"] = true;
				}
				
				break;
			}
			break;
		}
		default: {
			printf("This key is not found\n");
			break;
			}
        };
		option_index = -1;
	};
};
