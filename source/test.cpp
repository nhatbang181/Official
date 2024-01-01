#include <SFML/Graphics.hpp>
#include<iostream>
#include "admin.h"
const int rows1 = 11;
const int cols1 = 11;
const int squareSize = 20;

void drawQRCode(sf::RenderWindow& window, const int array2D[rows1][cols1]) {
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            // Sử dụng giá trị từ mảng để xác định màu cho ô vuông

            sf::Color color = array2D[i][j] % 2 == 0 ? sf::Color::Black : sf::Color::White;

            // Vẽ ô vuông
            sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
            square.setPosition(680 + j * squareSize, 70 + i * squareSize);
            square.setFillColor(color);

            window.draw(square);
        }
    }
}

std::vector<std::string> splitString(const std::string& input) {
    std::vector<std::string> result;
    std::string word;
    std::size_t startPos = input.find_first_not_of(" ,"); // Tìm vị trí của ký tự đầu tiên không phải là khoảng trắng hoặc dấu phẩy

    while (startPos != std::string::npos) {
        std::size_t endPos = input.find_first_of(" ,", startPos); // Tìm vị trí của ký tự đầu tiên là khoảng trắng hoặc dấu phẩy
        word = input.substr(startPos, (endPos != std::string::npos) ? (endPos - startPos) : std::string::npos);
        result.push_back(word);

        startPos = input.find_first_not_of(" ,", endPos); // Tìm vị trí của ký tự đầu tiên không phải là khoảng trắng hoặc dấu phẩy
    }

    return result;
}

// Function to check if there is at least one common genre between two strings
bool areGenresMatching(const std::string& genres1, const std::string& genres2) {
    std::vector<std::string> words1 = splitString(genres1);
    std::vector<std::string> words2 = splitString(genres2);

    for (const auto& word : words1) {
        if (std::find(words2.begin(), words2.end(), word) != words2.end()) {
            return true;
        }
    }

    return false;
}

int main() {
    admin admin1;
    admin1.themphim("DanhSachPhim.txt");
    admin1.nhaprap();
    admin1.quanlychieuphim();
    admin1.writesuatchieu("DanhSachSuatChieu.txt");
    admin1.nhapphongchieu("DanhSachPhong.txt");

    const int soPhim = admin1.getsophim();
    sf::RenderWindow window(sf::VideoMode(1480, 832), "Dat Ve");
    sf::Font Freck;
    if (!Freck.loadFromFile("FrederickatheGreat-Regular.ttf")) {
        // X? l� l?i n?u kh�ng t?i ???c font
        return EXIT_FAILURE;
    }


    sf::Font arial;
    if (!arial.loadFromFile("arial.ttf")) {
        // X? l� l?i n?u kh�ng t?i ???c font
        return EXIT_FAILURE;
    }
    sf::Font tech;
    if (!tech.loadFromFile("Judge-2OaRe.ttf")) {
        // X? l� l?i n?u kh�ng t?i ???c font
        return EXIT_FAILURE;
    }
    sf::Font funny;
    //if (!funny.loadFromFile("Ghostmeat.ttf")) {
    //    // X? l� l?i n?u kh�ng t?i ???c font
    //    return EXIT_FAILURE;
    //}
    sf::Font lora;
    if (!lora.loadFromFile("Lora-VariableFont_wght.ttf")) {
        // X? l� l?i n?u kh�ng t?i ???c font
        return EXIT_FAILURE;
    }
    sf::Font horror;
    if (!horror.loadFromFile("Melted Monster.ttf")) {
        // X? l� l?i n?u kh�ng t?i ???c font
        return EXIT_FAILURE;
    }

    sf::Font love;
    if (!love.loadFromFile("Love.ttf")) {
        // X? l� l?i n?u kh�ng t?i ???c font
        return EXIT_FAILURE;
    }
    sf::Font cinema;
    if (!cinema.loadFromFile("VOLACROME.ttf")) {
        // X? l� l?i n?u kh�ng t?i ???c font
        return EXIT_FAILURE;
    }
    sf::Font action;
    //if (!action.loadFromFile("PatrioticsDemoRegular.ttf")) {
    //    // X? l� l?i n?u kh�ng t?i ???c font
    //    return EXIT_FAILURE;
    //}
    // T?o ??i t??ng sf::Text
    int row;
    if ((float)admin1.getsophim() - admin1.getsophim() == 0) {
        row = admin1.getsophim() / 3;
    }
    else {
        row = admin1.getsophim() / 3 + 1;
    }
    int column = 3;
    sf::Text CGV;
    CGV.setFont(cinema);
    CGV.setCharacterSize(70); // K�ch th??c font
    CGV.setFillColor(sf::Color::Black); // M�u v?n b?n
    CGV.setString("CGV DN"); // N?i dung v?n b?n
    CGV.setPosition((window.getSize().x - CGV.getGlobalBounds().width) / 2, 20);
    bool daloadmenuphim = 0;
    sf::Text phimdangchieu;
    phimdangchieu.setFont(lora);
    phimdangchieu.setCharacterSize(52); // K�ch th??c font
    phimdangchieu.setFillColor(sf::Color::Black); // M�u v?n b?n
    phimdangchieu.setString("Phim Dang Chieu"); // N?i dung v?n b?n
    phimdangchieu.setPosition(167.5, 221 + 50);
    std::vector<sf::RectangleShape> borderPosterPhim;
    string truycapphim = "";
    float scalex, scaley;
    sf::Sprite* posterPhim = new sf::Sprite[soPhim];
    sf::Texture* texturePhim = new sf::Texture[soPhim];
    for (int i = 0; i < admin1.getsophim(); i++) {
        sf::Texture* tmptexture = new sf::Texture;
        sf::Sprite* tmpSprite = new sf::Sprite;

        sf::RectangleShape rectangle(sf::Vector2f(270, 385.2));

        // ??t v? tr� v� m�u s?c cho ch? nh?t
        rectangle.setFillColor(sf::Color::Transparent);  // ??t m�u n?n l� trong su?t
        rectangle.setOutlineThickness(5);  // ??t ?? r?ng ???ng vi?n
        rectangle.setOutlineColor(sf::Color::Black);  // ??t m�u ???ng vi?n
        // K�ch th??c m?i c?a sprite (v� d?: 100x100)
        // T�nh t? l? ?? gi? nguy�n t? l? khung h�nh
        // Thay ??i k�ch th??c c?a sprite
        borderPosterPhim.push_back(rectangle);
        posterPhim[i] = (*tmpSprite);
        texturePhim[i] = (*tmptexture);

    }
    int columnnow;
    int rownow;
    vector <int> countTheLoai;
    int viTriSearchBar = 20;
    sf::Texture searchBarTexture;
    if (!searchBarTexture.loadFromFile("searchBar.png")) {
        // Xử lý lỗi nếu không tải được hình ảnh
        return -1;
    }

    // Tạo sprite và đặt texture cho sprite
    sf::Sprite searchBar(searchBarTexture);

    searchBar.setPosition((window.getSize().x - searchBar.getGlobalBounds().width) / 2, 20);
    sf::Text searchBoxText;
    //searchBoxText.setFillColor(sf::Color::Black);
    searchBoxText.setFillColor(sf::Color(104, 104, 104));
    searchBoxText.setFont(lora);
    searchBoxText.setCharacterSize(25);
    searchBoxText.setPosition(searchBar.getPosition().x + 5, 35);
    searchBoxText.setString("Search...");

    sf::Texture backButtonTexture;
    if (!backButtonTexture.loadFromFile("previousButton.png")) {
        // Xử lý lỗi nếu không tải được hình ảnh
        return -1;
    }

    // Tạo sprite và đặt texture cho sprite
    sf::Sprite backButton(backButtonTexture);
    sf::Vector2f newSize(52.9774127312, 43);
    scalex = newSize.x / backButton.getGlobalBounds().width;
    scaley = newSize.y / backButton.getGlobalBounds().height;
    backButton.setScale(scalex, scaley);
    backButton.setPosition(0, 0);
    sf::Text thongtinphim1Tmp;
    thongtinphim1Tmp.setFont(lora);
    thongtinphim1Tmp.setCharacterSize(20);
    thongtinphim1Tmp.setFillColor(sf::Color::Black);


    // T?i h�nh ?nh t? file v� th�m v�o vector
    std::vector <sf::Text>  tenphim(admin1.getsophim());
    std::vector<std::pair<std::string, sf::Text>> thongtinphim1(admin1.getsophim());
    std::vector <sf::Text> thongtinphim2(admin1.getsophim());
    std::vector <sf::Text>  thongtinphim3(admin1.getsophim());
    string selectedMovie;
    int countPage = 1;
    sf::Cursor handPointer;
    sf::Cursor arrowPointer;
    sf::Image handImage;
    sf::Image arrowImage;
    if (!handImage.loadFromFile("handpointer.png")) {
        // Handle loading error
        return -1;
    }

    if (!handPointer.loadFromPixels(handImage.getPixelsPtr(), handImage.getSize(), { 0, 0 })) {
        // Handle loading error
        return -1;
    }
    if (!arrowImage.loadFromFile("arrowPointer.png")) {
        // Handle loading error
        return -1;
    }

    if (!arrowPointer.loadFromPixels(arrowImage.getPixelsPtr(), arrowImage.getSize(), { 0, 0 })) {
        // Handle loading error
        return -1;
    }
    bool isHovered = false;
    sf::Vector2f startPoint(phimdangchieu.getPosition().x, phimdangchieu.getPosition().y + 60);
    sf::Vector2f endPoint(posterPhim[2].getPosition().x + posterPhim[2].getGlobalBounds().width + 500, phimdangchieu.getPosition().y + 60);

    sf::Vector2f direction = endPoint - startPoint;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    sf::RectangleShape line(sf::Vector2f(length, 2)); // Độ dày của đường thẳng là 5 pixels
    line.setPosition(startPoint);
    line.setFillColor(sf::Color::Black);


    // page 2
    int selectedPhimNumber;
    sf::Text noiDungPhim;
    noiDungPhim.setFont(lora);
    noiDungPhim.setCharacterSize(52); // K�ch th??c font
    noiDungPhim.setFillColor(sf::Color::Black); // M�u v?n b?n
    noiDungPhim.setString("Noi Dung Phim"); // N?i dung v?n b?n
    noiDungPhim.setPosition(110, 0 + 90 + 30); // V? tr� c?a v?n b?n tr�n c?a s?

    sf::Text coTheBanCungThich;
    coTheBanCungThich.setFont(lora);
    coTheBanCungThich.setCharacterSize(52); // K�ch th??c font
    coTheBanCungThich.setFillColor(sf::Color::Black); // M�u v?n b?n
    coTheBanCungThich.setString("Co The Ban Cung Thich"); // N?i dung v?n b?n
    coTheBanCungThich.setPosition((window.getSize().x - coTheBanCungThich.getGlobalBounds().width) / 2, 700); // V? tr� c?a v?n b?n tr�n c?a s?

    sf::Texture orderButtonTextture;
    if (!orderButtonTextture.loadFromFile("orderButton.png")) {
        // Xử lý lỗi nếu không tải được hình ảnh
        return -1;
    }

    // Tạo sprite và đặt texture cho sprite
    sf::Sprite orderButton(orderButtonTextture);
    orderButton.setPosition(100 + 60, 400 + (static_cast<float>(window.getSize().y) - static_cast<float>(borderPosterPhim[0].getSize().y)) / 2 + 50);

    sf::Text contentText[2];
    phim selectedPhim;
    bool daloadtheloai = 0;
    bool daloadphimchieu = 0;
    //// page 3
    int selectedNgay;
    bool clickedSuatChieu = 0;
    sf::Text thuNgay[10];
    sf::Text ngayThang[10];
    sf::Text MENU;
    MENU.setFont(cinema);
    MENU.setCharacterSize(70); // K�ch th??c font
    MENU.setFillColor(sf::Color::Black); // M�u v?n b?n
    MENU.setString("MENU"); // N?i dung v?n b?n
    MENU.setPosition((window.getSize().x - MENU.getGlobalBounds().width) / 2 - 120, 250);
    int countSuatChieu = 0;
    for (int i = 0; i < 10; i++) {
        ngayThang[i].setFont(lora);
        ngayThang[i].setCharacterSize(20);
        ngayThang[i].setFillColor(sf::Color::Black);
        ngayThang[i].setString(to_string(admin1.getsuat(i, 0, 0).getthoigianchieu().getngay()) + " " + to_string(admin1.getsuat(i, 0, 0).getthoigianchieu().getthang()));
        if (admin1.getsuat(i, 0, 0).getthoigianchieu().getngay() < 10 || admin1.getsuat(i, 0, 0).getthoigianchieu().getthang()) {
            if (admin1.getsuat(i, 0, 0).getthoigianchieu().getngay() < 10) {
                if (admin1.getsuat(i, 0, 0).getthoigianchieu().getthang() < 10) {
                    ngayThang[i].setString("0" + to_string(admin1.getsuat(i, 0, 0).getthoigianchieu().getngay()) + " " + "0" + to_string(admin1.getsuat(i, 0, 0).getthoigianchieu().getthang()));
                }
                else {
                    ngayThang[i].setString("0" + to_string(admin1.getsuat(i, 0, 0).getthoigianchieu().getngay()) + " " + to_string(admin1.getsuat(i, 0, 0).getthoigianchieu().getthang()));
                }
            }
            else if (admin1.getsuat(i, 0, 0).getthoigianchieu().getthang() < 10) {
                ngayThang[i].setString(to_string(admin1.getsuat(i, 0, 0).getthoigianchieu().getngay()) + " " + "0" + to_string(admin1.getsuat(i, 0, 0).getthoigianchieu().getthang()));

            }
        }
        thuNgay[i].setFont(lora);
        thuNgay[i].setCharacterSize(20);
        thuNgay[i].setFillColor(sf::Color::Black);

        switch (admin1.getsuat(i, 0, 0).getthoigianchieu().getthungay()) {
        case 0:
            thuNgay[i].setString("SUN");
            break;
        case 1:

            thuNgay[i].setString("MON");
            break;
        case 2:
            thuNgay[i].setString("TUES");
            break;
        case 3:
            thuNgay[i].setString("WED");
            break;
        case 4:
            thuNgay[i].setString("THURS");
            break;
        case 5:
            thuNgay[i].setString("FRI");
            break;
        case 6:
            thuNgay[i].setString("SAT");
            break;
        default:
            // Xử lý trường hợp không nằm trong các giá trị trên (nếu cần)
            break;
        }
    }

    const int numRectangles = 10;
    std::vector<sf::RectangleShape> thuNgayBorder(numRectangles);
    // Initialize rectangles and texts
    for (int i = 0; i < numRectangles; ++i) {
        // Create rectangle for the border
        thuNgayBorder[i].setSize(sf::Vector2f(133, thuNgay[i].getGlobalBounds().height + ngayThang[i].getGlobalBounds().height + 18));
        thuNgayBorder[i].setFillColor(sf::Color::Transparent);
        thuNgayBorder[i].setOutlineColor(sf::Color::White);
        thuNgayBorder[i].setOutlineThickness(2.0f);
    }
    for (int i = 0; i < 6; i++) {
        thuNgay[i].setPosition(i * 150 + 50 + 60, 50);
        ngayThang[i].setPosition(i * 150 + 50, 50);
        thuNgayBorder[i].setPosition(ngayThang[i].getPosition().x, ngayThang[i].getPosition().y - 10);
    }
    for (int i = 6; i < 10; i++) {
        thuNgay[i].setPosition((i - 6) * 150 + 50 + 60, 50 + thuNgayBorder[0].getSize().y);
        ngayThang[i].setPosition((i - 6) * 150 + 50, 50 + thuNgayBorder[0].getSize().y);
        thuNgayBorder[i].setPosition(ngayThang[i].getPosition().x, ngayThang[i].getPosition().y - 10);
    }
    std::vector<sf::RectangleShape> suatChieuBorder;
    std::vector<sf::Text> suatChieu;
    const int buttonCount = 3;
    int quantities[buttonCount][buttonCount] = { 0 };

    sf::Text quantityTexts[buttonCount];
    sf::RectangleShape buttons[2 * buttonCount];
    sf::Text buttonTexts[2 * buttonCount];


    int sizeQuantities[buttonCount] = { 0 };
    int gioHangMenu[9] = { 0 };
    sf::Text sizeText[buttonCount];
    sf::RectangleShape increaseButtons[buttonCount];
    sf::RectangleShape decreaseButtons[buttonCount];
    sf::Text increaseTexts[buttonCount]; // Add array for increaseText
    sf::Text decreaseTexts[buttonCount]; // Add array for decreaseText
    const int spriteCount = 3;
    std::vector<sf::Sprite> coCaCoLa;
    std::vector<sf::Sprite> pepSi;
    std::vector<sf::Sprite> popCorn;

    for (int j = 0; j < spriteCount; j++) {
        for (int i = 0; i < spriteCount; ++i)
        {
            sf::Texture* tmptexture = new sf::Texture;
            if (!(*tmptexture).loadFromFile(to_string(i + j * 3) + ".png")) {
                if (!(*tmptexture).loadFromFile(to_string(i + j * 3) + ".jpg")) {
                    return -1;
                }
            }
            sf::Sprite* tmpSprite = new sf::Sprite;
            (*tmpSprite).setTexture(*tmptexture);
            (*tmpSprite).setPosition(j * 300.f + 150, MENU.getPosition().y + 100);
            if (j == 0) {
                coCaCoLa.push_back(*tmpSprite);
            }
            else if (j == 1) {
                pepSi.push_back(*tmpSprite);

            }
            else {
                popCorn.push_back(*tmpSprite);
            }
        }
    }
    for (int i = 0; i < buttonCount; ++i)
    {
        sizeText[i].setFont(lora);
        sizeText[i].setCharacterSize(24);
        sizeText[i].setFillColor(sf::Color::Black);

        if (i == 0) {
            sizeText[i].setPosition(coCaCoLa[0].getPosition().x + 40, coCaCoLa[0].getPosition().y + 220);
        }
        else if (i == 1) {
            sizeText[i].setPosition(pepSi[0].getPosition().x + 40, pepSi[0].getPosition().y + 220);

        }
        else {
            sizeText[i].setPosition(popCorn[0].getPosition().x + 40, popCorn[0].getPosition().y + 220);

        }



        increaseButtons[i].setSize(sf::Vector2f(50, 50));
        increaseButtons[i].setFillColor(sf::Color::Transparent);
        increaseButtons[i].setOutlineColor(sf::Color::Black);

        increaseButtons[i].setPosition(sizeText[i].getPosition().x + 90, sizeText[i].getPosition().y);
        increaseButtons[i].setOutlineThickness(1.0f);

        // Set text for increase button
        increaseTexts[i].setFont(lora);
        increaseTexts[i].setCharacterSize(30);
        increaseTexts[i].setFillColor(sf::Color::Black);
        increaseTexts[i].setString(">");

        decreaseButtons[i].setSize(sf::Vector2f(50, 50));
        decreaseButtons[i].setFillColor(sf::Color::Transparent);
        decreaseButtons[i].setPosition(sizeText[i].getPosition().x - 70, sizeText[i].getPosition().y);
        decreaseButtons[i].setOutlineColor(sf::Color::Black);
        decreaseButtons[i].setOutlineThickness(1.0f);

        // Set text for decrease button
        decreaseTexts[i].setFont(lora);
        decreaseTexts[i].setCharacterSize(30);
        decreaseTexts[i].setPosition(decreaseButtons[i].getPosition().x + 15, decreaseButtons[i].getPosition().y);
        increaseTexts[i].setPosition(increaseButtons[i].getPosition().x + 15., decreaseTexts[i].getPosition().y);
        decreaseTexts[i].setFillColor(sf::Color::Black);
        decreaseTexts[i].setString("<");
    }

    for (int i = 0; i < buttonCount; ++i)
    {
        quantityTexts[i].setFillColor(sf::Color::Black);
        quantityTexts[i].setFont(lora);
        quantityTexts[i].setCharacterSize(24);
        quantityTexts[i].setPosition(sizeText[i].getPosition().x + 20, sizeText[i].getPosition().y + 70);

        for (int j = 0; j < 2; ++j)
        {
            buttons[i * 2 + j].setSize(sf::Vector2f(50, 50));
            buttons[i * 2 + j].setFillColor(j == 0 ? sf::Color::Green : sf::Color::Red);
            if (j % 2 == 0) {
                buttons[i * 2 + j].setPosition(increaseButtons[i].getPosition().x, quantityTexts[i].getPosition().y);

            }
            else {
                buttons[i * 2 + j].setPosition(decreaseButtons[i].getPosition().x, quantityTexts[i].getPosition().y);
            }
            buttonTexts[i * 2 + j].setFont(lora);
            buttonTexts[i * 2 + j].setCharacterSize(30);
            buttonTexts[i * 2 + j].setPosition(buttons[i * 2 + j].getPosition().x + 10, buttons[i & 2 + j].getPosition().y);
            buttonTexts[i * 2 + j].setFillColor(sf::Color::Black);
            // Dấu "+" và "-"
            if (j == 0)
                buttonTexts[i * 2 + j].setString("+");
            else
                buttonTexts[i * 2 + j].setString("-");
        }
    }

    sf::Texture confirmTexture;
    if (!confirmTexture.loadFromFile("confirmButton.png")) {
        std::cerr << "Error loading confirm button texture!" << std::endl;
        return -1;
    }

    sf::Sprite confirmButton;
    confirmButton.setTexture(confirmTexture);
    confirmButton.setPosition(1000, 600);

    sf::Texture xacnhanTexture;
    if (!xacnhanTexture.loadFromFile("xacnhanButton.png")) {
        std::cerr << "Error loading xacnhan button texture!" << std::endl;
        return -1;
    }
    sf::Texture menuQuanTexture;
    if (!menuQuanTexture.loadFromFile("menuQuan.png")) {
        // Xử lý lỗi nếu không tải được hình ảnh
        return -1;
    }

    // Tạo sprite và đặt texture cho sprite
    sf::Sprite menuQuan(menuQuanTexture);

    menuQuan.setPosition(1100, 50);
    menuQuan.setScale(0.65, 0.65);

    sf::Sprite xacnhanButton;
    xacnhanButton.setTexture(xacnhanTexture);
    xacnhanButton.setPosition(600, 735);
    bool clickedSuatChieu2 = 0;
    const int rows = 7;
    const int cols = 11;
    const float squareSize = 50;
    const float borderSize = 2.f;
    bool datGheNgoi[cols] = { 0 };
    int hangDatGhe = 18;
    string gheNgoiDaDat = "";
    int tongTienGheNgoi = 0;
    sf::RectangleShape gheNgoi[rows][cols];
    sf::Text textLoaiGhe[3];

    sf::RectangleShape loaiGheNgoi[3];
    for (int i = 0; i < 3; i++) {
        loaiGheNgoi[i].setSize(sf::Vector2f(squareSize, squareSize));
        loaiGheNgoi[i].setPosition(200, 200 + 70 * i);
        loaiGheNgoi[i].setOutlineThickness(1);
        textLoaiGhe[i].setPosition(loaiGheNgoi[i].getPosition().x + 70, 10 + loaiGheNgoi[i].getPosition().y);
        textLoaiGhe[i].setFillColor(sf::Color::Black); // M�u v?n b?n
        textLoaiGhe[i].setFont(lora);
        textLoaiGhe[i].setCharacterSize(18); // K�ch th??c font
        textLoaiGhe[i].setStyle(sf::Text::Bold); // 
    }
    loaiGheNgoi[0].setOutlineColor(sf::Color::Green);
    loaiGheNgoi[1].setOutlineColor(sf::Color::Blue);
    loaiGheNgoi[2].setOutlineColor(sf::Color::Magenta);
    textLoaiGhe[0].setString("GHE THUONG");
    textLoaiGhe[1].setString("GHE VIP");
    textLoaiGhe[2].setString("GHE COUP");

    bool daLoadGheNgoi = 0;

    sf::Text textGheNgoi[rows][cols];
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            string tmp = "";
            tmp += i + 48 + 17;
            tmp += to_string(j);
            textGheNgoi[i][j].setString(tmp);
            textGheNgoi[i][j].setFillColor(sf::Color::Black); // M�u v?n b?n
            textGheNgoi[i][j].setFont(lora);
            textGheNgoi[i][j].setCharacterSize(18); // K�ch th??c font
            textGheNgoi[i][j].setPosition(500 + j * (squareSize + borderSize + 5) + 5, 10 + 200 + i * (squareSize + borderSize + 5));
            gheNgoi[i][j].setSize(sf::Vector2f(squareSize, squareSize));
            gheNgoi[i][j].setOutlineThickness(1);
            gheNgoi[i][j].setPosition(500 + j * (squareSize + borderSize + 5), 200 + i * (squareSize + borderSize + 5));
            gheNgoi[i][j].setOutlineColor(sf::Color::Black);
        }
    }
    string selectedPhong = "";
    sf::Texture nextTexture;
    if (!nextTexture.loadFromFile("nextButton.png")) {
        std::cerr << "Error loading xacnhan button texture!" << std::endl;
        return -1;
    }

    sf::Sprite nextButton;
    nextButton.setTexture(nextTexture);
    nextButton.setPosition(400.f, 400.f);

    sf::Texture xacNhanDatVeTexture;
    if (!xacNhanDatVeTexture.loadFromFile("xacNhanDatVe.png")) {
        std::cerr << "Error loading xacnhan button texture!" << std::endl;
        return -1;
    }

    sf::Sprite xacNhanDatVeButton;
    xacNhanDatVeButton.setTexture(xacNhanDatVeTexture);
    xacNhanDatVeButton.setPosition(loaiGheNgoi[2].getPosition().x, gheNgoi[6][0].getPosition().y);
    bool datinhtienthungay = 0;


    // count Page == 6 
    int giaVe = 0;
    now ngayDat;
    string bapNuoc = "";
    string tenPhim = "";
    Time ngayChieu;
    string gheNgoiVe = "";
    string loaiGhe = "";
    bool daThemVe = 0;
    bool gheTrongFull = 1;
    int array2D[rows1][cols1];
    int arrayK = 0, arrayO = 0;
    bool daVeQR = 0;



    sf::Texture movieSpriteTexture;
    if (!movieSpriteTexture.loadFromFile("movieSprite.png")) {
        std::cerr << "Error loading movieSpriteTexture texture!" << std::endl;
        return -1;
    }
    sf::Sprite movieSprite;
    movieSprite.setTexture(movieSpriteTexture);
    movieSprite.setScale(1, 0.675);
    movieSprite.setPosition(0, 680);

    sf::RectangleShape khungVe(sf::Vector2f(600, 1200));
    khungVe.setPosition(500, 20);

    // Thiết lập màu nền là trắng
    khungVe.setFillColor(sf::Color::White);

    // Thiết lập màu viền là đen
    khungVe.setOutlineColor(sf::Color::Black);

    // Thiết lập độ dày của đường viền
    khungVe.setOutlineThickness(2.0f);




    sf::Text contentSprite[7];

    for (int i = 0; i < 5; i++) {
        contentSprite[i].setFont(lora);
        contentSprite[i].setCharacterSize(28); // K�ch th??c font
        contentSprite[i].setFillColor(sf::Color::White); // M�u v?n b?n
        contentSprite[i].setPosition(370 * i + 300, movieSprite.getPosition().y);
    }



    for (int i = 5; i < 7; i++) {
        contentSprite[i].setFont(lora);
        contentSprite[i].setCharacterSize(28); // K�ch th??c font
        contentSprite[i].setFillColor(sf::Color::White); // M�u v?n b?n
        contentSprite[i].setPosition(370 * (i - 5) + 300, 40 + movieSprite.getPosition().y);
    }

    contentSprite[6].setPosition(370 * (6 - 5) + 130, 40 + movieSprite.getPosition().y);
    contentSprite[1].setPosition(370 * (6 - 5) + 130, 80 + movieSprite.getPosition().y);
    contentSprite[2].setPosition(370 * 2 + 300 + 150, movieSprite.getPosition().y);
    contentSprite[3].setPosition(370 * (6 - 5) + 130, 120 + movieSprite.getPosition().y);
    contentSprite[4].setPosition(370 * 2 + 300 + 150, movieSprite.getPosition().y + 40);
    contentSprite[0].setStyle(sf::Text::Bold);

    sf::Texture texturePhimPage6;

    sf::Sprite spritePhimPage6;

    int selectedSuatChieu = 0;


    sf::Text contentVe[7];

    for (int i = 0; i < 4; i++) {
        contentVe[i].setFont(Freck);
        contentVe[i].setCharacterSize(32); // K�ch th??c font
        contentVe[i].setFillColor(sf::Color::Black); // M�u v?n b?n
        contentVe[i].setPosition(khungVe.getPosition().x + 200, i * 50 + khungVe.getPosition().y + 300);
    }
    for (int i = 4; i < 7; i++) {
        contentVe[i].setFont(Freck);
        contentVe[i].setCharacterSize(32); // K�ch th??c font
        contentVe[i].setFillColor(sf::Color::Black); // M�u v?n b?n
        contentVe[i].setPosition(khungVe.getPosition().x + 200, 3 * 50 + khungVe.getPosition().y + 230 + i * 50);
    }
    contentVe[0].setCharacterSize(33); // K�ch th??c font

    contentVe[0].setStyle(sf::Text::Bold);


    while (window.isOpen()) {
        now rightNow;
        sf::Event event;
        //admin1.nhapphongchieu("DanhSachPhong.txt");
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Lấy vị trí của chuột khi nhấn
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    if (backButton.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                        if (countPage != 1) {
                            if (countPage == 2) {
                                searchBar.setPosition(searchBar.getPosition().x, 20);
                                phimdangchieu.setPosition(phimdangchieu.getPosition().x, 221 + 50);
                            }
                            countPage--;
                        }

                    }
                }
            }
            if (countPage == 1) {

                clickedSuatChieu = 0;
                daloadphimchieu = 0;
                backButton.setPosition(5, searchBar.getPosition().y);
                if (!daloadmenuphim) {
                    columnnow = 1;
                    rownow = 1;
                    string tmp = "000";
                    for (int i = 0; i < admin1.getsophim(); i++) {
                        if (!(texturePhim[i]).loadFromFile(tmp + ".jpg")) {
                            (texturePhim[i]).loadFromFile(tmp + ".png");
                            if (!(texturePhim[i]).loadFromFile(tmp + ".png")) {
                                if (!(texturePhim[i]).loadFromFile(tmp + ".jfif")) {
                                    return EXIT_FAILURE;
                                }
                            }
                        }
                        tmp = admin::increaseString(tmp);
                        posterPhim[i].setPosition(167.5 * columnnow + (columnnow - 1) * 270, 385.2 * (rownow - 1) + phimdangchieu.getPosition().y + 100 + (rownow - 1) * 200);
                        borderPosterPhim[i].setPosition(167.5 * columnnow + (columnnow - 1) * 270, 385.2 * (rownow - 1) + phimdangchieu.getPosition().y + 100 + (rownow - 1) * 200);
                        posterPhim[i].setTexture(texturePhim[i]);
                        sf::Vector2f newSize(270, 385.2);
                        float scaleX = newSize.x / (posterPhim[i]).getLocalBounds().width;
                        float scaleY = newSize.y / (posterPhim[i]).getLocalBounds().height;
                        (posterPhim[i]).setScale(scaleX, scaleY);
                        columnnow++;


                        if (columnnow > 3) {
                            columnnow = 1;
                            rownow++;
                        }
                        daloadmenuphim = 1;
                        daloadtheloai = 0;
                    }
                    for (int i = 0; i < admin1.getsophim(); i++) {
                        int textDistance[4];
                        for (int p = 0; p < 4; p++) {
                            textDistance[p] = 0;
                        }
                        std::string tmpText;
                        tmpText = admin1.getdanhsachphim()[i].gettenphim();
                        tenphim[i].setString(admin1.chinhSuaText(tmpText, textDistance, 0, 1));
                        tenphim[i].setFont(lora);
                        tenphim[i].setCharacterSize(20);
                        tenphim[i].setStyle(sf::Text::Bold);
                        tenphim[i].setFillColor(sf::Color::Black);
                        tenphim[i].setPosition(posterPhim[i].getPosition().x + (posterPhim[i].getGlobalBounds().width - tenphim[i].getGlobalBounds().width) / 2, 385.2 + posterPhim[i].getPosition().y + 15);

                        tmpText = admin1.getdanhsachphim()[i].gettheloai();
                        tmpText = "The loai : " + tmpText;
                        thongtinphim1[i].second.setString(admin1.chinhSuaText(tmpText, textDistance, 1, 0));
                        thongtinphim1[i].second.setFont(lora);
                        thongtinphim1[i].second.setCharacterSize(20);
                        thongtinphim1[i].second.setFillColor(sf::Color::Black);
                        thongtinphim1[i].second.setPosition(posterPhim[i].getPosition().x + (posterPhim[i].getGlobalBounds().width - thongtinphim1[i].second.getGlobalBounds().width) / 2, textDistance[0] * 4 + tenphim[i].getPosition().y + 20);

                        tmpText = to_string(admin1.getdanhsachphim()[i].getthoiluong());
                        tmpText = "Thoi luong : " + tmpText + " phut";
                        thongtinphim2[i].setString(admin1.chinhSuaText(tmpText, textDistance, 2, 0));
                        thongtinphim2[i].setFont(lora);
                        thongtinphim2[i].setCharacterSize(20);
                        thongtinphim2[i].setFillColor(sf::Color::Black);
                        thongtinphim2[i].setPosition(posterPhim[i].getPosition().x + (posterPhim[i].getGlobalBounds().width - thongtinphim2[i].getGlobalBounds().width) / 2, textDistance[1] * 4 + thongtinphim1[i].second.getPosition().y + 20);

                        tmpText = "Khoi Chieu : " + to_string(admin1.getdanhsachphim()[i].getkhoichieu().getngay()) + "-" + to_string(admin1.getdanhsachphim()[i].getkhoichieu().getthang()) + "-" + to_string(admin1.getdanhsachphim()[i].getkhoichieu().getnam());
                        thongtinphim3[i].setString(admin1.chinhSuaText(tmpText, textDistance, 3, 0));
                        thongtinphim3[i].setFont(lora);
                        thongtinphim3[i].setCharacterSize(20);
                        thongtinphim3[i].setFillColor(sf::Color::Black);
                        thongtinphim3[i].setPosition(posterPhim[i].getPosition().x + (posterPhim[i].getGlobalBounds().width - thongtinphim3[i].getGlobalBounds().width) / 2, textDistance[2] * 4 + thongtinphim2[i].getPosition().y + 20);
                        int tongDistance = textDistance[0] + textDistance[1] + textDistance[2] + textDistance[3];
                        if (tongDistance != 0) {
                            int rowGan = i + (3 - (i % 3));
                            for (int o = rowGan; o < soPhim; o++) {
                                borderPosterPhim[o].setPosition(borderPosterPhim[o].getPosition().x, borderPosterPhim[o].getPosition().y + tongDistance);
                                posterPhim[o].setPosition(posterPhim[o].getPosition().x, posterPhim[o].getPosition().y + tongDistance);
                            }
                        }
                    }

                }

                if (event.type == sf::Event::MouseWheelScrolled) {
                    if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                        if (event.mouseWheelScroll.delta > 0) {


                            if (searchBar.getPosition().y != 20)
                            {
                                phimdangchieu.move(0, 80);
                                for (int i = 0; i < soPhim; i++) {
                                    posterPhim[i].move(0, 80);
                                    borderPosterPhim[i].move(0, 80);
                                    tenphim[i].move(0, 80);
                                    thongtinphim1[i].second.move(0, 80);
                                    thongtinphim2[i].move(0, 80);
                                    thongtinphim3[i].move(0, 80);
                                }
                                viTriSearchBar += 80;
                                searchBar.move(0, 80);
                                searchBoxText.move(0, 80);
                                line.move(0, 80);
                            }

                        }
                        else if (event.mouseWheelScroll.delta < 0) {
                            phimdangchieu.move(0, -80);

                            for (int i = 0; i < soPhim; i++) {
                                posterPhim[i].move(0, -80);
                                borderPosterPhim[i].move(0, -80);
                                tenphim[i].move(0, -80);
                                thongtinphim1[i].second.move(0, -80);
                                thongtinphim2[i].move(0, -80);
                                thongtinphim3[i].move(0, -80);
                            }
                            viTriSearchBar -= 80;
                            searchBar.move(0, -80);
                            searchBoxText.move(0, -80);
                            line.move(0, -80);
                        }
                    }
                }
                else if (event.type == sf::Event::MouseMoved) {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    isHovered = false;
                    // Kiểm tra từng sprite trong mảng
                    for (int i = 0; i < soPhim; ++i) {
                        if (posterPhim[i].getGlobalBounds().contains(sf::Vector2f(mousePosition)) || thongtinphim1[i].second.getGlobalBounds().contains(sf::Vector2f(mousePosition)) || thongtinphim1[i].second.getGlobalBounds().contains(sf::Vector2f(mousePosition)) || thongtinphim2[i].getGlobalBounds().contains(sf::Vector2f(mousePosition)) || thongtinphim3[i].getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                            // Nếu con trỏ chuột hover vào sprite thứ i
                            // Thực hiện các hành động mong muốn, ví dụ: thay đổi màu sprite
                            posterPhim[i].setColor(sf::Color(200, 200, 200));
                            isHovered = true;
                        }
                        else {
                            posterPhim[i].setColor(sf::Color(255, 255, 255));
                        }
                        if (isHovered) {
                            window.setMouseCursor(handPointer);
                        }
                        else {
                            window.setMouseCursor(arrowPointer);

                        }
                    }
                }
                else if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // Lấy vị trí của chuột khi nhấn
                        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                        // Kiểm tra xem vị trí chuột có nằm trong phạm vi của sprite không
                        for (int i = 0; i < soPhim; ++i) {
                            coTheBanCungThich.setPosition((window.getSize().x - coTheBanCungThich.getGlobalBounds().width) / 2, 700);
                            noiDungPhim.setPosition(110, 0 + 90 + 30);
                            if (borderPosterPhim[i].getGlobalBounds().contains(sf::Vector2f(mousePosition)) || thongtinphim1[i].second.getGlobalBounds().contains(sf::Vector2f(mousePosition)) || thongtinphim2[i].getGlobalBounds().contains(sf::Vector2f(mousePosition)) || thongtinphim3[i].getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                                selectedMovie = (*(admin1.getdanhsachphim() + i)).getid();
                                selectedPhimNumber = i;
                                window.setMouseCursor(arrowPointer);
                                selectedPhim = admin1.getdanhsachphim()[admin1.getphimtuid(selectedMovie)];

                                for (int m = 0; m < 2; m++) {
                                    contentText[m].setFont(lora);
                                    contentText[m].setCharacterSize(20);
                                    contentText[m].setFillColor(sf::Color::Black);
                                    contentText[m].setPosition(500, (static_cast<float>(window.getSize().y) - static_cast<float>(borderPosterPhim[selectedPhimNumber].getSize().y)) / 2 + 140 + m * 50);
                                }


                                contentText[0].setString("Khoi Chieu Den : " + to_string(selectedPhim.gethankhoichieu().getngay()) + "-" + to_string(selectedPhim.gethankhoichieu().getthang()) + "-" + to_string(selectedPhim.gethankhoichieu().getnam()));
                                contentText[1].setString(selectedPhim.getgioithieuphim());



                                countPage = 2;
                            }
                        }
                    }
                }
            }
            else if (countPage == 2) {
                clickedSuatChieu = 0;
                if (areGenresMatching("Kinh Di", selectedPhim.gettheloai())) {
                    noiDungPhim.setFont(horror);
                }
                else if (areGenresMatching("Khoa Hoc", selectedPhim.gettheloai())) {
                    noiDungPhim.setFont(tech);

                }
                else if (areGenresMatching("Hai Huoc", selectedPhim.gettheloai())) {
                    noiDungPhim.setFont(funny);

                }
                else if (areGenresMatching("Tinh Cam", selectedPhim.gettheloai())) {
                    noiDungPhim.setFont(love);

                }
                else if (areGenresMatching("Hanh Dong", selectedPhim.gettheloai())) {
                    noiDungPhim.setFont(action);
                }
                else {
                    noiDungPhim.setFont(lora);

                }
                backButton.setPosition(5, CGV.getPosition().y);
                if (!daloadphimchieu) {
                    borderPosterPhim[selectedPhimNumber].setPosition(100, 50 + noiDungPhim.getPosition().y + 50);
                    posterPhim[selectedPhimNumber].setPosition(100, 50 + noiDungPhim.getPosition().y + 50);
                    tenphim[selectedPhimNumber].setPosition(500, 50 + noiDungPhim.getPosition().y + 50);
                    thongtinphim1Tmp.setString(admin1.getdanhsachphim()[selectedPhimNumber].gettheloai());
                    thongtinphim1Tmp.setPosition(500, 50 + noiDungPhim.getPosition().y + 50 + 35);
                    thongtinphim2[selectedPhimNumber].setPosition(500, 50 + noiDungPhim.getPosition().y + 50 + 70);

                    thongtinphim3[selectedPhimNumber].setPosition(500, 50 + noiDungPhim.getPosition().y + 50 + 105);
                    daloadphimchieu = 1;
                }
                if (!daloadtheloai) {
                    columnnow = 1;
                    rownow = 1;
                    for (int i = 0; i < admin1.getsophim(); i++) {
                        if (areGenresMatching(admin1.getdanhsachphim()[i].gettheloai(), selectedPhim.gettheloai()) && i != selectedPhimNumber) {
                            countTheLoai.push_back(i);
                            if (!(texturePhim[i]).loadFromFile(admin1.getdanhsachphim()[i].getid() + ".jpg")) {
                                (texturePhim[i]).loadFromFile(admin1.getdanhsachphim()[i].getid() + ".png");
                                if (!(texturePhim[i]).loadFromFile(admin1.getdanhsachphim()[i].getid() + ".png")) {
                                    if (!(texturePhim[i]).loadFromFile(admin1.getdanhsachphim()[i].getid() + ".jfif")) {
                                        return EXIT_FAILURE;

                                    }
                                }
                            }
                            posterPhim[i].setPosition(167.5 * columnnow + (columnnow - 1) * 270, coTheBanCungThich.getPosition().y + 100 + 385.2 * (rownow - 1) + (rownow - 1) * 200);
                            borderPosterPhim[i].setPosition(167.5 * columnnow + (columnnow - 1) * 270, 385.2 * (rownow - 1) + coTheBanCungThich.getPosition().y + 100 + (rownow - 1) * 200);
                            posterPhim[i].setTexture(texturePhim[i]);
                            sf::Vector2f newSize(270, 385.2);
                            float scaleX = newSize.x / (posterPhim[i]).getLocalBounds().width;
                            float scaleY = newSize.y / (posterPhim[i]).getLocalBounds().height;
                            (posterPhim[i]).setScale(scaleX, scaleY);
                            columnnow++;
                            if (columnnow > 3) {
                                columnnow = 1;
                                rownow++;
                            }
                            int textDistance[4];
                            for (int p = 0; p < 4; p++) {
                                textDistance[p] = 0;
                            }
                            std::string tmpText;
                            tmpText = admin1.getdanhsachphim()[i].gettenphim();
                            tenphim[i].setString(admin1.chinhSuaText(tmpText, textDistance, 0, 1));
                            tenphim[i].setFont(lora);
                            tenphim[i].setCharacterSize(20);
                            tenphim[i].setStyle(sf::Text::Bold);
                            tenphim[i].setFillColor(sf::Color::Black);
                            tenphim[i].setPosition(posterPhim[i].getPosition().x + (posterPhim[i].getGlobalBounds().width - tenphim[i].getGlobalBounds().width) / 2, 385.2 + posterPhim[i].getPosition().y + 15);

                            tmpText = admin1.getdanhsachphim()[i].gettheloai();
                            tmpText = "The loai : " + tmpText;
                            thongtinphim1[i].second.setString(admin1.chinhSuaText(tmpText, textDistance, 1, 0));
                            thongtinphim1[i].second.setFont(lora);
                            thongtinphim1[i].second.setCharacterSize(20);
                            thongtinphim1[i].second.setFillColor(sf::Color::Black);
                            thongtinphim1[i].second.setPosition(posterPhim[i].getPosition().x + (posterPhim[i].getGlobalBounds().width - thongtinphim1[i].second.getGlobalBounds().width) / 2, textDistance[0] * 4 + tenphim[i].getPosition().y + 20);

                            tmpText = to_string(admin1.getdanhsachphim()[i].getthoiluong());
                            tmpText = "Thoi luong : " + tmpText + " phut";
                            thongtinphim2[i].setString(admin1.chinhSuaText(tmpText, textDistance, 2, 0));
                            thongtinphim2[i].setFont(lora);
                            thongtinphim2[i].setCharacterSize(20);
                            thongtinphim2[i].setFillColor(sf::Color::Black);
                            thongtinphim2[i].setPosition(posterPhim[i].getPosition().x + (posterPhim[i].getGlobalBounds().width - thongtinphim2[i].getGlobalBounds().width) / 2, textDistance[1] * 4 + thongtinphim1[i].second.getPosition().y + 20);

                            tmpText = "Khoi Chieu : " + to_string(admin1.getdanhsachphim()[i].getkhoichieu().getngay()) + "-" + to_string(admin1.getdanhsachphim()[i].getkhoichieu().getthang()) + "-" + to_string(admin1.getdanhsachphim()[i].getkhoichieu().getnam());
                            thongtinphim3[i].setString(admin1.chinhSuaText(tmpText, textDistance, 3, 0));
                            thongtinphim3[i].setFont(lora);
                            thongtinphim3[i].setCharacterSize(20);
                            thongtinphim3[i].setFillColor(sf::Color::Black);
                            thongtinphim3[i].setPosition(posterPhim[i].getPosition().x + (posterPhim[i].getGlobalBounds().width - thongtinphim3[i].getGlobalBounds().width) / 2, textDistance[2] * 4 + thongtinphim2[i].getPosition().y + 20);
                            int tongDistance = textDistance[0] + textDistance[1] + textDistance[2] + textDistance[3];
                            if (tongDistance != 0) {
                                int rowGan = i + (3 - (i % 3));
                                for (int o = rowGan; o < soPhim; o++) {
                                    borderPosterPhim[o].setPosition(borderPosterPhim[o].getPosition().x, borderPosterPhim[o].getPosition().y + tongDistance);
                                    posterPhim[o].setPosition(posterPhim[o].getPosition().x, posterPhim[o].getPosition().y + tongDistance);
                                }
                            }

                        }
                        daloadtheloai = 1;
                        daloadmenuphim = 0;
                    }
                }

                if (event.type == sf::Event::MouseWheelScrolled) {



                    if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                        if (event.mouseWheelScroll.delta > 0) {
                            if (CGV.getPosition().y != 20)
                            {
                                noiDungPhim.move(0, 80);
                                thongtinphim1Tmp.move(0, 80);
                                for (int i = 0; i < countTheLoai.size(); i++) {
                                    posterPhim[countTheLoai[i]].move(0, 80);
                                    borderPosterPhim[countTheLoai[i]].move(0, 80);
                                    tenphim[countTheLoai[i]].move(0, 80);
                                    thongtinphim1[countTheLoai[i]].second.move(0, 80);
                                    thongtinphim2[countTheLoai[i]].move(0, 80);
                                    thongtinphim3[countTheLoai[i]].move(0, 80);
                                }
                                posterPhim[selectedPhimNumber].move(0, 80);
                                borderPosterPhim[selectedPhimNumber].move(0, 80);
                                tenphim[selectedPhimNumber].move(0, 80);
                                thongtinphim1[selectedPhimNumber].second.move(0, 80);
                                thongtinphim2[selectedPhimNumber].move(0, 80);
                                thongtinphim3[selectedPhimNumber].move(0, 80);
                                coTheBanCungThich.move(0, 80);
                                orderButton.move(0, 80);
                                for (int k = 0; k < 2; k++) {
                                    contentText[k].move(0, 80);

                                }

                                CGV.move(0, 80);
                                backButton.move(0, 80);
                            }

                        }
                        else if (event.mouseWheelScroll.delta < 0) {
                            phimdangchieu.move(0, -80);
                            CGV.move(0, -80);
                            thongtinphim1Tmp.move(0, -80);
                            for (int i = 0; i < countTheLoai.size(); i++) {
                                posterPhim[countTheLoai[i]].move(0, -80);
                                borderPosterPhim[countTheLoai[i]].move(0, -80);
                                tenphim[countTheLoai[i]].move(0, -80);
                                thongtinphim1[countTheLoai[i]].second.move(0, -80);
                                thongtinphim2[countTheLoai[i]].move(0, -80);
                                thongtinphim3[countTheLoai[i]].move(0, -80);
                            }
                            posterPhim[selectedPhimNumber].move(0, -80);
                            borderPosterPhim[selectedPhimNumber].move(0, -80);
                            tenphim[selectedPhimNumber].move(0, -80);
                            thongtinphim1[selectedPhimNumber].second.move(0, -80);
                            thongtinphim2[selectedPhimNumber].move(0, -80);
                            thongtinphim3[selectedPhimNumber].move(0, -80);
                            backButton.move(0, -80);
                            coTheBanCungThich.move(0, -80);
                            orderButton.move(0, -80);
                            noiDungPhim.move(0, -80);
                            for (int k = 0; k < 2; k++) {
                                contentText[k].move(0, -80);

                            }

                        }
                    }
                }
                else if (event.type == sf::Event::MouseMoved) {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    isHovered = false;
                    // Kiểm tra từng sprite trong mảng
                    for (int i = 0; i < countTheLoai.size(); ++i) {
                        if (posterPhim[countTheLoai[i]].getGlobalBounds().contains(sf::Vector2f(mousePosition)) || thongtinphim1[countTheLoai[i]].second.getGlobalBounds().contains(sf::Vector2f(mousePosition)) || thongtinphim1[countTheLoai[i]].second.getGlobalBounds().contains(sf::Vector2f(mousePosition)) || thongtinphim2[countTheLoai[i]].getGlobalBounds().contains(sf::Vector2f(mousePosition)) || thongtinphim3[countTheLoai[i]].getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                            // Nếu con trỏ chuột hover vào sprite thứ i
                            // Thực hiện các hành động mong muốn, ví dụ: thay đổi màu sprite
                            posterPhim[countTheLoai[i]].setColor(sf::Color(200, 200, 200));
                            isHovered = true;
                        }
                        else {
                            posterPhim[countTheLoai[i]].setColor(sf::Color(255, 255, 255));
                        }
                        if (isHovered) {
                            window.setMouseCursor(handPointer);
                        }
                        else {
                            window.setMouseCursor(arrowPointer);

                        }
                    }
                }
                else if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // Lấy vị trí của chuột khi nhấn
                        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                        daloadphimchieu = 0;
                        // Kiểm tra xem vị trí chuột có nằm trong phạm vi của sprite không
                        for (int i = 0; i < countTheLoai.size(); ++i) {
                            if (borderPosterPhim[countTheLoai[i]].getGlobalBounds().contains(sf::Vector2f(mousePosition)) || thongtinphim1[countTheLoai[i]].second.getGlobalBounds().contains(sf::Vector2f(mousePosition)) || thongtinphim2[countTheLoai[i]].getGlobalBounds().contains(sf::Vector2f(mousePosition)) || thongtinphim3[countTheLoai[i]].getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                                daloadtheloai = 0;
                                daloadphimchieu = 0;
                                daloadmenuphim = 0;
                                selectedMovie = (*(admin1.getdanhsachphim() + countTheLoai[i])).getid();
                                selectedPhimNumber = countTheLoai[i];
                                window.setMouseCursor(arrowPointer);
                                selectedPhim = admin1.getdanhsachphim()[admin1.getphimtuid(selectedMovie)];
                                contentText[0].setString("Khoi Chieu Den : " + to_string(selectedPhim.gethankhoichieu().getngay()) + "-" + to_string(selectedPhim.gethankhoichieu().getthang()) + "-" + to_string(selectedPhim.gethankhoichieu().getnam()));
                                contentText[1].setString(selectedPhim.getgioithieuphim());
                                for (int k = 0; k < 2; k++) {
                                    contentText[k].setFont(lora);
                                    contentText[k].setCharacterSize(20);
                                    contentText[k].setFillColor(sf::Color::Black);
                                    contentText[k].setPosition(500, 50 * k + (static_cast<float>(window.getSize().y) - static_cast<float>(borderPosterPhim[selectedPhimNumber].getSize().y)) / 2 + 140);
                                }
                                countTheLoai.clear();
                                break;
                            }


                        }
                        if (orderButton.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                            // Thực hiện hành động khi orderButton được nhấn
                            countPage++;
                            // Đặt hành động bạn muốn thực hiện khi orderButton được nhấn
                        }
                    }

                }


            }
            else if (countPage == 3) {
                hangDatGhe = 18;
                for (int i = 0; i < 11; i++) {
                    datGheNgoi[i] = 0;
                }

                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    // Kiểm tra click
                    for (int i = 0; i < numRectangles; i++) {
                        if (thuNgayBorder[i].getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                            // Xử lý sự kiện khi click vào đây
                            selectedNgay = i;
                            clickedSuatChieu = 1;
                            suatChieu.clear();

                            for (int k = 0; k < selectedPhim.getsosuatchieu(); k++) {
                                {
                                    if (selectedPhim.getdanhsachsuatchieu()[k].getthoigianchieu() == admin1.getsuat(selectedNgay, 0, 0).getthoigianchieu()) {
                                        sf::Text suatchieuTmp;
                                        suatchieuTmp.setFont(lora);
                                        suatchieuTmp.setCharacterSize(30);
                                        suatchieuTmp.setFillColor(sf::Color::Black);
                                        if (selectedPhim.getdanhsachsuatchieu()[k].getthoigianchieu().getgio() < 10) {
                                            if (selectedPhim.getdanhsachsuatchieu()[k].getthoigianchieu().getphut() < 10) {
                                                suatchieuTmp.setString("0" + to_string(selectedPhim.getdanhsachsuatchieu()[k].getthoigianchieu().getgio()) + ":" + "0" + to_string(selectedPhim.getdanhsachsuatchieu()[k].getthoigianchieu().getphut()));
                                            }
                                            else {
                                                suatchieuTmp.setString("0" + to_string(selectedPhim.getdanhsachsuatchieu()[k].getthoigianchieu().getgio()) + ":" + to_string(selectedPhim.getdanhsachsuatchieu()[k].getthoigianchieu().getphut()));
                                            }
                                        }
                                        else {
                                            suatchieuTmp.setString(to_string(selectedPhim.getdanhsachsuatchieu()[k].getthoigianchieu().getgio()) + ":" + to_string(selectedPhim.getdanhsachsuatchieu()[k].getthoigianchieu().getphut()));
                                        }
                                        suatchieuTmp.setPosition(0, 100);
                                        suatChieu.push_back(suatchieuTmp);

                                    }

                                }
                            }


                        }


                    }

                    for (int r = 0; r < suatChieu.size(); r++) {
                        // Create rectangle for the border
                        sf::RectangleShape tmpSuatChieuBorder;
                        suatChieu[r].setPosition(120 * r + thuNgayBorder[0].getPosition().x, thuNgayBorder[6].getPosition().y + 100);
                        tmpSuatChieuBorder.setSize(sf::Vector2f(suatChieu[r].getGlobalBounds().width + 20, suatChieu[r].getGlobalBounds().height + 20));
                        tmpSuatChieuBorder.setPosition(suatChieu[r].getPosition().x, suatChieu[r].getPosition().y);
                        tmpSuatChieuBorder.setFillColor(sf::Color::Transparent);
                        tmpSuatChieuBorder.setOutlineColor(sf::Color::White);
                        tmpSuatChieuBorder.setOutlineThickness(2.0f);
                        suatChieuBorder.push_back(tmpSuatChieuBorder);
                    }
                    for (int i = 0; i < buttonCount; ++i)
                    {
                        for (int j = 0; j < 2; ++j)
                        {
                            if (buttons[i * 2 + j].getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                            {
                                quantities[i][sizeQuantities[i]] += (j == 0) ? 1 : -1;
                            }
                        }
                        if (increaseButtons[i].getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                        {
                            if (sizeQuantities[i] < 2) {
                                for (int k = 0; k < 3; k++) {
                                    quantities[i][k] = 0;
                                }
                                sizeQuantities[i]++;
                            }

                        }
                        else if (decreaseButtons[i].getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                        {
                            if (sizeQuantities[i] > 0) {
                                sizeQuantities[i]--;
                                for (int k = 0; k < 3; k++) {
                                    quantities[i][k] = 0;
                                }
                            }
                        }
                    }
                    for (int i = 0; i < suatChieuBorder.size(); i++) {
                        if (suatChieuBorder[i].getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {

                            string tmp1 = "";
                            for (int n = 0; n < 2; n++) {
                                tmp1 += suatChieu[i].getString()[n];
                            }
                            string tmp2 = "";
                            for (int n = 3; n < 5; n++) {
                                tmp2 += suatChieu[i].getString()[n];
                            }
                            clickedSuatChieu2 = 1;

                            for (int j = 0; j < selectedPhim.getsosuatchieu(); j++) {
                                if (selectedNgay == (selectedPhim.getdanhsachsuatchieu()[j].getthoigianchieu().getngay() - rightNow.getngay()) && selectedPhim.getdanhsachsuatchieu()[j].getthoigianchieu().getgio() == stoi(tmp1) && selectedPhim.getdanhsachsuatchieu()[j].getthoigianchieu().getphut() == stoi(tmp2)) {
                                    selectedPhong = selectedPhim.getdanhsachsuatchieu()[j].getidphong();
                                    ngayChieu = selectedPhim.getdanhsachsuatchieu()[j].getthoigianchieu();
                                    selectedSuatChieu = j;

                                }
                            }
                            break;
                        }
                    }

                    if (clickedSuatChieu2) {
                        if (confirmButton.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                        {
                            for (int i = 0; i < 3; i++) {
                                for (int j = 0; j < 3; j++) {
                                    gioHangMenu[i * 3 + j] += quantities[i][j];
                                    quantities[i][j] = 0;
                                }
                            }
                        }
                        if (xacnhanButton.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                        {
                            countPage++;
                        }
                    }
                }
                if (event.type == sf::Event::MouseMoved) {
                    // Kiểm tra hover
                    for (int i = 0; i < numRectangles; ++i) {
                        if (thuNgayBorder[i].getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y))) {
                            thuNgayBorder[i].setOutlineColor(sf::Color::Black);
                        }
                        else {
                            thuNgayBorder[i].setOutlineColor(sf::Color::White);
                        }
                    }

                    if (clickedSuatChieu) {
                        for (int i = 0; i < suatChieuBorder.size(); i++) {
                            if (suatChieuBorder[i].getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y))) {
                                suatChieuBorder[i].setOutlineColor(sf::Color::Black);
                            }
                            else {
                                suatChieuBorder[i].setOutlineColor(sf::Color::White);
                            }
                        }

                    }

                }


            }
            else if (countPage == 4) {
                daVeQR = 0;
                datinhtienthungay = 0;
                phong selectedPhong2 = admin1.getphong(selectedPhong);
                contentSprite[3].setString("Phong Chieu " + to_string(selectedPhong[1] - 48));
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (selectedPhong2.getghengoi(i, j)) {
                            gheNgoi[i][j].setFillColor(sf::Color::Red);
                        }
                    }
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // Lấy vị trí của chuột khi nhấn
                        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                        // Kiểm tra xem vị trí chuột có nằm trong phạm vi của sprite không
                        for (int i = 0; i < rows; ++i) {
                            for (int j = 0; j < cols; j++)
                            {
                                if (gheNgoi[i][j].getGlobalBounds().contains(sf::Vector2f(mousePosition))) {

                                    gheTrongFull = 0;
                                    for (int l = 0; l < 11; l++) {
                                        if (datGheNgoi[l]) {
                                            gheTrongFull = 1;
                                        }
                                    }
                                    if (!gheTrongFull) {
                                        hangDatGhe = 18;
                                    }
                                    if (!selectedPhong2.getghengoi(i, j)) {
                                        if ((!datGheNgoi[j] && hangDatGhe == 18) || (!datGheNgoi[j] && (hangDatGhe == i))) {
                                            hangDatGhe = i;
                                            if (i == 0 || i == 1 || i == 5 || i == 6) {

                                                gheNgoi[i][j].setFillColor(sf::Color::Green);
                                                datGheNgoi[j] = 1;
                                                if (gheNgoiDaDat == "") {
                                                    gheNgoiDaDat += i + 48 + 17;
                                                    gheNgoiDaDat += to_string(j);
                                                }
                                                else {
                                                    gheNgoiDaDat += ", ";
                                                    gheNgoiDaDat += i + 48 + 17;
                                                    gheNgoiDaDat += to_string(j);
                                                }

                                            }
                                            else if (i == 2 || i == 3) {

                                                gheNgoi[i][j].setFillColor(sf::Color::Blue);
                                                datGheNgoi[j] = 1;
                                                if (gheNgoiDaDat == "") {
                                                    gheNgoiDaDat += i + 48 + 17;
                                                    gheNgoiDaDat += to_string(j);
                                                }
                                                else {
                                                    gheNgoiDaDat += ", ";
                                                    gheNgoiDaDat += i + 48 + 17;
                                                    gheNgoiDaDat += to_string(j);
                                                }
                                            }
                                            else if (i == 4 && j != 10) {

                                                if (j % 2 == 1) {
                                                    datGheNgoi[j] = 1;
                                                    datGheNgoi[j - 1] = 1;
                                                    gheNgoi[i][j].setFillColor(sf::Color::Magenta);
                                                    gheNgoi[i][j - 1].setFillColor(sf::Color::Magenta);
                                                    if (gheNgoiDaDat == "") {
                                                        gheNgoiDaDat += i + 48 + 17;
                                                        gheNgoiDaDat += to_string(j);
                                                        gheNgoiDaDat += ', ';
                                                        gheNgoiDaDat += i + 48 + 17;
                                                        gheNgoiDaDat += to_string(j - 1);
                                                    }
                                                    else {
                                                        gheNgoiDaDat += ", ";
                                                        gheNgoiDaDat += i + 48 + 17;
                                                        gheNgoiDaDat += to_string(j);
                                                        gheNgoiDaDat += ', ';
                                                        gheNgoiDaDat += i + 48 + 17;
                                                        gheNgoiDaDat += to_string(j - 1);
                                                    }


                                                }
                                                else {
                                                    datGheNgoi[j] = 1;
                                                    datGheNgoi[j + 1] = 1;
                                                    gheNgoi[i][j].setFillColor(sf::Color::Magenta);
                                                    gheNgoi[i][j + 1].setFillColor(sf::Color::Magenta);
                                                    if (gheNgoiDaDat == "") {
                                                        gheNgoiDaDat += i + 48 + 17;
                                                        gheNgoiDaDat += to_string(j);
                                                        gheNgoiDaDat += ', ';
                                                        gheNgoiDaDat += i + 48 + 17;
                                                        gheNgoiDaDat += to_string(j + 1);
                                                    }
                                                    else {
                                                        gheNgoiDaDat += ", ";
                                                        gheNgoiDaDat += i + 48 + 17;
                                                        gheNgoiDaDat += to_string(j);
                                                        gheNgoiDaDat += ', ';
                                                        gheNgoiDaDat += i + 48 + 17;
                                                        gheNgoiDaDat += to_string(j + 1);
                                                    }


                                                }


                                            }
                                            gheTrongFull = 1;


                                        }
                                        else if (datGheNgoi[j] && hangDatGhe == 18 || datGheNgoi[j] && (hangDatGhe == i)) {
                                            if (i == 4 && j != 10) {

                                                int Tong = 0;
                                                for (int m = 0; m < 11; m++) {
                                                    Tong += datGheNgoi[m];
                                                }
                                                if (Tong == 2) {
                                                    gheNgoiDaDat = "";
                                                }
                                                else {
                                                    gheNgoiDaDat = gheNgoiDaDat.substr(0, gheNgoiDaDat.length() - 7);

                                                }


                                                if (j % 2 == 1) {
                                                    gheNgoi[i][j].setFillColor(sf::Color::White);
                                                    datGheNgoi[j - 1] = 0;
                                                    gheNgoi[i][j - 1].setFillColor(sf::Color::White);
                                                    datGheNgoi[j] = 0;


                                                }
                                                else {
                                                    gheNgoi[i][j].setFillColor(sf::Color::White);
                                                    datGheNgoi[j + 1] = 0;
                                                    gheNgoi[i][j + 1].setFillColor(sf::Color::White);
                                                    datGheNgoi[j] = 0;

                                                }

                                            }
                                            else {

                                                int Tong = 0;
                                                for (int m = 0; m < 11; m++) {
                                                    Tong += datGheNgoi[m];
                                                }
                                                if (Tong == 1) {
                                                    gheNgoiDaDat = "";
                                                }
                                                else {
                                                    gheNgoiDaDat = gheNgoiDaDat.substr(0, gheNgoiDaDat.length() - 4);

                                                }

                                                gheNgoi[i][j].setFillColor(sf::Color::White);
                                                datGheNgoi[j] = 0;
                                            }
                                            for (int m = 0; m < 11; m++) {
                                                if (datGheNgoi[m]) {
                                                    gheTrongFull = 0;
                                                }
                                            }


                                        }
                                    }
                                }
                            }

                        }
                        if (xacNhanDatVeButton.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {

                            admin1.xacnhandatve((selectedPhong[0] - 48), (selectedPhong[1] - 48) - 1, (selectedPhong[2] - 48) - 1, hangDatGhe, datGheNgoi, "DanhSachPhong.txt");
                            giaVe = 0;
                            for (int n = 0; n < 3; n++) {
                                int FirstGia;

                                for (int m = 0; m < 3; m++)
                                {

                                    if (gioHangMenu[n * 3 + m]) {
                                        if (n == 0) {
                                            FirstGia = 15;
                                        }
                                        else if (n == 1) {
                                            FirstGia = 20;
                                        }
                                        else {
                                            FirstGia = 40;
                                        }
                                        FirstGia += m * 5;
                                        giaVe += FirstGia * gioHangMenu[n * 3 + m];
                                    }
                                }
                            }
                            for (int j = 0; j < 11; j++) {

                                if (datGheNgoi[j]) {
                                    if (hangDatGhe == 0 || hangDatGhe == 1 || hangDatGhe == 5 || hangDatGhe == 6) {
                                        giaVe += 60;
                                        loaiGhe = "NOR";
                                    }
                                    else if (hangDatGhe == 2 || hangDatGhe == 3) {
                                        giaVe += 100;
                                        loaiGhe = "VIP";
                                    }
                                    else {
                                        if (j == 10) {
                                            giaVe += 60;
                                            loaiGhe = "NOR";
                                        }
                                        else {
                                            giaVe += 80;
                                            loaiGhe = "COUP";
                                        }
                                    }

                                }
                            }

                            countPage++;

                        }
                    }


                }

                else  if (event.type == sf::Event::MouseMoved) {
                    // Kiểm tra hover
                    daLoadGheNgoi = 0;
                    if (!daLoadGheNgoi) {
                        for (int j = 0; j < 7; j++) {
                            for (int k = 0; k < 11; k++) {

                                if (selectedPhong2.getghengoi(j, k)) {
                                    gheNgoi[j][k].setFillColor(sf::Color::Red);
                                }
                                else {
                                    gheNgoi[j][k].setFillColor(sf::Color::White);

                                }


                            }
                        }

                        if (hangDatGhe == 0 || hangDatGhe == 1 || hangDatGhe == 5 || hangDatGhe == 6) {
                            for (int j = 0; j < 11; j++) {
                                if (datGheNgoi[j]) {
                                    gheNgoi[hangDatGhe][j].setFillColor(sf::Color::Green);
                                }
                            }
                        }
                        else if (hangDatGhe == 4) {
                            for (int j = 0; j < 11; j++) {
                                if (datGheNgoi[j]) {
                                    gheNgoi[hangDatGhe][j].setFillColor(sf::Color::Magenta);
                                }
                            }
                        }
                        else if (hangDatGhe == 2 || hangDatGhe == 3) {
                            for (int j = 0; j < 11; j++) {
                                if (datGheNgoi[j]) {
                                    gheNgoi[hangDatGhe][j].setFillColor(sf::Color::Blue);
                                }
                            }
                        }

                        daLoadGheNgoi = 1;
                    }

                    for (int i = 0; i < 3; ++i) {
                        if (loaiGheNgoi[i].getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y))) {
                            daLoadGheNgoi = 1;
                            if (i == 0) {
                                for (int k = 0; k < 11; k++) {
                                    gheNgoi[0][k].setFillColor(sf::Color::Green);
                                    gheNgoi[1][k].setFillColor(sf::Color::Green);
                                    gheNgoi[5][k].setFillColor(sf::Color::Green);
                                    gheNgoi[6][k].setFillColor(sf::Color::Green);
                                }

                            }
                            else if (i == 1) {
                                for (int k = 0; k < 11; k++) {
                                    gheNgoi[2][k].setFillColor(sf::Color::Blue);
                                    gheNgoi[3][k].setFillColor(sf::Color::Blue);

                                }
                            }
                            else if (i == 2) {
                                for (int k = 0; k < 11; k++) {
                                    gheNgoi[4][k].setFillColor(sf::Color::Magenta);

                                }
                            }
                        }



                    }


                }
                if (!texturePhimPage6.loadFromFile(selectedMovie + ".jpg")) {
                    if (!texturePhimPage6.loadFromFile(selectedMovie + ".png")) {
                        std::cerr << "Error loading movieSpriteTexture texture!" << std::endl;
                        return -1;
                    }

                }
                spritePhimPage6.setTexture(texturePhimPage6);
                spritePhimPage6.setPosition(100, movieSprite.getPosition().y);
                spritePhimPage6.setScale(0.18, 0.18);
                contentSprite[0].setString(selectedPhim.gettenphim());
                int tmpShit = 0;
                string tmpBapNuoc = "";
                for (int i = 0; i < 3; i++) {
                    tmpShit = 0;
                    for (int j = 0; j < 3; j++) {
                        tmpShit += gioHangMenu[i * 3 + j];
                    }
                    if (i == 0) {
                        tmpBapNuoc += to_string(tmpShit) + " Coca\n";

                    }
                    else if (i == 1) {
                        tmpBapNuoc += to_string(tmpShit) + " Coffe\n";

                    }
                    else {
                        tmpBapNuoc += to_string(tmpShit) + " PopCorn";

                    }
                }

                contentSprite[5].setString(tmpBapNuoc);

                contentSprite[6].setString("Ghe Ngoi : " + gheNgoiDaDat);


                if (selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getgio() < 10 || selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getphut() < 10) {
                    if (selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getgio() < 10) {
                        contentSprite[1].setString("Suat Chieu 0" + to_string(selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getgio()) + ":" + to_string(selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getphut()));

                    }
                    else if (selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getphut() < 10) {
                        contentSprite[1].setString("Suat Chieu " + to_string(selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getgio()) + ":0" + to_string(selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getphut()));

                    }
                }
                else {
                    contentSprite[1].setString("Suat Chieu " + to_string(selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getgio()) + ":" + to_string(selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getphut()));

                }
                if (selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getngay() < 10 || selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getthang() < 10) {
                    if (selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getngay() < 10) {
                        contentSprite[2].setString(to_string(selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getngay()) + "/" + to_string(selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getthang()) + "/" + to_string(selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getnam()));

                    }
                    else if (selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getthang() < 10) {
                        contentSprite[2].setString(to_string(selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getngay()) + "/0" + to_string(selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getthang()) + "/" + to_string(selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getnam()));

                    }
                }
                else {
                    contentSprite[2].setString(to_string(selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getngay()) + "/" + to_string(selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getthang()) + "/" + to_string(selectedPhim.getdanhsachsuatchieu()[selectedSuatChieu].getthoigianchieu().getnam()));

                }



                giaVe = 0;
                for (int n = 0; n < 3; n++) {
                    int FirstGia;

                    for (int m = 0; m < 3; m++)
                    {

                        if (gioHangMenu[n * 3 + m]) {
                            if (n == 0) {
                                FirstGia = 15;
                            }
                            else if (n == 1) {
                                FirstGia = 20;
                            }
                            else {
                                FirstGia = 40;
                            }
                            FirstGia += m * 5;
                            giaVe += FirstGia * gioHangMenu[n * 3 + m];
                        }
                    }
                }
                for (int j = 0; j < 11; j++) {

                    if (datGheNgoi[j]) {
                        if (hangDatGhe == 0 || hangDatGhe == 1 || hangDatGhe == 5 || hangDatGhe == 6) {
                            giaVe += 60;
                            loaiGhe = "NOR";
                        }
                        else if (hangDatGhe == 2 || hangDatGhe == 3) {
                            giaVe += 100;
                            loaiGhe = "VIP";
                        }
                        else {
                            if (j == 10) {
                                giaVe += 60;
                                loaiGhe = "NOR";
                            }
                            else {
                                giaVe += 80;
                                loaiGhe = "COUP";
                            }
                        }

                    }
                }

                contentSprite[4].setString("Tong : " + to_string(giaVe) + ".000 vnd");

            }
            else if (countPage == 5) {

                ve tmpVe(giaVe, rightNow, bapNuoc, selectedPhim.gettenphim(), ngayChieu, gheNgoiDaDat, loaiGhe);
                contentVe[0].setString(selectedPhim.gettenphim());
                contentVe[1].setString("Ghe Ngoi " + gheNgoiDaDat);
                contentVe[2].setString("Ghe " + loaiGhe);
                int tmpShit = 0;
                string tmpBapNuoc = "";
                for (int i = 0; i < 3; i++) {
                    tmpShit = 0;
                    for (int j = 0; j < 3; j++) {
                        tmpShit += gioHangMenu[i * 3 + j];
                    }
                    if (i == 0) {
                        tmpBapNuoc += to_string(tmpShit) + " Coca\n";

                    }
                    else if (i == 1) {
                        tmpBapNuoc += to_string(tmpShit) + " Coffe\n";

                    }
                    else {
                        tmpBapNuoc += to_string(tmpShit) + " PopCorn";

                    }
                }

                contentVe[3].setString(tmpBapNuoc);
                contentVe[4].setString("Ngay Chieu " + to_string(ngayChieu.getngay()) + "/" + to_string(ngayChieu.getthang()) + "/" + to_string(ngayChieu.getnam()));
                contentVe[5].setString("Ngay Dat Ve " + to_string(rightNow.getngay()) + "/" + to_string(rightNow.getthang()) + "/" + to_string(rightNow.getnam()));
                contentVe[6].setString(to_string(giaVe) + ".000 vnd");

                if (!datinhtienthungay) {
                    if (ngayChieu.getthungay() == 0 || ngayChieu.getthungay() == 6) {
                        for (int j = 0; j < 11; j++) {
                            if (datGheNgoi[j]) {
                                giaVe += 15;
                            }
                        }

                    }
                    datinhtienthungay = 1;
                }

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        bapNuoc += to_string(gioHangMenu[i * 3 + j]);
                    }
                }
                if (!daThemVe) {
                    admin1.themve(giaVe, rightNow, bapNuoc, selectedPhim.gettenphim(), ngayChieu, gheNgoiDaDat, loaiGhe);
                    daThemVe = 1;
                }
                if (!daVeQR) {
                    arrayK = 0;
                    arrayO = 0;

                    string tmp = tmpVe.getid() + "RAPCGVDANANGPBL2202318012004PHAMNHATBANGHUYNHHUUHOANG";



                    for (int i = 0; i < rows1; ++i) {
                        for (int j = 0; j < cols1; ++j) {
                            if (arrayO >= tmp.size()) {
                                arrayO = 0;
                                arrayK++;
                            }
                            if (tmp[arrayK * cols1 + arrayO] > 100) {
                                array2D[i][j] = tmp[arrayK * cols1 + arrayO] - 30;
                            }
                            else {
                                array2D[i][j] = tmp[arrayK * cols1 + arrayO];
                            }

                            arrayO++;
                        }

                    }
                    daVeQR = 1;
                }
            }
            window.clear(sf::Color(253, 252, 240));
            if (countPage == 1) {
                sf::Vector2f startPoint(phimdangchieu.getPosition().x, phimdangchieu.getPosition().y + 65);

                line.setPosition(startPoint);
                for (int i = 0; i < soPhim; i++) {
                    window.draw(borderPosterPhim[i]);
                    window.draw(posterPhim[i]);
                    window.draw(tenphim[i]);
                    window.draw(thongtinphim1[i].second);
                    window.draw(thongtinphim2[i]);
                    window.draw(thongtinphim3[i]);

                }
                window.draw(line);
                window.draw(phimdangchieu);
                window.draw(searchBar);
                window.draw(searchBoxText);
                if (isHovered) {
                    window.setMouseCursor(handPointer);
                }
                else {
                    window.setMouseCursor(arrowPointer);
                }

            }
            else if (countPage == 2) {
                window.draw(coTheBanCungThich);
                for (int i = 0; i < countTheLoai.size(); i++) {

                    window.draw(borderPosterPhim[countTheLoai[i]]);
                    window.draw(posterPhim[countTheLoai[i]]);
                    window.draw(tenphim[countTheLoai[i]]);
                    window.draw(thongtinphim1[countTheLoai[i]].second);
                    window.draw(thongtinphim2[countTheLoai[i]]);
                    window.draw(thongtinphim3[countTheLoai[i]]);
                }
                window.draw(thongtinphim1Tmp);
                window.draw(CGV);
                window.draw(noiDungPhim);
                sf::Vector2f startPoint(noiDungPhim.getPosition().x, noiDungPhim.getPosition().y + 65);

                line.setPosition(startPoint);
                window.draw(line);

                window.draw(borderPosterPhim[selectedPhimNumber]);
                window.draw(posterPhim[selectedPhimNumber]);
                window.draw(tenphim[selectedPhimNumber]);
                window.draw(thongtinphim2[selectedPhimNumber]);
                window.draw(thongtinphim3[selectedPhimNumber]);
                for (int k = 0; k < 2; k++) {
                    window.draw(contentText[k]);
                }
                window.draw(orderButton);
            }
            else if (countPage == 3) {
                for (int i = 0; i < buttonCount; ++i)
                {
                    quantityTexts[i].setString(std::to_string(quantities[i][sizeQuantities[i]]));
                }
                for (int i = 0; i < 10; i++) {
                    window.draw(thuNgayBorder[i]);
                    window.draw(thuNgay[i]);
                    window.draw(ngayThang[i]);
                }
                if (clickedSuatChieu) {
                    for (int i = 0; i < suatChieu.size(); i++) {
                        window.draw(suatChieuBorder[i]);
                        window.draw(suatChieu[i]);
                    }
                }
                if (clickedSuatChieu2) {
                    window.draw(MENU);
                    window.draw(menuQuan);
                    for (int i = 0; i < buttonCount; ++i)
                    {
                        if (sizeQuantities[i] == 0) {
                            sizeText[i].setString("Size S");
                        }
                        else if (sizeQuantities[i] == 1) {
                            sizeText[i].setString("Size M");
                        }
                        else if (sizeQuantities[i] == 2) {
                            sizeText[i].setString("Size L");
                        }
                    }

                    for (int i = 0; i < buttonCount; ++i)
                    {
                        window.draw(increaseButtons[i]);
                        window.draw(decreaseButtons[i]);
                        window.draw(sizeText[i]);
                        window.draw(increaseTexts[i]); // Draw increaseText
                        window.draw(decreaseTexts[i]); // Draw decreaseText
                    }
                    window.draw(coCaCoLa[sizeQuantities[0]]);
                    window.draw(pepSi[sizeQuantities[1]]);
                    window.draw(popCorn[sizeQuantities[2]]);
                    window.draw(confirmButton);
                    window.draw(xacnhanButton);
                    for (int i = 0; i < buttonCount; ++i)
                    {
                        for (int j = 0; j < 2; ++j)
                        {
                            window.draw(buttons[i * 2 + j]);
                            window.draw(buttonTexts[i * 2 + j]);
                        }
                        window.draw(quantityTexts[i]);
                    }
                }


            }
            else if (countPage == 4) {
                window.draw(movieSprite);
                for (int i = 0; i < 3; i++) {
                    window.draw(loaiGheNgoi[i]);
                    window.draw(textLoaiGhe[i]);

                }
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (i == 4 && j == 10) {

                        }
                        else {
                            window.draw(gheNgoi[i][j]);
                            window.draw(textGheNgoi[i][j]);
                        }
                    }
                }
                window.draw(xacNhanDatVeButton);
                window.draw(spritePhimPage6);
                for (int i = 0; i < 7; i++) {
                    window.draw(contentSprite[i]);
                }
            }
            else if (countPage == 5) {
                window.draw(khungVe);

                drawQRCode(window, array2D);
                for (int i = 0; i < 7; i++) {
                    window.draw(contentVe[i]);
                }


            }
            window.draw(backButton);
            window.display();
        }
    }
    return 0;
}

