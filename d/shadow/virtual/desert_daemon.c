#define SIZE 50
#define NUMDESCS 11
#define TERRAINPATH "/d/shadow/virtual/desert/desert.terrain"
#define DESCPATH "/d/shadow/virtual/desert/desert.desc"
#define EXITPATH "/d/shadow/virtual/desert/desert.exits"
#define DESCNIGHT "/d/shadow/virtual/desert/desert.night"

mixed *terrain ;
string *descs, *ldescs, *ndescs ;
mixed *exits ;

void create() {
        int i,j;
        string str, str2, *list ;
        seteuid(getuid()) ;
        terrain = allocate(SIZE) ;
        exits = allocate(SIZE) ;
        descs = allocate(NUMDESCS) ;
        ldescs = allocate(NUMDESCS) ;
        ndescs = allocate(NUMDESCS) ;
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
// added for more appropriate night descriptions *Styx*  2/17/03
        for (i=0 ; i<NUMDESCS ; i++) {

                str = read_file(DESCNIGHT,i*2+1,1) ;
                sscanf(str,"%s\n",descs[i]) ;              
                ndescs[i] = read_file(DESCNIGHT,i*2+2,1) ;
                list = explode (ndescs[i], "/");
                ndescs[i]="";
                if(sizeof(list) != 1)
                     for(j=0;j<sizeof(list);j++)
                        if(j != sizeof(list) - 1)
                          ndescs[i]=ndescs[i]+list[j]+"\n";
                        else
                          ndescs[i]=ndescs[i]+list[j];
                else
                     ndescs[i]=list[0];
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
        if(query_night())           // added to provide night descriptions *Styx* 2/17/03
           return ndescs[i];
        return ldescs[i];
}

int get_exits(int x, int y) {
        int i ;
        sscanf(exits[x][y],"%d",i) ;
        return i ;
}
