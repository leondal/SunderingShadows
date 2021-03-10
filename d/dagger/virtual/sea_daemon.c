#define SIZE 25
#define NUMDESCS 9
#define TERRAINPATH "/d/dagger/virtual/sea/sea.terrain"
#define DESCPATH "/d/dagger/virtual/sea/sea.desc"
#define EXITPATH "/d/dagger/virtual/sea/sea.exits"

mixed *terrain ;
string *descs, *ldescs ;
mixed *exits ;


void create() {

        int i,j;
        string str, str2, *list ;
        seteuid(getuid()) ;
        terrain = allocate(SIZE) ;
        exits = allocate(SIZE) ;
        descs = allocate(NUMDESCS) ;
        ldescs = allocate(NUMDESCS) ;
        for (i=0 ; i<SIZE ; i++) {
                str = read_file (TERRAINPATH,i+1,1) ;
                sscanf (str,"%s\n",str2) ;
                terrain[i] = explode (str2," ") ;
        }
        for (i=0 ; i<SIZE ; i++) {
                str = read_file (EXITPATH,i+1,1) ;
                sscanf(str,"%s\n",str2) ;
                exits[i] = explode (str2," ") ;
        }
        for (i=0 ; i<NUMDESCS ; i++) {

                str = read_file(DESCPATH,i*2+1,1) ;
                sscanf(str,"%s\n",descs[i]) ;
                ldescs[i] = read_file(DESCPATH,i*2+2,1) ;
                list = explode (ldescs[i], "/");
                ldescs[i]="";
                if(sizeof(list) != 1)
                     for(j=0;j<sizeof(list);j++)
                        if(j != sizeof(list) - 1)
                          ldescs[i]=ldescs[i]+list[j]+"\n";
                        else
                          ldescs[i]=ldescs[i]+list[j];
                else
                     ldescs[i]=list[0];
        }
}

string get_short(int x, int y) {
        int i ;
        sscanf(terrain[x][y],"%d",i) ;
        return descs[i] ;
}

string get_long(int x, int y) {
        int i ;
        sscanf(terrain[x][y],"%d",i) ;
        return ldescs[i];
}

int get_exits(int x, int y) {
        int i ;
        sscanf(exits[x][y],"%d",i) ;
        return i ;
}
