/* bin:  _more.c */

/* Written sometime by someone
	- loved by Sulam :)
/* Modified Oct27/91 by Jubal
	- added pager function to call more_file
/* Modified Nov3/91 by Jubal
	- tidied up format and arg passing
	- adjusted so that file is not kept in memory (phew)
/* Modified Nov4/91 by Jubal
	- added support for LINES environment variable
/* Modified Dec5/91 by Jubal
	- added more_pipe() to allow paging of strings
/* Modified Dec12/91 by Sulam
	- added code to display_page() to prevent 'over-shooting' things
	- integrated it into the /bin system (involved adding cmd_more())
/* Modified Jan27/92 by Oros
        - added search for regular expression
/* Modified Jan28/92 by Brian
	- added help
/* Modified Jan29/92 by Jubal
	- fixed the security _yet_ again
/* Modified Jun5/93 by Pallando
- inherited DAEMON
*/


#include <std.h>

inherit DAEMON;

#define  SEARCH_LINES  500


private int lines, eof, temp_file;
private int top_line, page_size;
private string fname, swap_file;
private string rem_expr;
private mixed *mark;


int help();
int more_file( string file );
int pager( string file );


private int
get_oid()
{
	string junk;
	int oid;

	sscanf( file_name( this_player() ), "%s#%d", junk, oid );
	return oid;
}


private void
swap_in()
{
	swap_file = "/tmp/moreswap" + get_oid();
	temp_file = 0; mark = 0; rem_expr = 0; eof = 0;
	if( ! restore_object( swap_file ) )
		write( "** Swap file corrupted. **\n" );
	seteuid( getuid( this_player(1) ) );
}


private void
swap_out()
{
	save_object( swap_file );
	temp_file = 0;
	seteuid( "root" );
}


protected void
write_menu_bar()
{
	int max;

	max = top_line + page_size - 1;
	if( max > lines ) max = lines;
	if( fname ) write( fname + "  " );
	write( top_line + "-" + max + " (" + lines + ") " +
		( max * 100 / lines ) + "% (help ?) " );
}


protected void
display_page()
{
	int n, ps;

	ps = page_size;
	if( top_line + ps > lines ) ps = lines - top_line + 1;
	n = cat( fname, top_line, ps );
	if( top_line + n > lines ) eof = 1;
}


protected void
cont_more()
{
	write_menu_bar();
	input_to( "get_more_com" );
	swap_out();
}


private int
get_mark( string str )
{
	int n;

	if( ! sscanf( str, "%d", n ) )
	{
		write( "Format should be \"m#\" where # is mark number.\n" );
		n = 0;
	}
	else if( n > 5 || n < 1 )
	{
		write( "Marks must be in range 1-5.\n" );
		n = 0;
	}
	return n;
}

private int
search_string( string str )
{
        int tmp_line;
	string tmp1;
	string tmp2;

	tmp_line = top_line + page_size / 2;
	tmp1 = read_file( fname, tmp_line, SEARCH_LINES );

	while( tmp1 && sscanf( tmp1, "%s" + str, tmp2 ) != 1 )
        {
	         tmp_line += SEARCH_LINES;
                 tmp1 = read_file( fname, tmp_line, SEARCH_LINES );
        }

	if( tmp2 )
	{
	         while( sscanf( tmp2, "%s\n%s",tmp1, tmp2 ) )
		        tmp_line++;
                 tmp_line -= 2;
		 return tmp_line;
	}
        return top_line;
}


protected void
get_more_com( string str )
{
	int n, cmd;
	int rem_line;
	string path;

	swap_in();
	if( ! str || str == "" ) str = " ";
	if( sscanf( str, "%d%s", n, str ) != 2 ) n = 1;
	if( ! str || str == "" ) str = "G";
	cmd = str[0]; str = extract( str, 1 );
	switch( cmd )
	{
		case 'G':	/* goto line */
			top_line = n;
			break;

		case ' ':	/* next page */
			if( ! eof )
			{
				top_line += n * page_size;
				break;
			}

		case 'q':	/* quit */
			if( temp_file && sscanf( fname, "/tmp/%s", path ) == 1 )
				rm( fname );
			rm( swap_file + ".o" );
			temp_file = 0;
			seteuid( "root" );
			return;

		case '?':	/* help */
			cat( "/doc/etc/more" );
			return cont_more();

		case 'b':	/* previous page */
			top_line -= n * page_size;
			break;

		case 'e':	/* switch files */
			if( temp_file )
			{
				write( "Cannot switch out of a temporary file.\n" );
				return cont_more();
			}
			while( str[0] == ' ' ) str = extract( str, 1 );
			path = (string) this_player() -> get_path();
			str = (string) this_player() -> add_paths( path, str );
			if( ! more_file( str ) )
			{
				write( "File not found.\n" );
				return cont_more();
			}
			return;

		case 'p':	/* switch page length */
        		if( sscanf( str, "%d ", n ) ) page_size = n;
			if( page_size < 1 ) page_size = 1;
			if( page_size > 40 ) page_size = 40;
			write( "Page length is now " + page_size + ".\n" );
			return cont_more();

		case 'm':	/* mark line */
        		if( ! fname )
			{
				write( "Cannot place mark here.\n" );
				return cont_more();
			}
			n = get_mark( str );
			if( n ) mark[n-1] = ({ fname, top_line, lines });
			return cont_more();

		case 'g':	/* goto mark */
			n = get_mark( str );
			if( ! mark[n-1] )
			{
				write( "Mark not set.\n" );
				return cont_more();
			}
			fname = mark[n-1][0];
			top_line = mark[n-1][1];
			lines = mark[n-1][2];
			break;

		case 'n':       /* Search for last r.e */
                        if( rem_expr ) str = rem_expr;
			else str = "";

                case '/':       /* Search for a regular expresssion */
                        if( ! str  || str == "" )
			{
			        write( "\nNo previous regular expression.\n\n" );
				return cont_more();
			}

			rem_expr = str;
			rem_line = top_line;
			top_line = search_string( str );
		        if( top_line == rem_line )
		        {
			        write( "\nNo match.\n\n" );
				return cont_more();
		        }
			break;



		default:
			write( "Unknown command.\n" );
			return cont_more();
	}
	eof = 0;
	if( top_line < 1 ) top_line = 1;
	if( top_line > lines ) top_line = lines;
	display_page();
	cont_more();
}


int
more_file( string str )
{
	string data;

	seteuid( getuid( this_player(1) ) );
	data = read_file( str );
	if( ! data ) return 0;
	swap_file = "/tmp/moreswap" + get_oid();
	fname = str;
	top_line = 1;
	rem_expr = "";
	lines = sizeof( explode( data, "\n" ) );
	if( ! mark ) mark = allocate( 5 );
	data = (string) this_player() -> getenv( "LINES" );
	if( data && sscanf( data, "%d", page_size ) )
	{
		if( page_size < 1 ) page_size = 1;
		if( page_size > 40 ) page_size = 40;
	}
	else page_size = 20;
	eof = 0;
	display_page();
	cont_more();
	return 1;
}


varargs void
more_pipe( string str, string fstr )
{
	seteuid( getuid( this_player(1) ) );
	fname = "/tmp/" +
		( fstr ? fstr : (string) this_player() -> query_name() ) +
		"." + get_oid();
	if( file_size( fname ) > 0 ) rm( fname );
	write_file( fname, str );
	temp_file = 1;
	more_file( fname );
}


void
pager( string str )
{
	more_file( str );
}


int
cmd_less( string arg )
{
	string more;
	object more_ob;

	seteuid( getuid( this_player(1) ) );
	if( ! arg || arg == "" ) return help();
	more = (string) this_player() -> getenv("PAGER");
	if( ! more ) more = "/bin/cmd/_more";
	more_ob = find_object( more );
	arg = resolv_path( (string) this_player() -> get_path(), arg );
	if( file_size( arg ) < 0 )
	{
		notify_fail( arg + ": file not found.\n" );
		return 0;
	}
	if( ! more_ob || more_ob == this_object() ) more_file( arg );
	else more_ob -> pager( arg );
	return 1;
}


int
help()
{
	write(
"Command: less\nSyntax: less <filename>\n" +
"This command lets you use less to read a file.  This means\n" +
"that the file will be displayed one-half screenful at a time. \n" +
"You may call up the next screenful by hitting <ENTER>.  If\n" +
"you want to goto a specific line then type that in and hit\n" +
"<ENTER>.  You can get further help from within less by using\n" +
"the ? command.\n"+
"See also: more, cat, head, tail\n"+
"NB try \"alias more less $*\"\n"+
"");
	return 1;
}


/* EOF */
