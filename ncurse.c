#include <curses.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_DARKBLUE 92
#define COLOR_GREY 100
#define COLOR_LIGHT_ORANGE_ 104
#define COLOR_ORANGE_ 110
#define COLOR_LIGHT_RED_ 116
#define COLOR_RED_ 122
#define COLOR_L_L_YELLOW_ 128
#define COLOR_L_YELLOW 60
#define COLOR_LIGHT_YELLOW_ 134
#define COLOR_YELLOW_ 140
#define COLOR_FULL_YELLOW_ 146
#define COLOR_WIN_LOSE 156

char	*ft_strjoin_char(char *str, char c)
{
	int i =0;
	char *new_str;

	new_str = (char *)malloc(sizeof(char) * strlen(str) + 2);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i++] = c;
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

char	*getUsername(void) {
	char		*input;

	input = (char *)malloc(sizeof(char) * 20);
	WINDOW		*userWin;
	int			h;
	int			w;
	int			ch;
	int			i;

	getmaxyx(stdscr, h, w);
	userWin = newwin(h, w, 0, 0);
	mvwprintw(userWin, (h / 2), (w / 2), "Username:");
	wrefresh(userWin);
	i = 0;
	while ( (ch = getch()) != '\n' ) {
		input = ft_strjoin_char(input, ch);
		mvwprintw(userWin, (h / 2), (w / 2), "Username:");
		mvwprintw(userWin, (h / 2 + 1), (w / 2), input);
		wrefresh(userWin);
		if ( i >= 15 )
			break;
		i++;
	}
	if (strlen(input) == 0)
		input = getUsername();
	endwin();
	return input;
}

/*
   int			launchGame( void ) {
   int			key;
   int			h;
   int			w;
   WINDOW		*gameWin;
   char		*username;

//username = getUsername();
choose_p1();	
timeout(1);
getmaxyx(stdscr, h, w);
gameWin = newwin(h, w, 0, 0);
wbkgdset(gameWin, COLOR_PAIR(102) );
while ((key = getch()) != 27) {
if (false)
wclear(gameWin);
switch (key)
{
case KEY_RESIZE:
getmaxyx(gameWin, h, w);
break;
case ' ':
break;
case KEY_RIGHT:
break;
case KEY_LEFT:
break;
}
wattron(gameWin, COLOR_PAIR(8));
if (true)
mvwprintw( gameWin, (h / 2), (w / 2) - 5, username);
else
{
mvwprintw( gameWin, (h / 2), (w / 2) - 5, " GAME OVER " );
}
wattroff(gameWin, COLOR_PAIR(8));
wrefresh(gameWin);
}
//logScore(game.getScore(), username);
endwin();
return 0;
}
*/

#include <dirent.h>

char	**get_available_players(void)
{
	char	**available_players;

	DIR *dir;
	struct dirent *ent;
	int nb_players = 0;
	if ((dir = opendir ("players/")) != NULL) {
		/* print all the files and directories within directory */
		while ((ent = readdir (dir)) != NULL) {
			nb_players++;
		}
	} else {
		/* could not open directory */
		system("clear");
		printf("Error: Can't open directory players/\n");
		exit(0);
		return (available_players);
	}
	available_players = (char **)malloc(sizeof(char*) * nb_players -1);
	int i =0;
	/* On saute . et .. */
	dir = opendir ("players/");
	readdir(dir);
	readdir(dir);
	while ((ent = readdir(dir)) != NULL)
		available_players[i++] = strdup(ent->d_name);
	closedir (dir);
	return (available_players);

}

static void	printLogo( WINDOW *menu, int h, int w ) {
	attron(COLOR_PAIR(2));
	mvwprintw(menu, (h / 3), (w / 2) - (8), "FILLER MATCHMAKER");
	//mvwprintw(menu, (h-2), (w) - (10), "plisieck");
	attroff(COLOR_PAIR(2));
}

static void	printMenu( WINDOW *menu, int choice ) {
	int		h;
	int		w;

	getmaxyx(stdscr, h, w );
	wattron(menu ,COLOR_PAIR(2));
	printLogo(menu, h, w );
	wborder(menu, '*', '*', '*', '*', '*', '*', '*', '*' );
	wattroff(menu, COLOR_PAIR(2));
	mvwprintw(menu, (h / 2), (w / 2) - (5), "Select Mode:" );
	(choice == 0 ? wattron(menu, COLOR_PAIR(2)) : 0);
	mvwprintw( menu, (h / 2 + 1), (w / 2) - (2), "1. Play" );
	(choice == 0 ? wattroff(menu, COLOR_PAIR(2)) : 0);
	(choice == 1 ? wattron(menu, COLOR_PAIR(2)) : 0);
	mvwprintw(menu, (h / 2 + 2), (w / 2) - (2), "2. Configure");
	(choice == 1 ? wattroff(menu, COLOR_PAIR(2)) : 0);
	(choice == 2 ? wattron(menu, COLOR_PAIR(2)) : 0);
	mvwprintw(menu, (h / 2 + 3), (w / 2) - (2), "3. Quit");
	(choice == 2 ? wattroff(menu, COLOR_PAIR(2)) : 0);
}

static void	print_choosing_player_menu( WINDOW *menu, int choice, char *player, char **available_players) 
{
	int		h;
	int		w;
	int i = 0;

	getmaxyx(stdscr, h, w );
	wattron(menu ,COLOR_PAIR(2));
	printLogo(menu, h, w );
	wborder(menu, '*', '*', '*', '*', '*', '*', '*', '*' );
	wattroff(menu, COLOR_PAIR(2));
	mvwprintw(menu, (h / 2) - 2, (w / 2) - (10), "Choose player for %s:", player);
	while (available_players[i])
	{
		(choice == i ? wattron(menu, COLOR_PAIR(2)) : 0);
		mvwprintw( menu, (h / 2 + i), (w / 2) - (8), "%d. %s", i, available_players[i]);
		(choice == i ? wattroff(menu, COLOR_PAIR(2)) : 0);
		i++;
	}
	(choice == i ? wattron(menu, COLOR_PAIR(2)) : 0);
	mvwprintw(menu, (h / 2 + i + 1), (w / 2) - 8, "%d. Back", i);
	(choice == i ? wattroff(menu, COLOR_PAIR(2)) : 0);
}


static void		init_pair_colors(void)
{
	init_pair(1, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(8, COLOR_WHITE, COLOR_DARKBLUE);
	init_pair(16, COLOR_BLACK, COLOR_ORANGE_);
	init_pair(32, COLOR_BLACK, COLOR_LIGHT_RED_);
	init_pair(64, COLOR_BLACK, COLOR_RED_);
	init_pair(128, COLOR_BLACK, COLOR_L_L_YELLOW_);
	init_pair(25, COLOR_BLACK, COLOR_L_YELLOW);
	init_pair(51, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(102, COLOR_BLACK, COLOR_YELLOW_);
	init_pair(204, COLOR_BLACK, COLOR_FULL_YELLOW_);
	init_pair(100, COLOR_GREY, COLOR_DARKBLUE);
	init_pair(101, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(102, COLOR_DARKBLUE, COLOR_DARKBLUE);

	init_pair(2, COLOR_GREEN, COLOR_DARKBLUE);
	init_pair(3, COLOR_RED, COLOR_DARKBLUE);
	init_pair(4, COLOR_L_YELLOW, COLOR_DARKBLUE);
}

int			choose_p2(char *str) {
	int		key;
	int		h;
	int		w;
	int		choice;
	WINDOW	*player_menu;
	char	**available_players = get_available_players();

	int nb_players =0;
	while (available_players[nb_players])
		nb_players++;
	choice = 0;
	getmaxyx(stdscr, h, w);
	player_menu = newwin(h, w, 0, 0);
	while ( (key = getch()) != 27 ) {
		timeout(-1);
		wclear( player_menu );
		choice -= ((key == KEY_UP) && (choice > 0)) ? 1 : 0;
		choice += ((key == KEY_DOWN) && (choice < nb_players)) ? 1 : 0;
		if ( key == ' ' || key == '\n' ) {
			if (choice == nb_players)
			{
					wclear( player_menu );
					endwin();
					return (0);

			}
			else
			{
					wclear( player_menu );
					system("./filler_vm -f maps/map01 -p1 players/plisieck.filler -p2 players/aboudjem.filler | ./graph");
					return (0);
			}
		}
		print_choosing_player_menu( player_menu, choice, "p2", available_players);
		wrefresh( player_menu );
	}
	endwin();
	return 0;
}

int			choose_p1() {
	int		key;
	int		h;
	int		w;
	int		choice;
	WINDOW	*player_menu;
	char	**available_players = get_available_players();

	int nb_players =0;
	while (available_players[nb_players])
		nb_players++;
	choice = 0;
	getmaxyx(stdscr, h, w);
	player_menu = newwin(h, w, 0, 0);
	wrefresh(player_menu);
	while ( (key = getch()) != 27 ) {
		timeout(-1);
		wclear( player_menu );
		choice -= ((key == KEY_UP) && (choice > 0)) ? 1 : 0;
		choice += ((key == KEY_DOWN) && (choice < nb_players)) ? 1 : 0;
		if ( key == ' ' || key == '\n' ) {
			if (choice == nb_players)
			{
					wclear( player_menu );
					endwin();
					return (0);

			}
			else
			{
					wclear( player_menu );
					choose_p2(available_players[choice]);
			}
		}
		print_choosing_player_menu( player_menu, choice, "p1", available_players);
		wrefresh( player_menu );
	}
	endwin();
	return 0;
}

#include <unistd.h>

int			menu(void) {
	int		key;
	int		h;
	int		w;
	int		choice;
	WINDOW	*menu;

	choice = 0;
	getmaxyx(stdscr, h, w);
	menu = newwin(h, w, 0, 0);
	while ( (key = getch()) != 27 ) {
		// timeout(-1);
		// wclear( menu );
		choice -= ((key == KEY_UP) && (choice > 0)) ? 1 : 0;
		choice += ((key == KEY_DOWN) && (choice < 2)) ? 1 : 0;
		if ( key == ' ' || key == '\n' ) {
			switch (choice) {
				case 0:
					wclear(menu);
					wrefresh(menu);
					choose_p1();
					break;
				case 1:
					wclear( menu );
					endwin();
					return 0;
					break;
				case 2:
					wclear( menu );
					endwin();
					return 0;
					break;

			}
		}
		printMenu( menu, choice);
		wrefresh( menu );
	}
	endwin();
	return 0;
}

static void		init_colors(void)
{
	start_color();
	init_color(COLOR_WHITE, 1000, 1000, 1000);
	init_color(COLOR_DARKBLUE, 100, 100, 150);
	init_color(COLOR_GREY, 300, 300, 300);
	init_color(COLOR_LIGHT_ORANGE_, 729, 534, 348);
	init_color(COLOR_ORANGE_, 741, 447, 279);
	init_color(COLOR_LIGHT_RED_, 744, 372, 270);
	init_color(COLOR_RED_, 747, 279, 150);
	init_color(COLOR_L_L_YELLOW_, 714, 621, 321);
	init_color(COLOR_L_YELLOW, 723, 624, 225);
	init_color(COLOR_LIGHT_YELLOW_, 711, 606, 3);
	init_color(COLOR_YELLOW_, 711, 699, 0);
	init_color(COLOR_FULL_YELLOW_, 711, 591, 3);
	init_color(COLOR_MAGENTA, 1000, 459, 1000);
	init_color(COLOR_WIN_LOSE, 432, 366, 303);
	init_color(COLOR_GREEN, 0, 1000, 0);
	init_color(COLOR_RED, 1000, 0, 0);
	init_pair_colors();
}

void	initCurses(void) {
	initscr();
	cbreak();
	curs_set(0);
	noecho();
	timeout(1);
	keypad( stdscr, TRUE );
	init_colors();
}



int	main(void)
{
	initCurses();
	menu();
	
	return (0);
}
