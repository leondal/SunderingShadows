
/** -*-C++-*- **
 * forest_daemon.c -- daemon that handles the exits, descriptions, etc for
 *  the virtual rooms in the forest
 *
 * craz@shadowgate -- 9609 -- creation
 *****/
#include <std.h>
#include <daemons.h>

inherit DAEMON;

/* define some macros... */
#define FILE_TERRAIN   "/d/shadow/virtual/level2/level2.terrain"
#define FILE_DESC      "/d/shadow/virtual/level2/level2.desc"
#define FILE_EXITS     "/d/shadow/virtual/level2/level2.exits"
#define NUMDESCS 3

/* prototype some member functions... */
void create();
private void load_terrain();
private void load_desc();
private void load_exits();
string get_short( int x, int y );
string get_long( int x, int y );
string get_exit( int x, int y );
mapping get_terrain();
string *get_short_desc();
string *get_long_desc();
mapping get_exits();

/* define some data members... */
mixed *terrain;			/* the rooms terrain */
string *sDesc;			/* the short descriptions */
string *lDesc;			/* the long descriptions */
mixed *exits;			/* the exits */


/*****
 * void create();
 *  -- apply called by the driver when this object is created
 *****/
void create()
{
  daemon::create();

  seteuid( getuid() );

  load_terrain();
  load_desc();
  load_exits();
}


/*****
 * void load_terrain();
 *  -- fills in the 'terrain' mapping with the data from the terrain file
 *****/
void load_terrain()
{
  string *file = ( string * )SEFUN_D->loadConfig( FILE_TERRAIN );
  string *s;
  int max_x, max_y;
  int a, b;

  /* the first line in the terrain file should be the x & y size of the area */
  s = explode( file[0], " " );

  if ( sizeof( s ) != 2 )
    error( "forest_daemon::load_terrain() -- parse error #1\n" );

  if ( sscanf( s[0], "%d", max_x ) != 1 )
    error( "forest_daemon::load_terrain() -- parse error #2\n" );

  if ( sscanf( s[1], "%d", max_y ) != 1 )
    error( "forest_daemon::load_terrain() -- parse error #3\n" );

  /* allocate the size of the terrain array (y direction) */
  terrain = allocate( max_y );

  /* the rest of the file should be the terrain numbers */
  for ( a = 0; a < sizeof( file ) - 1; ++a ) {
    s = explode( file[a + 1], " " );

    if ( sizeof( s ) < max_x )
      error( "forest_daemon::load_terrain() -- parse error #4\n" );

    /* allocate the terrain entries (x direction) */
    terrain[a] = allocate( max_x );

    for ( b = 0; b < max_x; ++b ) {
      int v;

      if ( s[b] == ".." )
	v = -1;
      else if ( sscanf( s[b], "%d", v ) != 1 )
	error( "forest_daemon::load_terrain() -- parse error #5\n" );

      terrain[a][b] = v;
    }
  }
}


/*****
 * void load_desc();
 *  -- fills in the 'lDesc' and 'sDesc' arrays with the list of descriptions
 *****/
void load_desc()
{
   int i,j;
   string *list, ldescs,str, *descs;
   descs = allocate(NUMDESCS) ;
   ldescs = allocate(NUMDESCS) ;
   for (i=0 ; i<NUMDESCS ; i++) {

                str = read_file(FILE_DESC,i*2+1,1) ;
                sscanf(str,"%s\n",descs[i]) ;
                ldescs[i] = read_file(FILE_DESC,i*2+2,1) ;
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
	lDesc = ldescs;
	sDesc = descs;
}


/*****
 * void load_exits();
 *  -- loads in the 'exits' mapping with the data from the exits file
 *****/
void load_exits()
{
  string *file = ( string * )SEFUN_D->loadConfig( FILE_EXITS );
  string *s;
  int max_x, max_y;
  int a, b;

  /* the first line in the exit file should be the x & y size of the area */
  s = explode( file[0], " " );

  if ( sizeof( s ) != 2 )
    error( "forest_daemon::load_exits() -- parse error #1\n" );

  if ( sscanf( s[0], "%d", max_x ) != 1 )
    error( "forest_daemon::load_exits() -- parse error #2\n" );

  if ( sscanf( s[1], "%d", max_y ) != 1 )
    error( "forest_daemon::load_exits() -- parse error #3\n" );

  /* allocate the size of the terrain array (y direction) */
  exits = allocate( max_y );

  /* the rest of the file should be the exit values */
  for ( a = 0; a < sizeof( file ) - 1; ++a ) {
    s = explode( file[a + 1], " " );
    if ( sizeof( s ) < max_x )
      error( "forest_daemon::load_exits() -- parse error #4\n" );

    /* allocate the terrain entries (x direction) */
    exits[a] = allocate( max_x );

    for ( b = 0; b < max_x; ++b ) {
      int hb, lb;

      if ( strlen( s[b] ) != 2 )
	error( "forest_daemon::load_exits() -- parse error #5\n" );

      if ( s[b] == ".." )
	s[b] = "00";

      /* convert the hex string to any actual number */
      if ( ( hb = strsrch( "0123456789ABCDEF", s[b][0..0] ) ) == -1 )
	error( "forest_daemon::load_exits() -- parse error #6\n" );

      if ( ( lb = strsrch( "0123456789ABCDEF", s[b][1..1] ) ) == -1 )
	error( "forest_daemon::load_exits() -- parse error #7\n" );

      exits[a][b] = ( hb << 4 ) + lb;
    }
  }
}


/*****
 * string get_short( int x, int y );
 *  -- return the short description for the room at (x,y)
 *****/
string get_short( int x, int y )
{
    return sDesc[terrain[y][x]];
  //return sprintf("Short: (%d,%d) == %d", x, y, terrain[y][x] );
}


/*****
 * string get_long( int x, int y );
 *  -- returns the long description for the room at (x,y)
 *****/
string get_long( int x, int y )
{
    return lDesc[terrain[y][x]];
  //return sprintf( "Long: (%d,%d) == %d", x, y, terrain[y][x] );
}


/*****
 * int get_exit( int x, int y );
 *  -- returns the bitmap of exits for the given room at location (x,y)
 *****/
int get_exit( int x, int y )
{
  return exits[y][x];
}


/*****
 * mapping get_terrain();
 * string *get_short_desc();
 * string *get_long_desc();
 * mapping get_exits();
 *  -- these functions just simply return the data members
 *****/
mapping get_terrain()
{
  return terrain;
}


string *get_short_desc()
{
  return sDesc;
}


string *get_long_desc()
{
  return lDesc;
}


mapping get_exits()
{
  return exits;
}
