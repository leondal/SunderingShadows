/** -*-C++-*- ***
 * _conv.c -- command that allows a creator to change some text in a file
 *   and optionally all the subdirecties
 *
 * 11 oct 96 -- craz@shadowgate -- creation
 *****/
#include <std.h>
#include <daemons.h>

inherit DAEMON;

// define some constants
#define START_DIR       0
#define SEARCH_TEXT     1
#define REPLACE_TEXT    2

// define some member variables
nosave string *args;
nosave int recurse = 0;

// prototype some functions
void doConv( string dir );
void fixFile( string file );
int cmd_conv( string str );


/*****
 * void doConv( string dir );
 *  -- does the converstion... note that this is a recursive function
 *****/
void doConv( string dir )
{
  string *files;
  int c;

  // if the dir is only a file, then just do the file :)
  if ( file_size( dir ) != -2 ) {
    fixFile( dir );
    return ;
  }

  // make sure that the directory has a / at the end
  if ( dir[-1..-1] != "/" )
    dir += "/";

  // get the files in the specified directory
  files = get_dir( dir );

  // loop through all the files
  for ( c = 0; c < sizeof( files ); ++c ) {
    // see if the file is a directory
    if ( file_size( dir + files[c] ) == -2 ) {
      // see if we are supposed to recuse into subdirs
      if ( !recurse )
	continue;

      // go into the new dir
      doConv( dir + files[c] );
    } else {
      // fix the file
      fixFile( dir + files[c] );
    }
  }
}


/*****
 * void fixFile( string file );
 *  -- called by doConv().  this is the function that actually changes
 *     the contents of the file
 *****/
void fixFile( string file )
{
  string fileText;

  if ( file_size( file ) == -1 ) {
    write( "Could not find the file '" + file + "'" );
    return ;
  }

  if ( file_size( file ) == -2 ) {
    write( "File '" + file + "' is a directory." );
    return ;
  }

  // read the file in and replace the text
  write( "Processing " + file + "..." );
  fileText = read_file( file );
  fileText = replace_string( fileText, args[SEARCH_TEXT], args[REPLACE_TEXT] );

  // save a backup copy!!
   if ( cp( file, file + ".conv.save" ) != 1 ) {
     write( "Unable to make a back up of the original.  Skipping file." );
    return ;
}

  // now, remove the file and write the new "updated" version
  rm( file );
  if ( !write_file( file, fileText ) ) {
    rm( file );
    rename( file + ".conv.save", file );
    write( "Unable to write to file '" + file + "'." );
    return ;
  }

  // done with the file... clean up
  rm( file + ".conv.save" );
}


int cmd_conv( string str )
{
  // make sure there is something in the argument list
  if ( !str || str == "" ) {
    notify_fail( "Syntax: conv [-R] start_dir search_text replace_text\n" );
    return 0;
  }

  // setup up some arugments
  seteuid("over");
  args = explode( str, " " );

  if ( args[0] == "-R" ) {
    recurse = 1;
    args -= ({ args[0] });
  }

  // check the arguments
  if ( sizeof( args ) != 3 ) {
    notify_fail( "Syntax: conv [-R] start_dir search_text replace_text\n" );
    return 0;
  }

  // resolve the path
  args[START_DIR] = resolv_path( "cwd", args[START_DIR] );

  // run the converstion
  doConv( args[START_DIR] );

  write( "Done." );

  return 1;
}


int help()
{
  write( @EndText
Syntax: conv [-R] start_dir search_text replace_text

This command will search all the files in 'start_dir' and change any
occurence of 'search_text' to 'replace_text'.  If the optional flag of
-R is given, then the search the entire directory tree starting at 'start_dir'.
EndText
  );

  return 1;
}
