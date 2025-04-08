#include<bits/stdc++.h>
using namespace std;

class Movie{
    public:
        int movieId;
        string movieName;
        int movieDurationInMinutes;

        int getMovieId(){
            return movieId;
        }

        void setMovieId(int movieId){
            this->movieId = movieId;
        }

        string getMovieName(){
            return movieName;
        }

        void setMovieName(string movieName){
            this->movieName = movieName;
        }

        int getMovieDurationInMinutes(){
            return movieDurationInMinutes;
        }

        void setMovieDurationInMinutes(int movieDurationInMinutes){
            this->movieDurationInMinutes = movieDurationInMinutes;
        }
            
};

enum City{
    Bangalore,
    Delhi,
    Mumbai,
    Chennai,
    Hyderabad,
    Kolkata,
    Pune,    
};

enum SeatCategory{
    SILVER,
    GOLD,
    PLATINUM,
};

class MovieController{
    public:
        unordered_map<City,list<Movie*>> cityVsMovies;
        list<Movie*> allMovies;

        void addMovie(Movie* movie,City city)
        {
            allMovies.push_back(movie);      
            cityVsMovies[city].push_back(movie);
        }

        Movie* getMovieByName(string movieName)
        {
            for(auto movie : allMovies)
            {
                if(movie->getMovieName() == movieName)
                    return movie;
            }
            return NULL;
        }

        list<Movie*> getMoviesByCity(City city)
        {
            return cityVsMovies[city];
        }
};

class Seat{
    public:
    int seatId;
    int row;
    SeatCategory seatCategory;

    int getSeatId()
    {
        return seatId;
    }

    void setSeatId(int seatId)
    {
        this->seatId = seatId;
    }

    int getRow()
    {
        return row;
    }

    void setRow(int row)
    {
        this->row = row;
    }

    SeatCategory getSeatCategory()
    {
        return seatCategory;
    }

    void setSeatCategory(SeatCategory seatCategory)
    {
        this->seatCategory = seatCategory;
    }
};

class Screen{
    public:
        int screenId;
        list<Seat*> seats;

        int getScreenId()
        {
            return screenId;
        }

        void setScreenId(int screenId)
        {
            this->screenId = screenId;
        }

        list<Seat*> getSeats()
        {
            return seats;
        }

        void setSeats(list<Seat*> seats)
        {
            this->seats = seats;
        }
};

class Show{
    public:
        int showId;
        Movie* movie;
        Screen* screen;
        int showStartTime;
        list<int> bookedSeatIds;

        int getShowId()
        {
            return showId;
        }

        void setShowId(int showId)
        {
            this->showId = showId;
        }

        Movie* getMovie()
        {
            return movie;
        }

        void setMovie(Movie* movie)
        {
            this->movie = movie;
        }

        Screen* getScreen()
        {
            return screen;
        }

        void setScreen(Screen* screen)
        {
            this->screen = screen;
        }

        int getShowStartTime()
        {
            return showStartTime;
        }

        void setShowStartTime(int showStartTime)
        {
            this->showStartTime = showStartTime;
        }

        list<int> getBookedSeatIds()
        {
            return bookedSeatIds;
        }

        void setBookedSeatIds(list<int> bookedSeatIds)
        {
            this->bookedSeatIds = bookedSeatIds;
        }
};

class Theatre{
    public:
        int theatreId;
        string address;
        City city;
        list<Screen*> screens;
        list<Show*> shows;

        int getTheatreId()
        {
            return theatreId;
        }

        void setTheatreId(int theatreId)
        {
            this->theatreId = theatreId;
        }

        string getAddress()
        {
            return address;
        }

        void setAddress(string address)
        {
            this->address = address;
        }

        list<Screen*> getScreens()
        {
            return screens;
        }

        void setScreens(list<Screen*> screens)
        {
            this->screens = screens;
        }

        list<Show*> getShows()
        {
            return shows;
        }

        void setShows(list<Show*> shows)
        {
            this->shows = shows;
        }

        City getCity()
        {
            return city;
        }
        
        void setCity(City city)
        {
            this->city = city;
        }
};

class TheatreController{
    public:
        unordered_map<City,list<Theatre*>> cityVsTheatres;
        list<Theatre*> allTheatres;

        void addTheatre(Theatre* theatre,City city)
        {
            allTheatres.push_back(theatre);
            cityVsTheatres[city].push_back(theatre);
        }

        unordered_map<Theatre*,list<Show*>> getAllShow(Movie* movie,City city)
        {
            unordered_map<Theatre*,list<Show*>> theatreVsShows;
            for(auto theatre : cityVsTheatres[city])
            {
                list<Show*> givenMovieShows;
                for(auto show : theatre->getShows())
                {
                    if(show->movie->getMovieId() == movie->getMovieId())
                    {
                        givenMovieShows.push_back(show);
                    }
                }

                if(givenMovieShows.size() > 0)
                {
                    theatreVsShows[theatre] = givenMovieShows;
                }
            }

            return theatreVsShows;
        }
};

class Payment{
    public:
        int paymentId;
};

class Booking{
    public:
        Show* show;
        list<Seat*> bookedSeats;
        Payment* payment;

        Show* getShow()
        {
            return show;
        }

        void setShow(Show* show)
        {
            this->show = show;
        }

        list<Seat*> getBookedSeats()
        {
            return bookedSeats;
        }

        void setBookedSeats(list<Seat*> bookedSeats)
        {
            this->bookedSeats = bookedSeats;
        }

        Payment* getPayment()
        {
            return payment;
        }

        void setPayment(Payment* payment)
        {
            this->payment = payment;
        }
};

class BookMyShow {
public:
    MovieController movieController;
    TheatreController theatreController;

    BookMyShow() {}

    void createBooking(City userCity, string movieName) {
        list<Movie*> movies = movieController.getMoviesByCity(userCity);

        Movie* interestedMovie = nullptr;
        for (auto movie : movies) {
            if (movie->getMovieName() == movieName) {
                interestedMovie = movie;
                break;
            }
        }

        if (!interestedMovie) {
            cout << "Movie not found." << endl;
            return;
        }

        unordered_map<Theatre*, list<Show*>> showsTheatreWise = theatreController.getAllShow(interestedMovie, userCity);

        if (showsTheatreWise.empty()) {
            cout << "No shows available." << endl;
            return;
        }

        auto entry = *showsTheatreWise.begin();
        list<Show*> runningShows = entry.second;
        Show* interestedShow = *runningShows.begin();

        int seatNumber = 30;
        list<int> bookedSeats = interestedShow->getBookedSeatIds();

        if (find(bookedSeats.begin(), bookedSeats.end(), seatNumber) == bookedSeats.end()) {
            bookedSeats.push_back(seatNumber);
            interestedShow->setBookedSeatIds(bookedSeats);

            Booking* booking = new Booking();
            list<Seat*> myBookedSeats;

            for (Seat* screenSeat : interestedShow->getScreen()->getSeats()) {
                if (screenSeat->getSeatId() == seatNumber) {
                    myBookedSeats.push_back(screenSeat);
                }
            }

            booking->setBookedSeats(myBookedSeats);
            booking->setShow(interestedShow);

            cout << "BOOKING SUCCESSFUL" << endl;
        } else {
            cout << "Seat already booked, try again" << endl;
        }
    }

    void initialize() {
        createMovies();
        createTheatres();
    }

    void createMovies() {
        Movie* avengers = new Movie();
        avengers->setMovieId(1);
        avengers->setMovieName("AVENGERS");
        avengers->setMovieDurationInMinutes(128);

        Movie* baahubali = new Movie();
        baahubali->setMovieId(2);
        baahubali->setMovieName("BAAHUBALI");
        baahubali->setMovieDurationInMinutes(180);

        movieController.addMovie(avengers, City::Bangalore);
        movieController.addMovie(avengers, City::Delhi);
        movieController.addMovie(baahubali, City::Bangalore);
        movieController.addMovie(baahubali, City::Delhi);
    }

    list<Seat*> createSeats() {
        list<Seat*> seats;

        for (int i = 0; i < 40; ++i) {
            Seat* seat = new Seat();
            seat->setSeatId(i);
            seat->setSeatCategory(SILVER);
            seats.push_back(seat);
        }
        for (int i = 40; i < 70; ++i) {
            Seat* seat = new Seat();
            seat->setSeatId(i);
            seat->setSeatCategory(GOLD);
            seats.push_back(seat);
        }
        for (int i = 70; i < 100; ++i) {
            Seat* seat = new Seat();
            seat->setSeatId(i);
            seat->setSeatCategory(PLATINUM);
            seats.push_back(seat);
        }

        return seats;
    }

    list<Screen*> createScreens() {
        list<Screen*> screens;
        Screen* screen = new Screen();
        screen->setScreenId(1);
        screen->setSeats(createSeats());
        screens.push_back(screen);
        return screens;
    }

    Show* createShow(int showId, Screen* screen, Movie* movie, int showStartTime) {
        Show* show = new Show();
        show->setShowId(showId);
        show->setScreen(screen);
        show->setMovie(movie);
        show->setShowStartTime(showStartTime);
        return show;
    }

    void createTheatres() {
        Movie* avengerMovie = movieController.getMovieByName("AVENGERS");
        Movie* baahubali = movieController.getMovieByName("BAAHUBALI");

        Theatre* inoxTheatre = new Theatre();
        inoxTheatre->setTheatreId(1);
        inoxTheatre->setScreens(createScreens());
        inoxTheatre->setCity(City::Bangalore);

        list<Show*> inoxShows;
        inoxShows.push_back(createShow(1, *inoxTheatre->getScreens().begin(), avengerMovie, 8));
        inoxShows.push_back(createShow(2, *inoxTheatre->getScreens().begin(), baahubali, 16));
        inoxTheatre->setShows(inoxShows);

        Theatre* pvrTheatre = new Theatre();
        pvrTheatre->setTheatreId(2);
        pvrTheatre->setScreens(createScreens());
        pvrTheatre->setCity(City::Delhi);

        list<Show*> pvrShows;
        pvrShows.push_back(createShow(3, *pvrTheatre->getScreens().begin(), avengerMovie, 13));
        pvrShows.push_back(createShow(4, *pvrTheatre->getScreens().begin(), baahubali, 20));
        pvrTheatre->setShows(pvrShows);

        theatreController.addTheatre(inoxTheatre, City::Bangalore);
        theatreController.addTheatre(pvrTheatre, City::Delhi);
    }
};

int main()
{
    BookMyShow bookMyShow;
    bookMyShow.initialize();

    bookMyShow.createBooking(City::Bangalore, "BAAHUBALI");
    bookMyShow.createBooking(City::Bangalore, "BAAHUBALI");

    return 0;
}