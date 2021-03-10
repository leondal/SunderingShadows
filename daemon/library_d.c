// library_d.c
#include <std.h>
#include <security.h>
#include <daemons.h>
#include <clock.h>

inherit DAEMON;

#define AVA_D               "/daemon/avatar_d.c"
#define LIBRARY_SAVE_PATH   "/d/save/library_books/"
#define BOOK_FILE           "/d/common/obj/misc/book"
#define SAVE_FILE           "/daemon/save/library_info"
#define LIBRARY_LOG         "libraries"
#define REAL_WEEK           432000

string *__Banned;

mapping __Librarians;
mapping __Libraries;
mapping __CheckedOut;
mapping __Allowed;
mapping __Restricted;
mapping __Submitted;
mapping __Denied;

// returns 1 if the titles are the same after stripping color and capitilization
int compare_titles(string title_one,string title_two);
// builds a file name based on book title and author alias
string build_file_name(object book);
// makes a file name based on the title and author arguments passed
string create_file_name(string title, string author);
// returns 1 if the library already exists
int library_exists(string library_name);
// returns 1 if the book exists in the library
int book_exists(string library_name,object book);
// returns 1 if the book has been saved to the library, 0 if not
int book_file_exists(string library_name,string title,string author);
// creates a new book from file and places it in player's inventory
int give_book_to_player(string file,object player);
// removes the book in question from the players inventory
int take_book_from_player(object book,object player);
// checks if the player has enough gold, and if so, removes it from their money
int collect_deposit(object player,int deposit,int due_date);
// returns a deposit if they return their book in time
int return_deposit(object player,int deposit);
// returns 1 if the player is a librarian in the library
int check_librarian(string library_name,object player);
// makes a new library, including directories for the library, denied and submitted books
int make_library(string library_name);
// makes a new librarian
int make_librarian(string library_name,string name,string alias,object player);
// removes a librarian
int remove_librarian(string library_name, string name, object player);
// returns the players real name based on the alias supplied
string get_real_name(mixed live, object ob);
// puts a book on the library shelves for use
int put_book_in_library(string library_name,object book,object player);
// removes a book from the library completely, gives the last copy to the player
int remove_book_from_library(string library_name,string book_title, string book_author,object player);
// increments the amount of copies of the book by amount
int add_book(string library_name, string book_title, string book_author, int amount);
// checks out a book from the library and adds to a mapping, collects deposit from player
int check_out_book(string library_name, string book_title, string book_author,object player,int deposit);
// used to return checked out books to the library, will return the deposit if its on time
int return_book_to_library(string library_name, object book, object player);
// takes a book from a library, used for private libraries
int take_book(string library_name, string book_title, string book_author,object player);
// replaces a book in the library, the desired way to return books to a private library
int replace_book(string library_name, object book, object player);
// spawns a copy of a book without deducting from copies in the library, useful for immortals
int spawn_book(string library_name, string book_title, string book_author,object player);
// updates the book file in the library, only librarians or the original author can update a book
int update_book(string library_name, object book, object player);
// submits a book to the library for a librarian to review later
int submit_book_to_library(string library_name,string alias,object book,object player);
// command used by librarians to take a book from the library and consider for review
int review_book(string library_name, string book_title, string book_author,object player);
// if the book is approved, the librarian uses this command to add it to the library shelves
int approve_book(string library_name, object book, object player);
// if the book is denied for reasons other than blatant ooc, they use this command
// the author or the person who submitted the book for review can then pick it up
// later and make any necessary changes before submitting it again
int deny_book(string library_name, object book, object player);
// this is the command used to retrieve books that have been denied by the librarian
int retrieve_book(string library_name,string book_title,string book_author,object player);
// this will be called the first time the library in question has any functions called to
// restock overdue books.  Should be more processor friendly than doing on reset or boot
int restock_books(string library_name);
// restricts a player from using a library, useful for people who cause damage, etc
int restrict_player_from_library(string library_name,string alias,object player);
// unrestricts a player from said library
int unrestrict_player_from_library(string library_name,string alias,object player);
// allows a player, for use with private libraries
int allow_player_for_library(string library_name,string alias,object player);
// unallows, again, for private libraries
int unallow_player_for_library(string library_name,string alias,object player);
// this is an OOC ban to prevent a person from using any library functions, might consider
// making this books and writing paper too, if there is a serious enough problem
int ban_player_from_libraries(string alias,object player);
// removes the ban from said player after they have been spanked hard enough
int unban_player_from_libraries(string alias,object player);
// returns a raw mapping of librarians for said library
mapping get_librarians(string library_name);
// returns raw mapping of all books in said library
mapping get_books(string library_name);
// returns a list of checked out books (no name here, it's the lesser of two evils, believe me)
mapping get_checked_out(string library_name);
// returns a mapping of submitted books waiting for review
mapping get_submitted(string library_name);
// returns a mapping of all books that have been denied and are awaiting pickup
mapping get_denied(string library_name);
// returns a mapping of all people allowed to use the library
mapping get_allowed(string library_name);
// returns a mapping of all the restricted people for the library
mapping get_restricted(string library_name);
// returns an array of all the banned people
string *get_banned();
// cleans the banned, allowed and restricted mappings for people who have been time rid, etc
void clean_lists();
void clean_banned();
void clean_allowed();
void clean_restricted();
// used to save this file and to save the book itself
void SAVE();
void SAVE_BOOK(string library_name, string file_name,object book);


void create()
{
    ::create();

    __Librarians = ([]);
    __Libraries  = ([]);
    __CheckedOut = ([]);
    __Allowed    = ([]);
    __Restricted = ([]);
    __Submitted  = ([]);
    __Denied     = ([]);
    __Banned     = ({});

    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_FILE);
    seteuid(getuid());

}


// filters and compares two titles to see if they're the same
int compare_titles(string title_one,string title_two)
{
    if(!stringp(title_one)) { return 0; }
    if(!stringp(title_two)) { return 0; }
    title_one = lower_case(title_one);
    title_two = lower_case(title_two);
    title_one = FILTERS_D->filter_colors(title_one);
    title_two = FILTERS_D->filter_colors(title_two);
    title_one = replace_string(title_one," ","_");
    title_two = replace_string(title_two," ","_");
    if(title_one == title_two) { return 1; }
    return 0;
}

// builds a file name based on the book title and the author's name
string build_file_name(object book)
{
    string file,title,author_alias;

    if(!objectp(book))               { return 0; }
    if(base_name(book) != BOOK_FILE) { return notify_fail("Wrong type of book.\n"); }
    title = book->query_book_title();
    author_alias = book->query_author_alias();
    file = create_file_name(title,author_alias);
    return file;
}

// same as build_file_name but takes strings instead of an object
string create_file_name(string title, string author)
{
    string file;
    if(!stringp(title))  { return 0; }
    if(!stringp(author)) { return 0; }

    title  = FILTERS_D->filter_colors(title);
    author = FILTERS_D->filter_colors(author);
// color filter first...! in the old order it was lower-casing
// the color codes and then not filtering them out... N, 7/17.
    title  = lower_case(title);
    author = lower_case(author);
    title  = replace_string(title," ","_");
    author = replace_string(author," ","_");
    file   = title+"_"+author;
    return file;
}

// returns 1 if the library exists, 0 if not
int library_exists(string library_name)
{
    string *libraries;
    libraries = keys(__Libraries);
    if(!sizeof(libraries))                          { return 0; }
    if(member_array(library_name, libraries) == -1) { return 0; }
    return 1;
}

// returns 1 if the book has been saved in the specified library, 0 if not
int book_exists(string library_name,object book)
{
    string file;
    if(!stringp(library_name))          { return 0; }
    if(!library_exists(library_name))   { return 0; }
    if(!objectp(book))                  { return 0; }
    file = build_file_name(book);
    if(file_exists(LIBRARY_SAVE_PATH + library_name +"/"+ file +".o")) { return 1; }
    return 0;
}

// returns 1 if the book has been saved to the library, 0 if not
int book_file_exists(string library_name,string title,string author)
{
    string file;
    if(!library_exists(library_name)) { return 0; }
    if(!stringp(title)) { return 0; }
    if(!stringp(author)) { return 0; }
    file = create_file_name(title,author);
    if(file_exists(LIBRARY_SAVE_PATH + library_name +"/"+ file +".o")) { return 1; }
    return 0;
}

// makes a copy of the needed book and puts it in the players inventory
int give_book_to_player(string file,object player)
{
    object book;
    string path;

    if(!objectp(player))    { return 0; }
    if(!stringp(file))      { return 0; }

    book = new(BOOK_FILE+".c");
    path = replace_string(file,".o","");
    book->RESTORE(path);
    book->move(player);
    return 1;
}

// removes object book from players inventory
int take_book_from_player(object book,object player)
{
    if(!objectp(book))       { return 0; }
    if(!objectp(player))     { return 0; }
    if(present(book,player)) { book->remove(); }
    return 1;
}

// collects the deposit when people check out a book
int collect_deposit(object player,int deposit,int due_date)
{
    if(!objectp(player))                        { return 0; }
    if(!player->query_funds("gold",deposit))
    {
        tell_object(player,"You don't have "+deposit+" gold for the deposit.\n");
        return 0;
    }
    tell_object(player,"%^RESET%^The library collects a "+deposit+" gold deposit.  "
        "If you do not return the book before "+ctime(due_date)+" you will not "
        "get your deposit back.");
    player->use_funds("gold",deposit);
    return 1;
}

// gives the deposit back to the player
int return_deposit(object player,int deposit)
{
    if(!objectp(player)) { return 0; }
    player->add_money("gold",deposit);
    tell_object(player,"You get back your "+deposit+" gold deposit.");
    return 1;
}

// returns 1 if they're a librarian for said library, or an immortal
int check_librarian(string library_name,object player)
{
    string name,*librarians;
    if(!objectp(player)) { return 0; }
    if(avatarp(player))  { return 1; }
    name = (string)player->query_name();
    if(!mapp(__Librarians[library_name])) { return 0; }
    if(!keys(__Librarians[library_name])) { return 0; }
    librarians = keys(__Librarians[library_name]);
    if(member_array(name, librarians) != -1) { return 1; }
    return 0;
}

// makes a new library and creates a directory with that name if it doesn't exist
int make_library(string library_name)
{
    if(!stringp(library_name))       { return 0; }
    if(library_exists(library_name)) { return 0; }

    __Libraries[library_name]   = ([]);
    __Restricted[library_name]  = ([]);
    __Allowed[library_name]     = ([]);
    __Submitted[library_name]   = ([]);
    __Denied[library_name]      = ([]);
    if(!get_dir(LIBRARY_SAVE_PATH+library_name+"/"))
    {
        mkdir(LIBRARY_SAVE_PATH+library_name);
        mkdir(LIBRARY_SAVE_PATH+library_name+"/submitted");
        mkdir(LIBRARY_SAVE_PATH+library_name+"/denied");
    }
    SAVE();
    return 1;
}

// makes a librarian for the library and gives them the alias.  alias will be used with an IC list
int make_librarian(string library_name,string name,string alias,object player)
{
    string real_name;

    if(!objectp(player))                        { return 0; }
    if(!stringp(name))                          { return 0; }
    if(!stringp(alias))                         { return 0; }
    if(!stringp(library_name))                  { return 0; }
    if(!library_exists(library_name))           { return 0; }
    if(!check_librarian(library_name,player))   { return 0; }

    if((string)player->query_position() != "high mortal" && !avatarp(player)) { return 0; }

    real_name = get_real_name(name,player);

    if(!__Librarians[library_name]) { __Librarians[library_name] = ([]); }
    __Librarians[library_name] += ([ real_name : alias ]);
    SAVE();
    return 1;
}

// removes a librarian from the library
int remove_librarian(string library_name, string name, object player)
{
    string real_name;
    if(!objectp(player))                { return 0; }
    if(!library_exists(library_name))   { return 0; }
    if(!stringp(name))                  { return 0; }

    real_name = get_real_name(name,player);
    map_delete(__Librarians[library_name],real_name);
    SAVE();
    return 1;
}

// gets the real name for people that are recognized as something different
string get_real_name(mixed live, object ob)
{
    string real_name;
    if(!objectp(ob)) return notify_fail("get_real_name() Invalid Object.");
    if(!objectp(live) && !stringp(live)) { return notify_fail("get_real_name() Invalid name passed."); }

    if(objectp(live) && live->is_player())
    {
        if(!live->is_player()) { return notify_fail("get_real_name() Not a User"); }
        return live->query_name();
    }

    if(!ob->is_player()) { return live; }
    if(avatarp(ob))
    {
        if(user_exists(live)) return live;
    }
    if(user_exists(real_name=ob->realName(live))) { return real_name; }
    if(user_exists(live)) { return live; }
    return notify_fail("You don't have that player recognized.");
}

// adds a new book to the library with 1 copy on the shelf
int put_book_in_library(string library_name,object book,object player)
{
    string file_name,title,author_alias,author_name;
    mapping book_info=([]);

    if(!stringp(library_name))                  { return 0; }
    if(!objectp(book))                          { return 0; }
    if(!library_exists(library_name))           { return 0; }
    if(book_exists(library_name,book))          { return 0; }
    if(!objectp(player))                        { return 0; }
    if(!check_librarian(library_name,player))   { return 0; }

    title = book->query_book_title();
    author_alias = book->query_author_alias();
    author_name = book->query_author_name();
    file_name = build_file_name(book);

    book_info = ([ file_name : ([ "title": title, "author name" : author_name, "author alias" : author_alias, "copies" : 1 ]), ]);
    __Libraries[library_name] += book_info;
    book->set_library_book(1);

    log_file(LIBRARY_LOG,""+ctime(time())+" "+player->QCN+" added "+title+" by "+author_alias+" to "+library_name+"\n");

    SAVE_BOOK(library_name,file_name,book);
    SAVE();
    take_book_from_player(book,player);
    return 1;
}

// completely removes a book from the library
int remove_book_from_library(string library_name,string book_title, string book_author,object player)
{
    string file,save_path;

    if(!objectp(player))                        { return 0; }
    if(!stringp(library_name))                  { return 0; }
    if(!stringp(book_title))                    { return 0; }
    if(!stringp(book_author))                   { return 0; }
    file = create_file_name(book_title,book_author);
    save_path = LIBRARY_SAVE_PATH+library_name+"/"+file+".o";
    if(!file_exists(save_path))                 { return 0; }
    if(!check_librarian(library_name,player))   { return 0; }

    log_file(LIBRARY_LOG,""+ctime(time())+" "+player->QCN+" removed "+book_title+" by "+book_author+" from "+library_name+"\n");

    give_book_to_player(save_path,player);
    map_delete(__Libraries[library_name],file);
    rm(save_path);

    SAVE();
    return 1;
}

// adds or subtracts copies of books
int add_book(string library_name, string book_title, string book_author, int amount)
{
    string file, save_path;
    int num_books;
    mapping books, book;

    if(!stringp(library_name))          { return 0; }
    if(!stringp(book_title))            { return 0; }
    if(!stringp(book_author))           { return 0; }
    if(!intp(amount))                   { return 0; }
    if(!library_exists(library_name))   { return 0; }
    file = create_file_name(book_title,book_author);
    save_path = LIBRARY_SAVE_PATH+library_name+"/"+file+".o";
    if(!file_exists(save_path))         { return 0; }

    books = __Libraries[library_name];
    if(!sizeof(keys(books))) { return 0; }
    book = books[file];
    if(!sizeof(keys(book))) { return 0; }
    num_books = book["copies"];
    num_books += amount;
    if(num_books < 0) { num_books = 0; }
    book["copies"] = num_books;
    SAVE();
    return num_books;
}

// marks a book as checked out, and returns an int value of the date the book is due back
int check_out_book(string library_name, string book_title, string book_author,object player,int deposit)
{
    string file, save_path,name;
    int due_date,num_books;
    mapping books;

    if(!stringp(library_name))          { return 0; }
    if(!stringp(book_title))            { return 0; }
    if(!stringp(book_author))           { return 0; }
    if(!objectp(player))                { return 0; }
    if(!library_exists(library_name))   { return 0; }
    file = create_file_name(book_title,book_author);
    save_path = LIBRARY_SAVE_PATH+library_name+"/"+file+".o";
    if(!file_exists(save_path))         { return 0; }

    if(!__CheckedOut[library_name]) { __CheckedOut[library_name] = ([]); }
    books = __CheckedOut[library_name];
    name = (string)player->query_name();
    if(books[name] && books[name] != ([]))
    {
        tell_object(player,"You already have a book checked out at this "
            "library, you may not have more than one at a time.\n");
        return 0;
    }

    due_date = time() + REAL_WEEK;

    num_books = add_book(library_name, book_title, book_author,0);
    if(!num_books)
    {
        tell_object(player,"There are no copies of that book left in the library.\n");
        return 0;
    }
    if(!collect_deposit(player,deposit,due_date)) { return 0; }
    add_book(library_name, book_title, book_author,-1);

    books[name] = ([ "title" : book_title, "author" : book_author, "due date" : due_date, "deposit" : deposit]);

    give_book_to_player(save_path,player);
    log_file(LIBRARY_LOG,""+ctime(time())+" "+capitalize(name)+" checked out "+book_title+" by "+book_author+" from "+library_name+"\n");

    SAVE();
    return due_date;
}

// checks to see if the books is returned before it's due, returns 1 if it is, 0 if not
int return_book_to_library(string library_name, object book, object player)
{
    string file, save_path,name,book_title,book_author;
    mapping books,book_info;
    int due_date;

    if(!stringp(library_name))          { return 0; }
    if(!objectp(book))                  { return 0; }
    if(!objectp(player))                { return 0; }
    if(!library_exists(library_name))   { return 0; }
    file = build_file_name(book);
    save_path = LIBRARY_SAVE_PATH+library_name+"/"+file+".o";
    if(!file_exists(save_path))         { return 0; }
    if(!__CheckedOut[library_name])     { return 0; }

    books = __CheckedOut[library_name];
    if(!sizeof(keys(books))) { return 0; }
    name = (string)player->query_name();
    book_title = book->query_book_title();
    book_author = book->query_author_alias();

    if(mapp(books[name]))
    {
        book_info = books[name];
        book_title = lower_case(FILTERS_D->filter_colors(book_title));
        if(lower_case((string)book_info["title"]) != book_title)
        {
            tell_object(player,"That is not the book you have checked "
                "out here.\n");
            tell_object(player,"The book you have checked out is "+(string)book_info["title"]+".");
            return 0;
        }
        due_date = (int)book_info["due date"];
        map_delete(books,name);
        add_book(library_name, book_title, book_author,1);
        if(book->query_modified())
        {
            tell_object(player,"That book has been modified, the library will "
                "not take it and you will not get your deposit back.  If you are "
                "the author and want to update it, use the update book command.");
            return -1;
        }
        take_book_from_player(book,player);
        log_file(LIBRARY_LOG,""+ctime(time())+" "+capitalize(name)+" returned "+book_title+" by "+book_author+" to "+library_name+"\n");
        SAVE();
        if(time() < due_date)
        {
            return_deposit(player,(int)book_info["deposit"]);
            return 1;
        }
        tell_object(player,"Your book is late so you do not get your deposit back.");
        return -1;
    }
    return 0;
}

// used to take books from private libraries where they don't need to be checked out
int take_book(string library_name, string book_title, string book_author,object player)
{
    string file, save_path,name;
    int num_books;

    if(!stringp(library_name))          { return 0; }
    if(!stringp(book_title))            { return 0; }
    if(!stringp(book_author))           { return 0; }
    if(!objectp(player))                { return 0; }
    if(!library_exists(library_name))   { return 0; }
    file = create_file_name(book_title,book_author);
    save_path = LIBRARY_SAVE_PATH+library_name+"/"+file+".o";
    if(!file_exists(save_path))         { return 0; }

    name = (string)player->query_name();
    num_books = add_book(library_name, book_title, book_author,0);
    if(!num_books) { return 0; }
    add_book(library_name, book_title, book_author,-1);
    give_book_to_player(save_path,player);

    log_file(LIBRARY_LOG,""+ctime(time())+" "+capitalize(name)+" took "+book_title+" by "+book_author+" from "+library_name+"\n");

    SAVE();
    return 1;
}

// replaces a book that has been previously taken from the library by said player.
int replace_book(string library_name, object book, object player)
{
    string name,book_title,book_author;

    if(!stringp(library_name))          { return 0; }
    if(!objectp(book))                  { return 0; }
    if(!objectp(player))                { return 0; }
    if(!library_exists(library_name))   { return 0; }
    if(!book_exists(library_name,book)) { return 0; }

    name = (string)player->query_name();
    book_title = book->query_book_title();
    book_author = book->query_author_alias();

    add_book(library_name, book_title, book_author,1);
    take_book_from_player(book,player);

    log_file(LIBRARY_LOG,""+ctime(time())+" "+capitalize(name)+" returned "+book_title+" by "+book_author+" to "+library_name+"\n");

    SAVE();
    return 1;
}

// this spawns a book without altering the number that are in the library.  useful for immortals
int spawn_book(string library_name, string book_title, string book_author,object player)
{
    string file, save_path,name;
    int num_books;
    object book;

    if(!stringp(library_name))          { return 0; }
    if(!stringp(book_title))            { return 0; }
    if(!stringp(book_author))           { return 0; }
    if(!objectp(player))                { return 0; }
    if(!library_exists(library_name))   { return 0; }
    file = create_file_name(book_title,book_author);
    save_path = LIBRARY_SAVE_PATH+library_name+"/"+file+".o";
    if(!file_exists(save_path))         { return 0; }
    give_book_to_player(save_path,player);
    return 1;
}

// updates a book, will need checks for librarians, imms and original author
int update_book(string library_name, object book, object player)
{
    string file,save_path,title,author_alias,author_name;
    mapping book_info = ([]),books = ([]),checked_out = ([]),by_player = ([]);
    int copies;

    if(!objectp(player))                        { return 0; }
    if(!objectp(book))                          { return 0; }
    if(!stringp(library_name))                  { return 0; }
    file = build_file_name(book);
    save_path = LIBRARY_SAVE_PATH+library_name+"/"+file+".o";
    if(!file_exists(save_path))                 { return 0; }

    title = book->query_book_title();
    author_alias = book->query_author_alias();
    author_name = book->query_author_name();
    book_info = __Libraries[library_name];
    books = book_info[file];
    copies = 1 + (int)books["copies"];

    map_delete(__Libraries[library_name],file);
    rm(save_path);

    book_info = ([ file : ([ "title": title, "author name" : author_name, "author alias" : author_alias, "copies" : copies ]), ]);
    __Libraries[library_name] += book_info;
    book->set_library_book(1);

    log_file(LIBRARY_LOG,""+ctime(time())+" "+player->QCN+" updated "+title+" by "+author_alias+" in "+library_name+"\n");

    tell_object(player,"The book has been updated.\n");
    book->set_modified(0);
    add_book(library_name,title,author_alias,1);

    SAVE_BOOK(library_name,file,book);
    take_book_from_player(book,player);
    checked_out = __CheckedOut[library_name];
    if(mapp(checked_out))
    {
        by_player = checked_out[(string)player->query_name()];
        if(mapp(by_player))
        {
            if(compare_titles((string)by_player["title"],title))
            {
                map_delete(checked_out,(string)player->query_name());
            }
        }
    }
    SAVE();
    return 1;
}

// submits a book to the library for review by a librarian before it goes into the game.
int submit_book_to_library(string library_name,string alias,object book,object player)
{
    string file_name,title,author_alias,author_name,player_name,player_alias;
    mapping book_info=([]);

    if(!stringp(library_name))                  { return 0; }
    if(!objectp(book))                          { return 0; }
    if(!stringp(alias))                         { return 0; }
    if(!library_exists(library_name))           { return 0; }
    if(book_exists(library_name,book))          { return 0; }
    if(!objectp(player))                        { return 0; }
    if(!check_librarian(library_name,player))   { return 0; }

    title = book->query_book_title();
    author_alias = book->query_author_alias();
    author_name = book->query_author_name();
    file_name = build_file_name(book);
    file_name = "submitted/"+file_name;
    player_alias = alias;
    player_name = (string)player->query_name();

    book_info = ([ file_name : ([ "player name" : player_name, "player alias" : player_alias, "title": title, "author name" : author_name, "author alias" : author_alias, "date" : ctime(time()), ]), ]);
    __Submitted[library_name] += book_info;

    log_file(LIBRARY_LOG,""+ctime(time())+" "+capitalize(player_name)+" submitted "+title+" by "+author_alias+" to "+library_name+" for review.\n");

    SAVE_BOOK(library_name,file_name,book);
    SAVE();
    take_book_from_player(book,player);
    return 1;
}

// command for librarians to review books that have been submitted
int review_book(string library_name, string book_title, string book_author,object player)
{
    string file, save_path,name;
    int num_books;
    object book;
    mapping submitted = ([]),book_stuff = ([]);

    if(!stringp(library_name))                  { return 0; }
    if(!stringp(book_title))                    { return 0; }
    if(!stringp(book_author))                   { return 0; }
    if(!objectp(player))                        { return 0; }
    if(!library_exists(library_name))           { return 0; }
    if(!check_librarian(library_name,player))   { return 0; }
    file = create_file_name(book_title,book_author);
    file = "submitted/"+file;
    save_path = LIBRARY_SAVE_PATH+library_name+"/"+file+".o";
    if(!file_exists(save_path))         { return 0; }

    name = (string)player->query_name();
    submitted = __Submitted[library_name];
    book_stuff = submitted[file];

    give_book_to_player(save_path,player);
    book = present("book",player);
    book->set_property("submitted_by",book_stuff["player name"]);

    map_delete(__Submitted[library_name],file);
    rm(save_path);

    tell_object(player,"You are now reviewing "+book_title+" by "+book_author+".  This is the "
        "only copy of the book.  After reviewing it, please <accept book>, or <reject book>.  "
        "If it contains blatant ooc information, please contact an immortal.");
    log_file(LIBRARY_LOG,""+ctime(time())+" "+capitalize(name)+" began reviewing "+book_title+" by "+book_author+" from "+library_name+"\n");

    SAVE();
    return 1;
}

// approves a book and adds it to the library
int approve_book(string library_name, object book, object player)
{
    string book_title,player_name,book_author;

    if(!stringp(library_name))                  { return 0; }
    if(!objectp(book))                          { return 0; }
    if(!objectp(player))                        { return 0; }
    if(!library_exists(library_name))           { return 0; }
    if(!check_librarian(library_name,player))   { return 0; }
    if(book_exists(library_name,book))          { return 0; }

    book_title = book->query_book_title();
    book_author = book->query_author_alias();
    player_name = capitalize((string)player->query_name());
    book->remove_property("submitted_by");

    put_book_in_library(library_name,book,player);
    log_file(LIBRARY_LOG,""+ctime(time())+" "+player_name+" approved and added "+book_title+" by "+book_author+" to "+library_name+".\n");
    SAVE();
    return 1;
}

// denies a book and places it back on the shelf for the person that submitted it to retrieve
int deny_book(string library_name, object book, object player)
{
    string book_title,player_name,book_author,file_name,submitted;
    mapping book_info=([]);

    if(!stringp(library_name))                  { return 0; }
    if(!objectp(book))                          { return 0; }
    if(!objectp(player))                        { return 0; }
    if(!library_exists(library_name))           { return 0; }
    if(!check_librarian(library_name,player))   { return 0; }
    if(book_exists(library_name,book))          { return 0; }

    book_title = book->query_book_title();
    book_author = book->query_author_alias();
    file_name = build_file_name(book);
    file_name = "denied/"+file_name;
    player_name = (string)player->query_name();
    submitted = (string)book->query_property("submitted_by");
    book->remove_property("submitted_by");

    book_info = ([ file_name : ([ "title": book_title, "submitted by" : submitted, "author name" : book_author, "author alias" : book_author, "date" : ctime(time()), ]), ]);
    __Denied[library_name] += book_info;

    log_file(LIBRARY_LOG,""+ctime(time())+" "+capitalize(player_name)+" denied "+book_title+" by "+book_author+" for "+library_name+".\n");

    SAVE_BOOK(library_name,file_name,book);
    SAVE();
    take_book_from_player(book,player);
    return 1;
}

// retrieves a book from the library after it's been denied
int retrieve_book(string library_name,string book_title,string book_author,object player)
{
    string player_name,submitted_by,file,save_path,author;
    mapping book_info = ([]), stuff = ([]);

    if(!stringp(library_name))                  { return 0; }
    if(!stringp(book_title))                    { return 0; }
    if(!stringp(book_author))                   { return 0; }
    if(!objectp(player))                        { return 0; }
    if(!library_exists(library_name))           { return 0; }
    file = create_file_name(book_title,book_author);
    file = "denied/"+file;
    save_path = LIBRARY_SAVE_PATH+library_name+"/"+file+".o";
    if(!file_exists(save_path))                 { return 0; }

    book_info = __Denied[library_name];
    stuff = book_info[file];
    submitted_by = stuff["submitted by"];
    author = stuff["author name"];
    player_name = (string)player->query_name();

    if(player_name != submitted_by && player_name != author && !avatarp(player))
    {
        tell_object(player,"You must be the author of the book or the person who originally "
            "submitted it for review to retrieve it.");
        return 0;
    }

    log_file(LIBRARY_LOG,""+ctime(time())+" "+capitalize(player_name)+" retrieved "+book_title+" by "+book_author+" from "+library_name+" after it was denied.");

    give_book_to_player(save_path,player);
    map_delete(__Denied[library_name],file);
    rm(save_path);

    SAVE();
    return 1;
}

// called to restock overdue books.  Process hungry, use sparingly
int restock_books(string library_name)
{
    string *book_files,title,author;
    mapping books = ([]),info = ([]);
    int i,due;

    if(!stringp(library_name))                  { return 0; }
    if(!library_exists(library_name))           { return 0; }
    if(!mapp(__CheckedOut[library_name]))       { return 0; }
    if(__CheckedOut[library_name] == ([]) )     { return 0; }

    books = __CheckedOut[library_name];
    book_files = keys(books);

    if(!pointerp(book_files)) { return 0; }
    for(i=0;i<sizeof(book_files);i++)
    {
        info = books[book_files[i]];
        due = info["due date"];
        if(time() > due)
        {
            title = info["title"];
            author = info["author"];
            map_delete(books,book_files[i]);
            add_book(library_name,title,author,1);
        }
    }
    SAVE();
    return 1;
}

// adds a player to the restricted mapping, need to have player recognized as alias
int restrict_player_from_library(string library_name,string alias,object player)
{
    string real_name;

    if(!stringp(library_name))                  { return 0; }
    if(!stringp(alias))                         { return 0; }
    if(!objectp(player))                        { return 0; }
    if(!library_exists(library_name))           { return 0; }
    if(!check_librarian(library_name,player))   { return 0; }

    real_name = get_real_name(alias,player);

    if(!__Restricted[library_name]) { __Restricted[library_name] = ([]); }
    __Restricted[library_name] += ([ real_name : alias ]);
    log_file(LIBRARY_LOG,""+ctime(time())+" "+(string)player->query_name()+" restricted "+real_name+" from "+library_name+".\n");
    SAVE();
    return 1;
}

// unrestricts a player
int unrestrict_player_from_library(string library_name,string alias,object player)
{
    string real_name;

    if(!stringp(library_name))                  { return 0; }
    if(!stringp(alias))                         { return 0; }
    if(!objectp(player))                        { return 0; }
    if(!library_exists(library_name))           { return 0; }
    if(!check_librarian(library_name,player))   { return 0; }

    real_name = get_real_name(alias, player);

    if(!__Restricted[library_name] || __Restricted[library_name] == ([])) { return 0; }
    map_delete(__Restricted[library_name],real_name);
    log_file(LIBRARY_LOG,""+ctime(time())," "+(string)player->query_name()+" unrestricted "+real_name+" from "+library_name+".\n");
    SAVE();
    return 1;
}

// adds a player to the allowed list, for use with private libraries
int allow_player_for_library(string library_name,string alias,object player)
{
    string real_name;

    if(!stringp(library_name))                  { return 0; }
    if(!stringp(alias))                         { return 0; }
    if(!objectp(player))                        { return 0; }
    if(!library_exists(library_name))           { return 0; }
    if(!check_librarian(library_name,player))   { return 0; }

    real_name = get_real_name(alias,player);

    if(!__Allowed[library_name]) { __Allowed[library_name] = ([]); }
    __Allowed[library_name] += ([ real_name : alias ]);
    log_file(LIBRARY_LOG,""+ctime(time())+" "+(string)player->query_name()+" allowed "+real_name+" to use "+library_name+".\n");
    SAVE();
    return 1;
}

// unallows player from library
int unallow_player_for_library(string library_name,string alias,object player)
{
    string real_name;

    if(!stringp(library_name))                  { return 0; }
    if(!stringp(alias))                         { return 0; }
    if(!objectp(player))                        { return 0; }
    if(!library_exists(library_name))           { return 0; }
    if(!check_librarian(library_name,player))   { return 0; }

    real_name = get_real_name(alias, player);

    if(!__Allowed[library_name] || __Allowed[library_name] == ([])) { return 0; }
    map_delete(__Allowed[library_name],real_name);
    log_file(LIBRARY_LOG,""+ctime(time())," "+(string)player->query_name()+" unallowed "+real_name+" from "+library_name+".\n");
    SAVE();
    return 1;
}

// bans a player from ALL library functions, this is an ooc for use with DMFs
int ban_player_from_libraries(string alias,object player)
{
    string real_name;
    if(!stringp(alias))                 { return 0; }
    if(!objectp(player))                { return 0; }
    real_name = get_real_name(alias,player);
    if(!__Banned) { __Banned = ({}); }
    __Banned += ({ real_name });
    log_file(LIBRARY_LOG,""+ctime(time())+" "+(string)player->query_name()+" banned "+real_name+" from using libraries.\n");
    SAVE();
    return 1;
}

// unbans a player
int unban_player_from_libraries(string alias,object player)
{
    string real_name;
    if(!stringp(alias))                 { return 0; }
    if(!objectp(player))                { return 0; }
    real_name = get_real_name(alias,player);
    if(member_array(real_name,__Banned) == -1) { return 0; }
    __Banned -= ({ real_name });
    SAVE();
    return 1;
}

// returns a mapping of librarians with real names as keys
mapping get_librarians(string library_name)
{
    if(!stringp(library_name))          { return 0; }
    if(!library_exists(library_name))   { return 0; }
    return __Librarians[library_name];
}

// returns a mapping of all the books in the library with file names as keys
mapping get_books(string library_name)
{
    if(!stringp(library_name))          { return 0; }
    if(!library_exists(library_name))   { return 0; }
    return __Libraries[library_name];
}

// returns a mapping of all the books checked out with names as keys
mapping get_checked_out(string library_name)
{
    if(!stringp(library_name))          { return 0; }
    if(!library_exists(library_name))   { return 0; }
    return __CheckedOut[library_name];
}

// returns a mapping of the books that have been submitted for review
mapping get_submitted(string library_name)
{
    if(!stringp(library_name))          { return 0; }
    if(!library_exists(library_name))   { return 0; }
    return __Submitted[library_name];
}

// returns a mapping of the books that have been denied
mapping get_denied(string library_name)
{
    if(!stringp(library_name))          { return 0; }
    if(!library_exists(library_name))   { return 0; }
    return __Denied[library_name];
}

// mapping of allowed, for use with private libraries
mapping get_allowed(string library_name)
{
    if(!stringp(library_name))          { return 0; }
    if(!library_exists(library_name))   { return 0; }
    return __Allowed[library_name];
}

// mapping of restricted
mapping get_restricted(string library_name)
{
    if(!stringp(library_name))          { return 0; }
    if(!library_exists(library_name))   { return 0; }
    return __Restricted[library_name];
}

// returns array of every banned person
string *get_banned()
{
    return __Banned;
}


// cleans up lists of mappings and arrays and gets rid of players that have been rid
void clean_lists()
{
    clean_banned();
    clean_allowed();
    clean_restricted();
    SAVE();
    return;
}

void clean_banned()
{
    int i;
    if(sizeof(__Banned))
    {
        for(i=0;i<sizeof(__Banned);i++)
        {
            if(find_player(__Banned[i])) { continue; }
            if(user_exists(__Banned[i])) { continue; }
            __Banned -= ({ __Banned[i] });
        }
    }
    SAVE();
    return;
}

void clean_allowed()
{
    int i,j;
    string *libraries,*names;
    mapping tmp;
    if(!__Allowed || __Allowed == ([])) { return; }
    libraries = keys(__Allowed);
    for(i=0;i<sizeof(libraries);i++)
    {
        tmp = __Allowed[libraries[i]];
        names = keys(tmp);
        for(j=0;j<sizeof(names);j++)
        {
            if(find_player(names[j])) { continue; }
            if(user_exists(names[j])) { continue; }
            map_delete(__Allowed[libraries[i]],names[j]);
        }
    }
    SAVE();
    return;
}

void clean_restricted()
{
    int i,j;
    string *libraries,*names;
    mapping tmp;
    if(!__Restricted || __Restricted == ([])) { return; }
    libraries = keys(__Restricted);
    for(i=0;i<sizeof(libraries);i++)
    {
        tmp = __Restricted[libraries[i]];
        names = keys(tmp);
        for(j=0;j<sizeof(names);j++)
        {
            if(find_player(names[j])) { continue; }
            if(user_exists(names[j])) { continue; }
            map_delete(__Restricted[libraries[i]],names[j]);
        }
    }
    SAVE();
    return;
}


void SAVE()
{
    seteuid(UID_DAEMONSAVE);
	save_object(SAVE_FILE);
    seteuid(getuid());
    return;
}

void SAVE_BOOK(string library_name, string file_name,object book)
{
    string save_path;

    if(!stringp(library_name))          { return 0; }
    if(!stringp(file_name))             { return 0; }
    if(!objectp(book))                  { return 0; }
    if(book_exists(library_name,book))  { return 0; }
    save_path = LIBRARY_SAVE_PATH+library_name+"/"+file_name;
    book->SAVE(save_path);
    return;
}
