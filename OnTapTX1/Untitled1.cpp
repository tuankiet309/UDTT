#include <iostream>
#include <vector>
#include <algorithm>

struct Flight {
    std::string flight_number;
    double ticket_price;
    int seat_count;
};

// Tạo danh sách chuyến bay b với số lượng từ 6 đến 10 chuyến bay
std::vector<Flight> createFlights() {
    std::vector<Flight> flights;
    int flight_count = rand() % 5 + 6; // Số lượng chuyến bay từ 6 đến 10
    double price = 500000; // Giá vé ban đầu
    for (int i = 0; i < flight_count; ++i) {
        Flight flight;
        flight.flight_number = "VN00" + std::to_string(i + 1); // Số hiệu chuyến bay
        flight.ticket_price = price;
        flight.seat_count = 100; // Số ghế ngồi
        price += 100000; // Tăng giá vé lên 100,000 cho mỗi chuyến bay
        flights.push_back(flight);
    }
    return flights;
}

// Hiển thị tất cả các chuyến bay có giá vé trên 700,000 bằng đệ quy
void displayFlightsAbovePrice(const std::vector<Flight>& flights, int index) {
    if (index == flights.size()) {
        return;
    }

    if (flights[index].ticket_price > 700000) {
        std::cout << "Flight " << flights[index].flight_number << " - Ticket Price: " << flights[index].ticket_price << std::endl;
    }

    displayFlightsAbovePrice(flights, index + 1);
}

// Tìm chuyến bay có giá vé thấp nhất bằng phương pháp chia để trị
Flight findMinPriceFlight(const std::vector<Flight>& flights, int low, int high) {
    if (low == high) {
        return flights[low];
    }

    int mid = (low + high) / 2;
    Flight left_min = findMinPriceFlight(flights, low, mid);
    Flight right_min = findMinPriceFlight(flights, mid + 1, high);

    return (left_min.ticket_price < right_min.ticket_price) ? left_min : right_min;
}

// Hiển thị tất cả các phương án khác nhau để chọn ra 4 chuyến bay từ ds b bằng phương pháp quay lui
void findCombinations(const std::vector<Flight>& flights, std::vector<std::string>& chosen_flights, int index) {
    if (chosen_flights.size() == 4) {
        for (const auto& flight : chosen_flights) {
            std::cout << flight << std::endl;
        }
        std::cout << std::endl;
        return;
    }

    if (index == flights.size()) {
        return;
    }

    chosen_flights.push_back(flights[index].flight_number);
    findCombinations(flights, chosen_flights, index + 1);
    chosen_flights.pop_back();
    findCombinations(flights, chosen_flights, index + 1);
}

int main() {
    

    // Tạo danh sách chuyến bay
    std::vector<Flight> flights = createFlights();

    std::cout << "Flights with ticket price above 700,000:" << std::endl;
    displayFlightsAbovePrice(flights, 0);

    // Tìm chuyến bay có giá vé thấp nhất bằng phương pháp chia để trị
    Flight min_price_flight = findMinPriceFlight(flights, 0, flights.size() - 1);
    std::cout << "\nFlight with the lowest ticket price: " << min_price_flight.flight_number << " - Ticket Price: " << min_price_flight.ticket_price << std::endl;

    std::cout << "\nAll combinations of 4 flights:" << std::endl;
    std::vector<std::string> chosen_flights;
    findCombinations(flights, chosen_flights, 0);

    return 0;
}
