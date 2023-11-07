#include "main.h"
void activate(GtkApplication *app, gpointer user_data){
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button;

    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Window");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    grid = gtk_grid_new ();
    gtk_container_add (GTK_CONTAINER (window), grid);
    button = gtk_button_new_with_label ("Button 1");
    g_signal_connect (button, "clicked", G_CALLBACK (Play), NULL);
    gtk_grid_attach (GTK_GRID (grid), button, 0, 0, 1, 1);
    button = gtk_button_new_with_label ("Button 2");
    g_signal_connect (button, "clicked", G_CALLBACK (Play_Song_2), NULL);
    gtk_grid_attach (GTK_GRID (grid), button, 1, 0, 1, 1);
    button = gtk_button_new_with_label ("Quit");
    g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
    gtk_grid_attach (GTK_GRID (grid), button, 0, 1, 2, 1);
    gtk_widget_show_all (window);
}
void print_hello(GtkWidget *widget, gpointer data){
    Play();
}

void Play(){
    int start1 = 2048;
    int start2 = 2048;
    const char *mp3_file = "/home/ryan/Downloads/FNP.mp3";
    mpg123_handle *mh;
    mpg123_init();
    mh = mpg123_new(NULL, NULL);
    if (mpg123_open(mh, mp3_file) != MPG123_OK) {
        printf("Could not open MP3 file: %s\n", mp3_file);
        return;
    }

    mpg123_format(mh, 88200, MPG123_STEREO, MPG123_ENC_SIGNED_16);

    snd_pcm_t *handle;
    int err;
    if ((err = snd_pcm_open(&handle, "default", SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
        fprintf(stderr, "Cannot open audio device: %s\n", snd_strerror(err));
        return;
    }

    if ((err = snd_pcm_set_params(handle, SND_PCM_FORMAT_S16, SND_PCM_ACCESS_RW_INTERLEAVED, 2, 88200, 1, 500000)) < 0) {
        fprintf(stderr, "Cannot set audio parameters: %s\n", snd_strerror(err));
        snd_pcm_close(handle);
        return;
    }

    int channels, encoding;
    long rate;
    mpg123_getformat(mh, &rate, &channels, &encoding);

    unsigned char *buffer = (unsigned char *)malloc(start1);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    size_t done;
    while (mpg123_read(mh, buffer, 4, &done) == MPG123_OK) {
        int write_result = snd_pcm_writei(handle, buffer, done / mpg123_encsize(encoding));
        if (write_result < 0) {
            fprintf(stderr, "Error writing audio data: %s\n", snd_strerror(write_result));
            break;
        }
    }

    free(buffer);
    snd_pcm_close(handle);
    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();
}

void Play_Song_2(){
    int start1 = 2048;
    int start2 = 2048;
    const char *mp3_file = "/home/ryan/Downloads/MD.mp3";
    mpg123_handle *mh;
    mpg123_init();
    mh = mpg123_new(NULL, NULL);
    if (mpg123_open(mh, mp3_file) != MPG123_OK) {
        printf("Could not open MP3 file: %s\n", mp3_file);
        return;
    }

    mpg123_format(mh, 88200, MPG123_STEREO, MPG123_ENC_SIGNED_16);

    snd_pcm_t *handle;
    int err;
    if ((err = snd_pcm_open(&handle, "default", SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
        fprintf(stderr, "Cannot open audio device: %s\n", snd_strerror(err));
        return;
    }

    if ((err = snd_pcm_set_params(handle, SND_PCM_FORMAT_S16, SND_PCM_ACCESS_RW_INTERLEAVED, 2, 88200, 1, 500000)) < 0) {
        fprintf(stderr, "Cannot set audio parameters: %s\n", snd_strerror(err));
        snd_pcm_close(handle);
        return;
    }

    int channels, encoding;
    long rate;
    mpg123_getformat(mh, &rate, &channels, &encoding);

    unsigned char *buffer = (unsigned char *)malloc(start1);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    size_t done;
    while (mpg123_read(mh, buffer, 4, &done) == MPG123_OK) {
        int write_result = snd_pcm_writei(handle, buffer, done / mpg123_encsize(encoding));
        if (write_result < 0) {
            fprintf(stderr, "Error writing audio data: %s\n", snd_strerror(write_result));
            break;
        }
    }

    free(buffer);
    snd_pcm_close(handle);
    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();
}
void Add_Song(){
    struct link_list *Song_1;
    struct link_list *Song_2;
    struct link_list *Song_3;
    struct link_list *Song_4;
    struct link_list *Song_5;
    struct link_list *Song_6;
    Song_1 = (struct link_list*) malloc(sizeof(struct link_list));
    Song_2 = (struct link_list*) malloc(sizeof(struct link_list));
    Song_3 = (struct link_list*) malloc(sizeof(struct link_list));
    Song_4 = (struct link_list*) malloc(sizeof(struct link_list));
    Song_5 = (struct link_list*) malloc(sizeof(struct link_list));
    Song_6 = (struct link_list*) malloc(sizeof(struct link_list));

    Song_1->next = Song_2;
    Song_2->next = Song_3;
    Song_3->next = Song_4;
    Song_4->next = Song_5;
    Song_5->next = Song_6;
    Song_6->next = Song_1;

    printf("Select a song to add [Name]:\n");
    scanf(" %s", Song_1->Song_Name);
    Song_1->Song_No = 1;

    printf("Select a song to add [Name]:\n");
    scanf(" %s", Song_2->Song_Name);
    Song_2->Song_No = 2;

    printf("Select a song to add [Name]:\n");
    scanf(" %s", Song_3->Song_Name);
    Song_3->Song_No = 3;

    printf("Select a song to add [Name]:\n");
    scanf(" %s", Song_4->Song_Name);
    Song_4->Song_No = 4;

    printf("Select a song to add [Name]:\n");
    scanf(" %s", Song_5->Song_Name);
    Song_5->Song_No = 5;

    printf("Select a song to add [Name]:\n");
    scanf(" %s", Song_6->Song_Name);
    Song_6->Song_No = 6;
    struct link_list *Song_Temp;
    Song_Temp = Song_1;
    for (int i = 1; i < 7; ++i) {
        printf("The %d song was: %s\n", i, Song_Temp->Song_Name);
        printf("The song No. was: %d\n", Song_Temp->Song_No);
        Song_Temp = Song_Temp->next;
    }
    free(Song_1);
    free(Song_2);
    free(Song_3);
    free(Song_4);
    free(Song_5);
    free(Song_6);
}
void Calculator(){
    printf("Please choose: Quotient(Q), Multiplication(M), Modulus(m), Addition(A), Subtraction(S) or (q) to quit.\n");
    char Calculator_Input;
    scanf(" %c", &Calculator_Input);
    if(Calculator_Input == 'Q'){
        int num_1;
        int num_2;
        printf("Choose number 1:");
        scanf("%d", &num_1);
        printf("Choose number 2:");
        scanf("%d", &num_2);
        float result = num_1 / num_2;
        printf("The result is: %f", result);
    }
    else if(Calculator_Input == 'M'){
        int num_1;
        int num_2;
        printf("Choose number 1:");
        scanf("%d", &num_1);
        printf("Choose number 2:");
        scanf("%d", &num_2);
        float result = num_1 * num_2;
        printf("The result is: %f", result);
    }
    else if(Calculator_Input == 'm'){
        int num_1;
        int num_2;
        printf("Choose number 1:");
        scanf("%d", &num_1);
        printf("Choose number 2:");
        scanf("%d", &num_2);
        float result = num_1 % num_2;
        printf("The result is: %f", result);
    }
    else if(Calculator_Input == 'A'){
        int num_1;
        int num_2;
        printf("Choose number 1:");
        scanf("%d", &num_1);
        printf("Choose number 2:");
        scanf("%d", &num_2);
        float result = num_1 + num_2;
        printf("The result is: %f", result);
    }
    else if(Calculator_Input == 'S'){
        int num_1;
        int num_2;
        printf("Choose number 1:");
        scanf("%d", &num_1);
        printf("Choose number 2:");
        scanf("%d", &num_2);
        float result = num_1 - num_2;
        printf("The result is: %f", result);
    }
    return;
}

int random_number(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}


void Bubble_Sort(){
    int bubble[3];
    for (int i = 0; i < SIZE; ++i) {
        printf("Please chose number %d for the array:\n", i+1);
        scanf("%d", &bubble[i]);
    }
    int inner, outer, temp, x;
    for (outer = 0; outer < SIZE-1; outer++) {
        for (inner = outer+1;  inner < SIZE ; inner++) {
            if(bubble[outer] > bubble[inner]){
                temp = bubble[outer];
                bubble[outer] = bubble[inner];
                bubble[inner] = temp;
            }
        }
    }
    printf("Sorted Array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", bubble[i]);
    }
    printf("\n");
}


void Guessing_Game(struct Player P1, struct Player P2, int number, int lower_bound, int upper_bound){
    int Guess_Won = 0;
    int P1_Guess;
    int P2_Guess;
    printf("%s, Enter Your Guess [%d-%d]:\n", P1.name, lower_bound, upper_bound);
    scanf(" %d", &P1_Guess);
    printf("%s, Enter Your Guess [%d-%d]:\n", P2.name, lower_bound, upper_bound);
    scanf(" %d", &P2_Guess);
    bool guess_TF = 1;
    while(guess_TF) {
        if (P1_Guess == number) {
            printf("%s has won the game, Congrats!\n", P1.name);
            break;
        }
        if (P2_Guess == number) {
            printf("%s has won the game, Congrats!\n", P2.name);
            break;
        }
        printf("%s, Enter Your Guess [%d-%d]:\n", P1.name, lower_bound, upper_bound);
        scanf(" %d", &P1_Guess);
        printf("%s, Enter Your Guess [%d-%d]:\n", P2.name,lower_bound, upper_bound);
        scanf(" %d", &P2_Guess);
    }
    return;
}


int Password(){
    char pass_guess[6];
    char password[] = "Stark";
    printf("Please input the password to continue the program:");
    int Guess_Limit = 3;
    int Guess_no = 0;
    scanf("%s", pass_guess);
    int truth = strcmp(pass_guess, password);
    while(truth){
        printf("Incorrect Guess, try again:\n");
        scanf("%s", pass_guess);
        if(Guess_no > Guess_Limit){
            printf("Failed to input password, exiting...\n");
            return 1;
        }
        Guess_no = Guess_Limit + 1;

        truth = strcmp(pass_guess, password);
    }
    return 0;
}


void Say_Hi(){
    char input[10];
    printf("Please print your name:\n");
    scanf("%s", input);
    input[10] = '\0';
    int i = 0;
    printf("Hello, ");
    int string_length = strlen(input)-1;
    while (i < string_length+1
    ){
        printf("%c", input[i]);
        i += 1;
    }
    printf("!\n");
    return;
}


void Game(struct Player P1, struct Player P2, int number){
    int P1_Guess;
    int P2_Guess;
    printf("Player 1, Enter Your Guess [0-10]:\n");
    scanf(" %d", &P1_Guess);
    printf("Player 2, Enter Your Guess [0-10]:\n");
    scanf(" %d", &P2_Guess);
    printf("%d\n", number);
    bool guess_TF = 1;
    char exit;
    while(guess_TF) {
        if (P1_Guess == number) {
            printf("Player one has won the game, Congrats!\n");
            P1.score = P1.score + 1;
            printf("\nPlayer one's score is now: %d\n", P1.score);
            printf("\nPress q if you would like to quit,\nother wise press Enter Key:\n");
            scanf("%c", &exit);
            exit = toupper(exit);
            if(exit == 'Q'){
                break;
            }
        }
        if (P2_Guess == number) {
            printf("Player two has won the game, Congrats!\n");
            P2.score = P2.score + 1;
            printf("\nPlayer two's score is now: %d\n", P2.score);
            printf("\nPress q if you would like to quit,\nother "
                   "wise press Enter Key:\n");
            scanf("%c", &exit);
            exit = toupper(exit);
            if(exit == 'Q'){
                break;
            }
        }
        printf("\nPlayer 1, Enter Your Guess [0-10]:\n");
        scanf(" %d", &P1_Guess);
        printf("\nPlayer 2, Enter Your Guess [0-10]:\n");
        scanf(" %d", &P2_Guess);
    }
    return;
}
