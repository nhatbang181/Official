

//
//#include <sfml/graphics.hpp>
//#include <iostream>
//#include <vector>
//#include <iomanip>
//#include <sstream>
//#include <chrono>
//#include <ctime>
//#include<sstream>
////#include <unistd.h>
//using namespace std;
//
//// lớp đại diện cho một trang
////class page
////{
////public:
////	void draw(sf::renderwindow& window)
////	{
////
////	}
////};
////
//bool ismouseover(sf::rectangleshape& button, sf::event event)
//{
//	return button.getglobalbounds().contains(event.mousebutton.x, event.mousebutton.y);
//}
//// 
//// bool ismouseover(sf::rectangleshape& rect, sf::renderwindow& window)
////{
////    sf::floatrect bounds = rect.getglobalbounds();
////    sf::vector2i mouseposition = sf::mouse::getposition(window);
////    return bounds.contains(static_cast<float>(mouseposition.x), static_cast<float>(mouseposition.y));
////}
////
////bool ismouseover(sf::text& option, sf::renderwindow& window)
////{
////    sf::floatrect bounds = option.getglobalbounds();
////    sf::vector2i mouseposition = sf::mouse::getposition(window);
////    return bounds.contains(static_cast<float>(mouseposition.x), static_cast<float>(mouseposition.y));
////}
////
////int createadminwindow() {
////	sf::renderwindow window(sf::videomode(1280, 720), "admin");
////
////	// tải ảnh từ file trên hệ thống
////	sf::texture texture;
////	if (!texture.loadfromfile("image.jfif"))
////		return exit_failure;
////
////	// tạo sprite sử dụng texture đã tải
////	sf::sprite sprite(texture);
////
////	// lấy kích thước của cửa sổ
////	sf::vector2u windowsize = window.getsize();
////
////	// tính toán tỷ lệ giữa kích thước ảnh và kích thước cửa sổ
////	float scalex = static_cast<float>(windowsize.x) / texture.getsize().x;
////	float scaley = static_cast<float>(windowsize.y) / texture.getsize().y;
////
////	// đặt tỷ lệ kích thước cho sprite
////	sprite.setscale(scalex, scaley);
////
////	// đặt vị trí của sprite
////	sprite.setposition(0, 0);
////
////	// vòng lặp chính
////	while (window.isopen())
////	{
////		// xử lý các sự kiện
////		sf::event event;
////		while (window.pollevent(event))
////		{
////			if (event.type == sf::event::closed)
////				window.close();
////		}
////
////		// xóa cửa sổ
////		window.clear();
////
////		// vẽ sprite lên cửa sổ
////		window.draw(sprite);
////
////		// hiển thị cửa sổ
////		window.display();
////	}
////}
////
////int createloginadminwindow() {
////
////	sf::renderwindow window(sf::videomode(800, 600), "admin");
////	
////	bool login = true;
////	bool homepageadmin = false;
////
////	// tạo các thành phần giao diện
////	sf::font font;
////	if (!font.loadfromfile("shortbaby-mg2w.ttf"))
////	{
////		std::cout << "failed to load font!" << std::endl;
////		return -1;
////	}
////
////	//login////////////////////////////////////////////////////////
////	sf::rectangleshape button1(sf::vector2f(500, 50));
////	button1.setfillcolor(sf::color::white);
////	button1.setposition(100, 100);
////
////	sf::text inputtext1;
////	inputtext1.setfont(font);
////	inputtext1.setcharactersize(24);
////	inputtext1.setfillcolor(sf::color::black);
////	//inputtext1.setposition(button1.getposition().x + button1.getsize().x / 2 - inputtext1.getglobalbounds().width / 2,
////	//    button1.getposition().y + button1.getsize().y / 2 - inputtext1.getglobalbounds().height / 2);
////	inputtext1.setposition(100, 107);
////
////	/*sf::text inputtext1;
////	inputtext1.setfont(font);
////	inputtext1.setcharactersize(24);
////	inputtext1.setposition(100, 100);
////	inputtext1.setfillcolor(sf::color::white);*/
////
////	sf::rectangleshape button2(sf::vector2f(500, 50));
////	button2.setfillcolor(sf::color::white);
////	button2.setposition(100, 200);
////
////	sf::text inputtext2;
////	inputtext2.setfont(font);
////	inputtext2.setcharactersize(24);
////	inputtext2.setfillcolor(sf::color::black);
////	//inputtext2.setposition(button2.getposition().x + button2.getsize().x / 2 - inputtext2.getglobalbounds().width / 2,
////	//    button2.getposition().y + button2.getsize().y / 2 - inputtext2.getglobalbounds().height / 2);
////	inputtext2.setposition(100, 207);
////
////	//sf::text inputtext2;
////	//inputtext2.setfont(font);
////	//inputtext2.setcharactersize(24);
////	//inputtext2.setposition(100, 200);
////	//inputtext2.setfillcolor(sf::color::white);
////
////	sf::rectangleshape loginbutton(sf::vector2f(100, 50));
////	loginbutton.setfillcolor(sf::color::white);
////	loginbutton.setposition(250, 300);
////	loginbutton.setfillcolor(sf::color(238, 100, 87));
////
////	sf::text loginbuttontext;
////	loginbuttontext.setfont(font);
////	loginbuttontext.setstring("login");
////	loginbuttontext.setcharactersize(24);
////	loginbuttontext.setposition(250, 300);
////	loginbuttontext.setfillcolor(sf::color::black);
////
////	bool isinput1active = false;
////	bool isinput2active = false;
////	//login////////////////////////////////////////////////////////
////
////
////	while (window.isopen())
////	{
////		sf::event event;
////		while (window.pollevent(event))
////		{
////			if (event.type == sf::event::closed)
////			{
////				window.close();
////			}
////			else if (event.type == sf::event::mousebuttonpressed && event.mousebutton.button == sf::mouse::left)
////			{
////				if (loginbutton.getglobalbounds().contains(event.mousebutton.x, event.mousebutton.y))
////				{
////					std::string currenttext1 = inputtext1.getstring();
////					std::string currenttext2 = inputtext2.getstring();
////					if (currenttext1 == "admin" && currenttext2 == "password") {
////						/*createadminwindow();*/
////						login = false;
////						homepageadmin = true;
////					}
////				}
////				if (ismouseover(button1, event))
////				{
////					button1.setfillcolor(sf::color::yellow);
////					isinput1active = true;
////					isinput2active = false;
////					button2.setfillcolor(sf::color::white);
////				}
////				else if (ismouseover(button2, event))
////				{
////					button2.setfillcolor(sf::color::yellow);
////					isinput1active = false;
////					isinput2active = true;
////					button1.setfillcolor(sf::color::white);
////				}
////				else {
////					button1.setfillcolor(sf::color::white);
////					button2.setfillcolor(sf::color::white);
////				}
////			}
////			else if (event.type == sf::event::textentered)
////			{
////				if (isinput1active)
////				{
////					if (event.text.unicode < 128)
////					{
////						if (event.text.unicode == '\b' && !inputtext1.getstring().isempty())
////						{
////							std::string currenttext = inputtext1.getstring();
////							currenttext.pop_back();
////							inputtext1.setstring(currenttext);
////						}
////						else
////						{
////							inputtext1.setstring(inputtext1.getstring() + static_cast<char>(event.text.unicode));
////						}
////					}
////				}
////				else if (isinput2active)
////				{
////					if (event.text.unicode < 128)
////					{
////						if (event.text.unicode == '\b' && !inputtext2.getstring().isempty())
////						{
////							std::string currenttext = inputtext2.getstring();
////							currenttext.pop_back();
////							inputtext2.setstring(currenttext);
////						}
////						else
////						{
////							inputtext2.setstring(inputtext2.getstring() + static_cast<char>(event.text.unicode));
////						}
////					}
////				}
////			}
////		}
////
////		window.clear();
////		
////		//login
////		if (login) {
////			window.draw(button1);
////			window.draw(inputtext1);
////			window.draw(button2);
////			window.draw(inputtext2);
////			window.draw(loginbutton);
////		}
////		//login
////
////		window.display();
////	}
////}
////
////int createdashboardwindow() {
////	sf::renderwindow window(sf::videomode(1280, 720), "home");
////
////	// tải ảnh từ file trên hệ thống
////	sf::texture texture;
////	if (!texture.loadfromfile("image.jfif"))
////		return exit_failure;
////
////	// tạo sprite sử dụng texture đã tải
////	sf::sprite sprite(texture);
////
////	// lấy kích thước của cửa sổ
////	sf::vector2u windowsize = window.getsize();
////
////	// tính toán tỷ lệ giữa kích thước ảnh và kích thước cửa sổ
////	float scalex = static_cast<float>(windowsize.x) / texture.getsize().x;
////	float scaley = static_cast<float>(windowsize.y) / texture.getsize().y;
////
////	// đặt tỷ lệ kích thước cho sprite
////	sprite.setscale(scalex, scaley);
////
////	// đặt vị trí của sprite
////	sprite.setposition(0, 0);
////
////	// vòng lặp chính
////	while (window.isopen())
////	{
////		// xử lý các sự kiện
////		sf::event event;
////		while (window.pollevent(event))
////		{
////			if (event.type == sf::event::closed)
////				window.close();
////		}
////
////		// xóa cửa sổ
////		window.clear();
////
////		// vẽ sprite lên cửa sổ
////		window.draw(sprite);
////
////		// hiển thị cửa sổ
////		window.display();
////	}
////
////}
////
////int main()
////{
////	// tạo cửa sổ kích thước 800x600 pixels
////	sf::renderwindow window(sf::videomode(1280, 720), "cinema");
////
////	//text clock
////	sf::font fontclock;
////	if (!fontclock.loadfromfile("wallpoet-regular.ttf"))
////		return exit_failure;
////
////	// tạo văn bản sử dụng font đã tải
////	sf::text textclock("", fontclock, 24);
////	textclock.setposition(0, 10);
////	//text clock
////
////	// tải ảnh từ file trên hệ thống
////	sf::texture texture;
////	if (!texture.loadfromfile("movie.jpg"))
////		return exit_failure;
////
////	// tạo sprite sử dụng texture đã tải
////	sf::sprite sprite(texture);
////
////	// lấy kích thước của cửa sổ
////	sf::vector2u windowsize = window.getsize();
////
////	// tính toán tỷ lệ giữa kích thước ảnh và kích thước cửa sổ
////	float scalex = static_cast<float>(windowsize.x) / texture.getsize().x;
////	float scaley = static_cast<float>(windowsize.y) / texture.getsize().y;
////
////	// đặt tỷ lệ kích thước cho sprite
////	sprite.setscale(scalex, scaley);
////
////	// đặt vị trí của sprite
////	sprite.setposition(0, 0);
////
////
////	// tạo nút để chuyển sang trang khác
////		//sf::rectangleshape button(sf::vector2f(200, 50));
////		////sf::circleshape button(50, 100);
////		//button.setfillcolor(sf::color(139, 216, 189));
////		//button.setposition(300, 250);
////
////	sf::circleshape button1(25);
////	button1.setfillcolor(sf::color(139, 216, 189)); // màu xám
////	button1.setoutlinethickness(5);
////	button1.setoutlinecolor(sf::color(150, 150, 150)); // màu xám nhạt
////	button1.setposition(1100, 10);
////
////	sf::circleshape button2(25);
////	button2.setfillcolor(sf::color(139, 216, 189)); // màu xám
////	button2.setoutlinethickness(5);
////	button2.setoutlinecolor(sf::color(150, 150, 150)); // màu xám nhạt
////	button2.setposition(1000, 10);
////
////	sf::texture texture1;
////	if (!texture1.loadfromfile("admin-icon-png-4.jpg"))
////	{
////		std::cout << "failed to load icon." << std::endl;
////		return -1;
////	}
////	sf::sprite iconsprite1(texture1);
////	iconsprite1.setscale(0.2f, 0.2f);
////	iconsprite1.setposition(1105, 12);
////
////	sf::texture texture2;
////	if (!texture2.loadfromfile("icon-home-removebg-preview.png"))
////	{
////		std::cout << "failed to load icon." << std::endl;
////		return -1;
////	}
////	sf::sprite iconsprite2(texture2);
////	iconsprite2.setscale(0.1f, 0.1f);
////	iconsprite2.setposition(994, 12);
////
////	/*sf::font font;
////	if (!font.loadfromfile("shortbaby-mg2w.ttf"))
////		return exit_failure;
////
////	sf::text text("click táo!", font, 24);
////	text.setfillcolor(sf::color::red);
////	text.setposition(button.getposition().x + button.getsize().x / 2 - text.getglobalbounds().width / 2,
////		button.getposition().y + button.getsize().y / 2 - text.getglobalbounds().height / 2);*/
////
////		// vòng lặp chính
////	while (window.isopen())
////	{
////		// xử lý các sự kiện
////		sf::event event;
////		while (window.pollevent(event))
////		{
////			if (event.type == sf::event::closed)
////				window.close();
////
////			if (event.type == sf::event::mousebuttonpressed && event.mousebutton.button == sf::mouse::left)
////			{
////				// kiểm tra xem người dùng đã ấn vào nút hay chưa
////				if (button1.getglobalbounds().contains(event.mousebutton.x, event.mousebutton.y))
////				{
////					createloginadminwindow();
////				}
////				if (button2.getglobalbounds().contains(event.mousebutton.x, event.mousebutton.y))
////				{
////					createdashboardwindow();
////				}
////			}
////		}
////
////		auto now = std::chrono::system_clock::now();
////		std::time_t now_time = std::chrono::system_clock::to_time_t(now);
////
////		// chuyển đổi std::time_t sang đối tượng std::tm
////		std::tm time_info;
////		localtime_s(&time_info, &now_time);
////
////		// chuyển đổi std::tm sang chuỗi có thể đọc được
////		char buf[100];
////		std::strftime(buf, sizeof(buf), "%y-%m-%d | %h:%m:%s", &time_info);
////
////		// cập nhật văn bản hiển thị trên đồng hồ
////		textclock.setstring(buf);
////
////		// xóa cửa sổ
////		window.clear();
////
////		// vẽ các đối tượng lên cửa sổ
////		window.draw(sprite);
////		window.draw(textclock);
////		window.draw(button1);
////		window.draw(button2);
////		window.draw(iconsprite1);
////		window.draw(iconsprite2);
////		//window.draw(text);
////
////		// hiển thị cửa sổ
////		window.display();
////	}
////
////	return 0;
////}
//
//
//
////#include <sfml/graphics.hpp>
////#include <iostream>
////#include <string>
////#include <vector>
////
//
//bool ismouseover(sf::rectangleshape& rect, sf::renderwindow& window)
//{
//	sf::floatrect bounds = rect.getglobalbounds();
//	sf::vector2i mouseposition = sf::mouse::getposition(window);
//	return bounds.contains(static_cast<float>(mouseposition.x), static_cast<float>(mouseposition.y));
//}
//
//bool ismouseover(sf::text& option, sf::renderwindow& window)
//{
//	sf::floatrect bounds = option.getglobalbounds();
//	sf::vector2i mouseposition = sf::mouse::getposition(window);
//	return bounds.contains(static_cast<float>(mouseposition.x), static_cast<float>(mouseposition.y));
//}
//
////int main()
////{
////    // tạo cửa sổ kích thước 800x600 pixels
////    sf::renderwindow window(sf::videomode(800, 600), "dropdown");
////
////    // tạo các thành phần giao diện
////    sf::font font;
////    if (!font.loadfromfile("shortbaby-mg2w.ttf"))
////    {
////        std::cout << "failed to load font!" << std::endl;
////        return -1;
////    }
////
////    sf::rectangleshape dropdownbox(sf::vector2f(200, 50));
////    dropdownbox.setfillcolor(sf::color::white);
////    dropdownbox.setoutlinethickness(2);
////    dropdownbox.setoutlinecolor(sf::color::black);
////    dropdownbox.setposition(100, 100);
////
////    sf::text dropdowntext("select an option", font, 24);
////    dropdowntext.setfillcolor(sf::color::black);
////    dropdowntext.setposition(110, 110);
////
////    std::vector< std::pair<sf::text, sf::rectangleshape> > options;
////    sf::rectangleshape option1box(sf::vector2f(200, 50));
////    option1box.setfillcolor(sf::color::white);
////    option1box.setoutlinethickness(2);
////    option1box.setoutlinecolor(sf::color::black);
////    option1box.setposition(100, 150);
////
////    sf::text option1("option 1", font, 24);
////    option1.setposition(110, 160);
////    option1.setfillcolor(sf::color::black);
////    options.push_back({ option1 , option1box });
////
////    sf::rectangleshape option2box(sf::vector2f(200, 50));
////    option2box.setfillcolor(sf::color::white);
////    option2box.setoutlinethickness(2);
////    option2box.setoutlinecolor(sf::color::black);
////    option2box.setposition(100, 200);
////
////    sf::text option2("option 2", font, 24);
////    option2.setposition(110, 210);
////    option2.setfillcolor(sf::color::black);
////    options.push_back({ option2 , option2box });
////
////    sf::rectangleshape option3box(sf::vector2f(200, 50));
////    option3box.setfillcolor(sf::color::white);
////    option3box.setoutlinethickness(2);
////    option3box.setoutlinecolor(sf::color::black);
////    option3box.setposition(100, 250);
////
////    sf::text option3("option 3", font, 24);
////    option3.setposition(110, 260);
////    option3.setfillcolor(sf::color::black);
////    options.push_back({ option3 , option3box });
////
////    bool isdropdownactive = false;
////
////    while (window.isopen())
////    {
////        sf::event event;
////        while (window.pollevent(event))
////        {
////            if (event.type == sf::event::closed)
////            {
////                window.close();
////            }
////            else if (event.type == sf::event::mousebuttonpressed)
////            {
////                if (ismouseover(dropdownbox, window))
////                {
////                    dropdownbox.setfillcolor(sf::color(111, 110, 111));
////                    isdropdownactive = !isdropdownactive;
////                }
////                else if (isdropdownactive)
////                {
////                    for (std::pair<sf::text, sf::rectangleshape> option : options)
////                    {
////                        if (ismouseover(option.second, window))
////                        {
////                            dropdowntext.setstring(option.first.getstring());
////                            dropdownbox.setfillcolor(sf::color::white);
////                            isdropdownactive = false;
////                            break;
////                        }
////                    }
////                }
////            }
////        }
////
////        window.clear(sf::color::white);
////
////        window.draw(dropdownbox);
////        window.draw(dropdowntext);
////
////        if (isdropdownactive)
////        {
////            for (const std::pair<sf::text, sf::rectangleshape> option : options)
////            {
////                window.draw(option.second);
////                window.draw(option.first);
////            }
////        }
////
////        window.display();
////    }
////
////    return 0;
////}
//
////<<<<<<< head
//int main()
//{
//	// tạo cửa sổ kích thước 800x600 pixels
//	sf::renderwindow window(sf::videomode(1195, 672), "drawing line");
//
//	sf::rectangleshape thickline(sf::vector2f(1195, 3));
//	thickline.setfillcolor(sf::color::red);
//	thickline.setposition(0, 100);
//
//
//	//////////////////////order//////////////////
//	sf::texture texture;
//	if (!texture.loadfromfile("order.jpg"))
//		return exit_failure;
//
//	// tạo sprite sử dụng texture đã tải
//	sf::sprite sprite(texture);
//	sf::vector2u windowsize = window.getsize();
//	float scalex = 1195.0 / texture.getsize().x;
//	float scaley = 572.0 / texture.getsize().y;
//	sprite.setscale(scalex, scaley);
//	sprite.setposition(0, 100);
//
//	std::pair<sf::rectangleshape, bool> box[3][12][6];
//	//vector< std::pair<sf::rectangleshape, bool>> box[12][6];
//
//	double x_0 = 157, y_0 = 277;
//	double delta_x = 74.5, delta_y = 64;
//
//	for (int k = 0; k < 3; k++) {
//		for (int i = 0; i < 12; i++) {
//			for (int j = 0; j < 6; j++) {
//				double x = x_0 + i * delta_x, y = y_0 + j * delta_y;
//				box[k][i][j].second = false;
//				box[k][i][j].first.setsize(sf::vector2f(59, 52));
//				box[k][i][j].first.setfillcolor(sf::color(238, 100, 87)); //100, 238, 87
//				box[k][i][j].first.setoutlinethickness(2);
//				box[k][i][j].first.setoutlinecolor(sf::color::black);
//				box[k][i][j].first.setposition(x, y);
//			}
//		}
//	}
//
//
//	//////////////////////order//////////////////
//
//	///////////////////////////////////
//
//	sf::font font;
//	if (!font.loadfromfile("shortbaby-mg2w.ttf"))
//	{
//		std::cout << "failed to load font!" << std::endl;
//		return -1;
//	}
//
//
//	//bool selectbutton[3]; memset(selectbutton, false, 3);
//	bool homepagebutton = true;
//	bool selectdropdownbutton = false;
//	bool selectandupdatebutton = false; int indexbutton = 0;
//	bool createbuttonactive = false;
//
//	sf::text homepagetext("homepage", font, 24);
//	homepagetext.setfillcolor(sf::color::black);
//	homepagetext.setposition(500, 500);
//
//	sf::circleshape button1(25);
//	button1.setfillcolor(sf::color(139, 216, 189)); // màu xám
//	button1.setoutlinethickness(5);
//	button1.setoutlinecolor(sf::color(150, 150, 150)); // màu xám nhạt
//	button1.setposition(100, 25);
//
//	sf::texture texture1;
//	if (!texture1.loadfromfile("icon-home-removebg-preview.png"))
//	{
//		std::cout << "failed to load icon." << std::endl;
//		return -1;
//	}
//	sf::sprite iconsprite1(texture1);
//	iconsprite1.setscale(0.1f, 0.1f);
//	iconsprite1.setposition(94, 28);
//	///////////////////////////////////
//
//	//////////////////dropdown/////////////////////////
//
//	sf::rectangleshape dropdownbox(sf::vector2f(125, 50));
//	dropdownbox.setfillcolor(sf::color::white);
//	dropdownbox.setoutlinethickness(2);
//	dropdownbox.setoutlinecolor(sf::color::black);
//	dropdownbox.setposition(300, 25);
//
//	sf::text dropdowntext("rap", font, 24);
//	dropdowntext.setfillcolor(sf::color::black);
//	dropdowntext.setposition(331, 35);
//
//	std::vector< std::pair<sf::text, sf::rectangleshape> > options;
//	sf::rectangleshape option1box(sf::vector2f(125, 50));
//	option1box.setfillcolor(sf::color::white);
//	option1box.setoutlinethickness(2);
//	option1box.setoutlinecolor(sf::color::black);
//	option1box.setposition(300, 75);
//
//	sf::text option1("rap 1", font, 24);
//	option1.setposition(330, 85);
//	option1.setfillcolor(sf::color::black);
//	options.push_back({ {option1} , option1box });
//
//	sf::rectangleshape option2box(sf::vector2f(125, 50));
//	option2box.setfillcolor(sf::color::white);
//	option2box.setoutlinethickness(2);
//	option2box.setoutlinecolor(sf::color::black);
//	option2box.setposition(300, 125);
//
//	sf::text option2("rap 2", font, 24);
//	option2.setposition(330, 135);
//	option2.setfillcolor(sf::color::black);
//	options.push_back({ {option2} , option2box });
//
//	sf::rectangleshape option3box(sf::vector2f(125, 50));
//	option3box.setfillcolor(sf::color::white);
//	option3box.setoutlinethickness(2);
//	option3box.setoutlinecolor(sf::color::black);
//	option3box.setposition(300, 175);
//
//	sf::text option3("rap 3", font, 24);
//	option3.setposition(330, 185);
//	option3.setfillcolor(sf::color::black);
//	options.push_back({ {option3} , option3box });
//
//	bool isdropdownactive = false;
//
//	sf::convexshape arrow(3);
//	arrow.setpoint(0, sf::vector2f(0, 0));
//	arrow.setpoint(1, sf::vector2f(15, 0));
//	arrow.setpoint(2, sf::vector2f(7.5, 7.5));
//	arrow.setfillcolor(sf::color::black);
//	arrow.setposition(400, 47);
//	bool isarrowdownup = true;
//
//	//////////////////dropdown/////////////////////////
//
//	/////////////////create////////////////////////////
//
//	sf::rectangleshape createbutton(sf::vector2f(125, 50));
//	createbutton.setfillcolor(sf::color::white);
//	createbutton.setoutlinethickness(2);
//	createbutton.setoutlinecolor(sf::color::black);
//	createbutton.setposition(600, 25);
//
//	sf::text createbuttontext("them moi", font, 24);
//	createbuttontext.setfillcolor(sf::color::black);
//	createbuttontext.setposition(614, 35);
//
//	/////////////////create////////////////////////////
//
//
//	while (window.isopen())
//	{
//		sf::event event;
//		while (window.pollevent(event))
//		{
//			if (event.type == sf::event::closed)
//			{
//				window.close();
//			}
//			if (event.type == sf::event::mousebuttonpressed && event.mousebutton.button == sf::mouse::left)
//			{
//				// kiểm tra xem người dùng đã ấn vào nút hay chưa
//				if (button1.getglobalbounds().contains(event.mousebutton.x, event.mousebutton.y))
//				{
//					homepagebutton = true;
//					selectdropdownbutton = false;
//					selectandupdatebutton = false;
//					indexbutton = 0;
//				}
//				if (ismouseover(dropdownbox, window))
//				{
//					dropdownbox.setfillcolor(sf::color(111, 110, 111));
//					isdropdownactive = !isdropdownactive;
//				}
//				else if (isdropdownactive)
//				{
//					for (int i = 0; i < 3; i++) {
//						{
//							//option.first.second = false;
//							if (ismouseover(options[i].second, window))
//							{
//								dropdowntext.setstring(options[i].first.getstring());
//								indexbutton = i + 1;
//								cout << i << indexbutton << endl;
//								dropdownbox.setfillcolor(sf::color::white);
//								isdropdownactive = false;
//								isarrowdownup = true;
//								homepagebutton = false;  selectdropdownbutton = true; selectandupdatebutton = true;
//								break;
//							}
//						}
//					}
//
//				}
//				if (selectandupdatebutton) {
//					if (indexbutton) {
//						for (int i = 0; i < 12; i++) {
//							for (int j = 0; j < 6; j++) {
//								if (box[indexbutton - 1][i][j].first.getglobalbounds().contains(event.mousebutton.x, event.mousebutton.y)) {
//									if (box[indexbutton - 1][i][j].second) {
//										box[indexbutton - 1][i][j].second = false;
//										box[indexbutton - 1][i][j].first.setfillcolor(sf::color(238, 100, 87)); //100, 238, 87
//
//									}
//									else {
//										box[indexbutton - 1][i][j].second = true;
//										box[indexbutton - 1][i][j].first.setfillcolor(sf::color(100, 238, 87)); //100, 238, 87
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//
//		}
//		window.clear(sf::color::white);
//
//		//if (homepageadmin) {
//		window.draw(button1);
//		window.draw(iconsprite1);
//		//}
//
//		if (homepagebutton) {
//			window.draw(homepagetext);
//		}
//
//		if (selectdropdownbutton) {
//			window.draw(sprite);
//		}
//
//		if (selectandupdatebutton) {
//			if (indexbutton) {
//				for (int i = 0; i < 12; i++) {
//					for (int j = 0; j < 6; j++) {
//						window.draw(box[indexbutton - 1][i][j].first);
//					}
//				}
//			}
//		}
//
//		window.draw(thickline);
//
//		window.draw(dropdownbox);
//		window.draw(dropdowntext);
//		if (isarrowdownup) {
//			arrow.setpoint(0, sf::vector2f(0, 0));
//			arrow.setpoint(1, sf::vector2f(15, 0));
//			arrow.setpoint(2, sf::vector2f(7.5, 7.5));
//			arrow.setfillcolor(sf::color::black);
//			window.draw(arrow);
//		}
//
//		if (isdropdownactive)
//		{
//			isarrowdownup = false;
//			arrow.setpoint(0, sf::vector2f(7.5, 0));
//			arrow.setpoint(1, sf::vector2f(0, 7.5));
//			arrow.setpoint(2, sf::vector2f(15, 7.5));
//			arrow.setfillcolor(sf::color::black);
//			window.draw(arrow);
//
//			for (const std::pair<sf::text, sf::rectangleshape> option : options)
//			{
//				window.draw(option.second);
//				window.draw(option.first);
//			}
//		}
//
//		window.draw(createbutton);
//		window.draw(createbuttontext);
//
//		window.display();
//	}
//}
////#include <sfml/graphics.hpp>
////#include <iostream>
////#include <string>
////#include <vector>
////
//// 
////=======
////>>>>>>> c8e790886348a2e06edb733d8e864adf6330eb28
////int main()
////{
////	// tạo cửa sổ kích thước 800x600 pixels
////	sf::renderwindow window(sf::videomode(1195, 672), "drawing line");
////
////	sf::rectangleshape thickline(sf::vector2f(1195, 3));
////	thickline.setfillcolor(sf::color::red);
////	thickline.setposition(0, 100);
////
////
////	//////////////////////order//////////////////
////	sf::texture texture;
////	if (!texture.loadfromfile("order.jpg"))
////		return exit_failure;
////
////	// tạo sprite sử dụng texture đã tải
////	sf::sprite sprite(texture);
////	sf::vector2u windowsize = window.getsize();
////	float scalex = 1195.0 / texture.getsize().x;
////	float scaley = 572.0 / texture.getsize().y;
////	sprite.setscale(scalex, scaley);
////	sprite.setposition(0, 100);
////
////	std::pair<sf::rectangleshape, bool> box[3][12][6];
// 
////	//vector< std::pair<sf::rectangleshape, bool>> box[12][6];
////
////	double x_0 = 157, y_0 = 277;
////	double delta_x = 74.5, delta_y = 64;
////
////	for (int k = 0; k < 3; k++) {
////		for (int i = 0; i < 12; i++) {
////			for (int j = 0; j < 6; j++) {
////				double x = x_0 + i * delta_x, y = y_0 + j * delta_y;
////				box[k][i][j].second = false;
////				box[k][i][j].first.setsize(sf::vector2f(59, 52));
////				box[k][i][j].first.setfillcolor(sf::color(238, 100, 87)); //100, 238, 87
////				box[k][i][j].first.setoutlinethickness(2);
////				box[k][i][j].first.setoutlinecolor(sf::color::black);
////				box[k][i][j].first.setposition(x, y);
////			}
////		}
////	}
////
////
////	//////////////////////order//////////////////
////
////	///////////////////////////////////
////
////	sf::font font;
////	if (!font.loadfromfile("shortbaby-mg2w.ttf"))
////	{
////		std::cout << "failed to load font!" << std::endl;
////		return -1;
////	}
////
////	//bool selectbutton[3]; memset(selectbutton, false, 3);
////	bool homepagebutton = true;
////	bool selectdropdownbutton = false;
////	bool selectandupdatebutton = false; int indexbutton = 0;
////	bool createbuttonactive = false;
////
////	sf::text homepagetext("homepage", font, 24);
////	homepagetext.setfillcolor(sf::color::black);
////	homepagetext.setposition(500, 500);
////
////	sf::circleshape button1(25);
////	button1.setfillcolor(sf::color(139, 216, 189)); // màu xám
////	button1.setoutlinethickness(5);
////	button1.setoutlinecolor(sf::color(150, 150, 150)); // màu xám nhạt
////	button1.setposition(100, 25);
////
////	sf::texture texture1;
////	if (!texture1.loadfromfile("icon-home-removebg-preview.png"))
////	{
////		std::cout << "failed to load icon." << std::endl;
////		return -1;
////	}
////	sf::sprite iconsprite1(texture1);
////	iconsprite1.setscale(0.1f, 0.1f);
////	iconsprite1.setposition(94, 28);
////	///////////////////////////////////
////
////	//////////////////dropdown/////////////////////////
////
////	sf::rectangleshape dropdownbox(sf::vector2f(125, 50));
////	dropdownbox.setfillcolor(sf::color::white);
////	dropdownbox.setoutlinethickness(2);
////	dropdownbox.setoutlinecolor(sf::color::black);
////	dropdownbox.setposition(300, 25);
////
////	sf::text dropdowntext("room", font, 24);
////	dropdowntext.setfillcolor(sf::color::black);
////	dropdowntext.setposition(319, 35);
////
////	std::vector< std::pair<sf::text, sf::rectangleshape> > options;
////	sf::rectangleshape option1box(sf::vector2f(125, 50));
////	option1box.setfillcolor(sf::color::white);
////	option1box.setoutlinethickness(2);
////	option1box.setoutlinecolor(sf::color::black);
////	option1box.setposition(300, 75);
////
////	sf::text option1("room 1", font, 24);
////	option1.setposition(325, 85);
////	option1.setfillcolor(sf::color::black);
////	options.push_back({ {option1} , option1box });
////
////	sf::rectangleshape option2box(sf::vector2f(125, 50));
////	option2box.setfillcolor(sf::color::white);
////	option2box.setoutlinethickness(2);
////	option2box.setoutlinecolor(sf::color::black);
////	option2box.setposition(300, 125);
////
////	sf::text option2("room 2", font, 24);
////	option2.setposition(325, 135);
////	option2.setfillcolor(sf::color::black);
////	options.push_back({ {option2} , option2box });
////
////	sf::rectangleshape option3box(sf::vector2f(125, 50));
////	option3box.setfillcolor(sf::color::white);
////	option3box.setoutlinethickness(2);
////	option3box.setoutlinecolor(sf::color::black);
////	option3box.setposition(300, 175);
////
////	sf::text option3("room 3", font, 24);
////	option3.setposition(325, 185);
////	option3.setfillcolor(sf::color::black);
////	options.push_back({ {option3} , option3box });
////
////	bool isdropdownactive = false;
////
////	sf::convexshape arrow(3);
////	arrow.setpoint(0, sf::vector2f(0, 0));
////	arrow.setpoint(1, sf::vector2f(15, 0));
////	arrow.setpoint(2, sf::vector2f(7.5, 7.5));
////	arrow.setfillcolor(sf::color::black);
////	arrow.setposition(402, 47);
////	bool isarrowdownup = true;
////
////	//////////////////dropdown/////////////////////////
////
////	/////////////////create////////////////////////////
////
////	sf::rectangleshape createbutton(sf::vector2f(125, 50));
////	createbutton.setfillcolor(sf::color::white);
////	createbutton.setoutlinethickness(2);
////	createbutton.setoutlinecolor(sf::color::black);
////	createbutton.setposition(600, 25);
////
////	sf::text createbuttontext("create", font, 24);
////	createbuttontext.setfillcolor(sf::color::black);
////	createbuttontext.setposition(614, 35);
////
////	/////////////////create////////////////////////////
////
////
////	while (window.isopen())
////	{
////		sf::event event;
////		while (window.pollevent(event))
////		{
////			if (event.type == sf::event::closed)
////			{
////				window.close();
////			}
////			if (event.type == sf::event::mousebuttonpressed && event.mousebutton.button == sf::mouse::left)
////			{
////				// kiểm tra xem người dùng đã ấn vào nút hay chưa
////				if (button1.getglobalbounds().contains(event.mousebutton.x, event.mousebutton.y))
////				{
////					homepagebutton = true;
////					selectdropdownbutton = false;
////					selectandupdatebutton = false;
////					indexbutton = 0;
////				}
////				if (ismouseover(dropdownbox, window))
////				{
////					dropdownbox.setfillcolor(sf::color(111, 110, 111));
////					isdropdownactive = !isdropdownactive;
////				}
////				else if (isdropdownactive)
////				{
////					for (int i = 0; i < 3; i++) {
////						{
////							//option.first.second = false;
////							if (ismouseover(options[i].second, window))
////							{
////								dropdowntext.setstring(options[i].first.getstring());
////								indexbutton = i + 1;
////								cout << i << indexbutton << endl;
////								dropdownbox.setfillcolor(sf::color::white);
////								isdropdownactive = false;
////								isarrowdownup = true;
////								homepagebutton = false;  selectdropdownbutton = true; selectandupdatebutton = true;
////								break;
////							}
////						}
////					}
////
////				}
////				if (selectandupdatebutton) {
////					if (indexbutton) {
////						for (int i = 0; i < 12; i++) {
////							for (int j = 0; j < 6; j++) {
////								if (box[indexbutton - 1][i][j].first.getglobalbounds().contains(event.mousebutton.x, event.mousebutton.y)) {
////									if (box[indexbutton - 1][i][j].second) {
////										box[indexbutton - 1][i][j].second = false;
////										box[indexbutton - 1][i][j].first.setfillcolor(sf::color(238, 100, 87)); //100, 238, 87
////
////									}
////									else {
////										box[indexbutton - 1][i][j].second = true;
////										box[indexbutton - 1][i][j].first.setfillcolor(sf::color(100, 238, 87)); //100, 238, 87
////									}
////								}
////							}
////						}
////					}
////				}
////			}
////
////		}
////		window.clear(sf::color::white);
////
////		//if (homepageadmin) {
////		window.draw(button1);
////		window.draw(iconsprite1);
////		//}
////
////		if (homepagebutton) {
////			window.draw(homepagetext);
////		}
////
////		if (selectdropdownbutton) {
////			window.draw(sprite);
////		}
////
////		if (selectandupdatebutton) {
////			if (indexbutton) {
////				for (int i = 0; i < 12; i++) {
////					for (int j = 0; j < 6; j++) {
////						window.draw(box[indexbutton - 1][i][j].first);
////					}
////				}
////			}
////		}
////
////		window.draw(thickline);
////
////		window.draw(dropdownbox);
////		window.draw(dropdowntext);
////		if (isarrowdownup) {
////			arrow.setpoint(0, sf::vector2f(0, 0));
////			arrow.setpoint(1, sf::vector2f(15, 0));
////			arrow.setpoint(2, sf::vector2f(7.5, 7.5));
////			arrow.setfillcolor(sf::color::black);
////			window.draw(arrow);
////		}
////
////		if (isdropdownactive)
////		{
////			isarrowdownup = false;
////			arrow.setpoint(0, sf::vector2f(7.5, 0));
////			arrow.setpoint(1, sf::vector2f(0, 7.5));
////			arrow.setpoint(2, sf::vector2f(15, 7.5));
////			arrow.setfillcolor(sf::color::black);
////			window.draw(arrow);
////
////			for (const std::pair<sf::text, sf::rectangleshape> option : options)
////			{
////				window.draw(option.second);
////				window.draw(option.first);
////			}
////		}
////
////		window.draw(createbutton);
////		window.draw(createbuttontext);
////
////		window.display();
////	}
////}
//
////int main()
////{
////	// tạo cửa sổ kích thước 800x600 pixels
////	sf::renderwindow window(sf::videomode(1195, 672), "drawing line");
////
////	sf::rectangleshape thickline(sf::vector2f(1195, 3));
////	thickline.setfillcolor(sf::color::red);
////	thickline.setposition(0, 100);
////
////
////	//////////////////////order//////////////////
////	sf::texture texture;
////	if (!texture.loadfromfile("order.jpg"))
////		return exit_failure;
////
////	// tạo sprite sử dụng texture đã tải
////	sf::sprite sprite(texture);
////	sf::vector2u windowsize = window.getsize();
////	float scalex = 1195.0 / texture.getsize().x;
////	float scaley = 572.0 / texture.getsize().y;
////	sprite.setscale(scalex, scaley);
////	sprite.setposition(0, 100);
////
////	//std::pair<sf::rectangleshape, bool> box[3][12][6];
////	//vector< std::pair<sf::rectangleshape, bool>> box[12][6];
////
////	double x_0 = 157, y_0 = 277;
////	double delta_x = 74.5, delta_y = 64;
////
////	//for (int k = 0; k < 3; k++) {
////	//	for (int i = 0; i < 12; i++) {
////	//		for (int j = 0; j < 6; j++) {
////	//			double x = x_0 + i * delta_x, y = y_0 + j * delta_y;
////	//			box[k][i][j].second = false;
////	//			box[k][i][j].first.setsize(sf::vector2f(59, 52));
////	//			box[k][i][j].first.setfillcolor(sf::color(238, 100, 87)); //100, 238, 87
////	//			box[k][i][j].first.setoutlinethickness(2);
////	//			box[k][i][j].first.setoutlinecolor(sf::color::black);
////	//			box[k][i][j].first.setposition(x, y);
////	//		}
////	//	}
////	//}
////
////	std::pair<sf::rectangleshape, bool> box[12][6];
////	for (int i = 0; i < 12; i++) {
////		for (int j = 0; j < 6; j++) {
////			double x = x_0 + i * delta_x, y = y_0 + j * delta_y;
////			box[i][j].second = false;
////			box[i][j].first.setsize(sf::vector2f(59, 52));
////			box[i][j].first.setfillcolor(sf::color(238, 100, 87)); //100, 238, 87
////			box[i][j].first.setoutlinethickness(2);
////			box[i][j].first.setoutlinecolor(sf::color::black);
////			box[i][j].first.setposition(x, y);
////		}
////	}
////
////
////	//////////////////////order//////////////////
////
////	///////////////////////////////////
////
////	sf::font font;
////	if (!font.loadfromfile("shortbaby-mg2w.ttf"))
////	{
////		std::cout << "failed to load font!" << std::endl;
////		return -1;
////	}
////
////	//bool selectbutton[3]; memset(selectbutton, false, 3);
////	bool homepagebutton = true;
////	bool selectdropdownbutton = false;
////	bool selectandupdatebutton = false;
////	bool createbuttonactive = false;
////
////	sf::text homepagetext("homepage", font, 24);
////	homepagetext.setfillcolor(sf::color::black);
////	homepagetext.setposition(500, 500);
////
////	sf::circleshape button1(25);
////	button1.setfillcolor(sf::color(139, 216, 189)); // màu xám
////	button1.setoutlinethickness(5);
////	button1.setoutlinecolor(sf::color(150, 150, 150)); // màu xám nhạt
////	button1.setposition(100, 25);
////
////	sf::texture texture1;
////	if (!texture1.loadfromfile("icon-home-removebg-preview.png"))
////	{
////		std::cout << "failed to load icon." << std::endl;
////		return -1;
////	}
////	sf::sprite iconsprite1(texture1);
////	iconsprite1.setscale(0.1f, 0.1f);
////	iconsprite1.setposition(94, 28);
////	///////////////////////////////////
////
////	//////////////////dropdown/////////////////////////
////
////	sf::rectangleshape dropdownbox(sf::vector2f(125, 50));
////	dropdownbox.setfillcolor(sf::color::white);
////	dropdownbox.setoutlinethickness(2);
////	dropdownbox.setoutlinecolor(sf::color::black);
////	dropdownbox.setposition(300, 25);
////
////	sf::text dropdowntext("rap", font, 24);
////	dropdowntext.setfillcolor(sf::color::black);
////	dropdowntext.setposition(331, 35);
////
////	std::vector< std::pair<sf::text, sf::rectangleshape> > options;
////	sf::rectangleshape option1box(sf::vector2f(125, 50));
////	option1box.setfillcolor(sf::color::white);
////	option1box.setoutlinethickness(2);
////	option1box.setoutlinecolor(sf::color::black);
////	option1box.setposition(300, 75);
////
////	sf::text option1("rap 1", font, 24);
////	option1.setposition(330, 85);
////	option1.setfillcolor(sf::color::black);
////	options.push_back({ option1 , option1box });
////
////	sf::rectangleshape option2box(sf::vector2f(125, 50));
////	option2box.setfillcolor(sf::color::white);
////	option2box.setoutlinethickness(2);
////	option2box.setoutlinecolor(sf::color::black);
////	option2box.setposition(300, 125);
////
////	sf::text option2("rap 2", font, 24);
////	option2.setposition(330, 135);
////	option2.setfillcolor(sf::color::black);
////	options.push_back({ option2 , option2box });
////
////	sf::rectangleshape option3box(sf::vector2f(125, 50));
////	option3box.setfillcolor(sf::color::white);
////	option3box.setoutlinethickness(2);
////	option3box.setoutlinecolor(sf::color::black);
////	option3box.setposition(300, 175);
////
////	sf::text option3("rap 3", font, 24);
////	option3.setposition(330, 185);
////	option3.setfillcolor(sf::color::black);
////	options.push_back({ option3 , option3box });
////
////	bool isdropdownactive = false;
////
////	sf::convexshape arrow(3);
////	arrow.setpoint(0, sf::vector2f(0, 0));
////	arrow.setpoint(1, sf::vector2f(15, 0));
////	arrow.setpoint(2, sf::vector2f(7.5, 7.5));
////	arrow.setfillcolor(sf::color::black);
////	arrow.setposition(400, 47);
////	bool isarrowdownup = true;
////
////	//////////////////dropdown/////////////////////////
////
////	/////////////////create////////////////////////////
////
////	sf::rectangleshape createbutton(sf::vector2f(125, 50));
////	createbutton.setfillcolor(sf::color::white);
////	createbutton.setoutlinethickness(2);
////	createbutton.setoutlinecolor(sf::color::black);
////	createbutton.setposition(600, 25);
////
////	sf::text createbuttontext("them moi", font, 24);
////	createbuttontext.setfillcolor(sf::color::black);
////	createbuttontext.setposition(614, 35);
////
////	/////////////////create////////////////////////////
////
////
////	while (window.isopen())
////	{
////		sf::event event;
////		while (window.pollevent(event))
////		{
////			if (event.type == sf::event::closed)
////			{
////				window.close();
////			}
////			if (event.type == sf::event::mousebuttonpressed && event.mousebutton.button == sf::mouse::left)
////			{
////				// kiểm tra xem người dùng đã ấn vào nút hay chưa
////				if (button1.getglobalbounds().contains(event.mousebutton.x, event.mousebutton.y))
////				{
////					homepagebutton = true;
////					selectdropdownbutton = false;
////					selectandupdatebutton = false;
////				}
////				if (ismouseover(dropdownbox, window))
////				{
////					dropdownbox.setfillcolor(sf::color(111, 110, 111));
////					isdropdownactive = !isdropdownactive;
////				}
////				else if (isdropdownactive)
////				{
////					for (int i = 0; i < 3; i++) {
////						{
////							if (ismouseover(options[i].second, window))
////							{
////								dropdowntext.setstring(options[i].first.getstring());
////								dropdownbox.setfillcolor(sf::color::white);
////								isdropdownactive = false;
////								isarrowdownup = true;
////								homepagebutton = false;  selectdropdownbutton = true; selectandupdatebutton = true;
////								break;
////							}
////						}
////					}
////
////				}
////				if (selectandupdatebutton) {
////					for (int i = 0; i < 12; i++) {
////						for (int j = 0; j < 6; j++) {
////							if (box[i][j].first.getglobalbounds().contains(event.mousebutton.x, event.mousebutton.y)) {
////								if (box[i][j].second) {
////									box[i][j].second = false;
////									box[i][j].first.setfillcolor(sf::color(238, 100, 87)); //100, 238, 87
////
////								}
////								else {
////									box[i][j].second = true;
////									box[i][j].first.setfillcolor(sf::color(100, 238, 87)); //100, 238, 87
////								}
////							}
////						}
////					}
////				}
////			}
////		}
////		window.clear(sf::color::white);
////
////		//if (homepageadmin) {
////		window.draw(button1);
////		window.draw(iconsprite1);
////		//}
////
////		if (homepagebutton) {
////			window.draw(homepagetext);
////		}
////
////		if (selectdropdownbutton) {
////			window.draw(sprite);
////		}
////
////		if (selectandupdatebutton) {
////			for (int i = 0; i < 12; i++) {
////				for (int j = 0; j < 6; j++) {
////					window.draw(box[i][j].first);
////				}
////			}
////		}
////
////		window.draw(thickline);
////
////		window.draw(dropdownbox);
////		window.draw(dropdowntext);
////		if (isarrowdownup) {
////			arrow.setpoint(0, sf::vector2f(0, 0));
////			arrow.setpoint(1, sf::vector2f(15, 0));
////			arrow.setpoint(2, sf::vector2f(7.5, 7.5));
////			arrow.setfillcolor(sf::color::black);
////			window.draw(arrow);
////		}
////
////		if (isdropdownactive)
////		{
////			isarrowdownup = false;
////			arrow.setpoint(0, sf::vector2f(7.5, 0));
////			arrow.setpoint(1, sf::vector2f(0, 7.5));
////			arrow.setpoint(2, sf::vector2f(15, 7.5));
////			arrow.setfillcolor(sf::color::black);
////			window.draw(arrow);
////
////			for (const std::pair<sf::text, sf::rectangleshape> option : options)
////			{
////				window.draw(option.second);
////				window.draw(option.first);
////			}
////		}
////
////		window.draw(createbutton);
////		window.draw(createbuttontext);
////
////		window.display();
////	}
////}
//
//
//
////#include <sfml/graphics.hpp>
////#include <iostream>
////#include <string>
////#include <vector>
////
////
////int main()
////{
////	// tạo cửa sổ kích thước 800x600 pixels
////	sf::renderwindow window(sf::videomode(1195, 672), "product list");
////
////	// tạo danh sách sản phẩm
////
////	sf::rectangleshape thickline(sf::vector2f(1195, 3));
////	thickline.setfillcolor(sf::color::red);
////	thickline.setposition(0, 100);
////
////	// tạo các sản phẩm
////	sf::font font;
////	if (!font.loadfromfile("svn-times new roman bold.ttf"))
////	{
////		std::cout << "failed to load font!" << std::endl;
////		return -1;
////	}
////
////	std::vector<pair<string, string>> films;
////
////	string title = "my nhan dao chich";
////	string linkimage = "mynhandaochich.jpg";
////	films.push_back({ title, linkimage });
////
////	title = "am hon do thi";
////	linkimage = "amhondothi.jpg";
////	films.push_back({ title, linkimage });
////
////	title = "nguoi vo cuoi cung";
////	linkimage = "nguoivocuoicung.jpg";
////	films.push_back({ title, linkimage });
////
////	title = "nam dem kinh hoang";
////	linkimage = "5demkinhhoang.jpg";
////	films.push_back({ title, linkimage });
////
////	title = "quy mon quan";
////	linkimage = "quymonquan.jpg";
////	films.push_back({ title, linkimage });
////
////	title = "wolfoo";
////	linkimage = "wolfoo.jpg";
////	films.push_back({ title, linkimage });
////
////	title = "dat rung phuong nam";
////	linkimage = "datrungphuongnam.jpg";
////	films.push_back({ title, linkimage });
////
////	title = "biet doi marvel";
////	linkimage = "marvel.jpg";
////	films.push_back({ title, linkimage });
////
////	title = "hai ke doi tra";
////	linkimage = "haikedoitra.png";
////	films.push_back({ title, linkimage });
////
////	std::vector<pair<sf::rectangleshape, pair<sf::text, string>>> productboxes;
////
////	for (int i = 0; i < films.size(); i++)
////	{
////		sf::rectangleshape productbox(sf::vector2f(300, 500));
////		productbox.setfillcolor(sf::color::white);
////		productbox.setoutlinethickness(2);
////		productbox.setoutlinecolor(sf::color::black);
////		productbox.setposition(20 + i * 350, 125);
////
////		sf::text producttext(films[i].first, font, 24);
////		producttext.setfillcolor(sf::color::black);
////		float textx = productbox.getposition().x + productbox.getsize().x / 2 - producttext.getlocalbounds().width / 2;
////		//producttext.setposition(30 + i * 350, 135);
////		producttext.setposition(textx, 600);
////
////		productboxes.push_back({ productbox , {producttext, films[i].second} });
////	}
////
////	// vòng lặp chính
////	while (window.isopen())
////	{
////		// xử lý các sự kiện
////		sf::event event;
////		while (window.pollevent(event))
////		{
////			if (event.type == sf::event::closed)
////			{
////				window.close();
////			}
////			if (event.type == sf::event::mousebuttonpressed && event.mousebutton.button == sf::mouse::left)
////			{
////				for (int i = 0; i < productboxes.size(); i++)
////				{
////					if (productboxes[i].first.getglobalbounds().contains(event.mousebutton.x, event.mousebutton.y)) {
////						cout << productboxes[i].second.first.getstring().toansistring() << endl;
////					}
////				}
////			}
////		}
////
////		// cập nhật vị trí của các sản phẩm
////		sf::vector2f offset(0, 0);
////		sf::vector2f newpos = productboxes[productboxes.size() - 1].first.getposition() + offset;
////		float textx = productboxes[productboxes.size() - 1].first.getposition().x + productboxes[productboxes.size() - 1].first.getsize().x / 2 - productboxes[productboxes.size() - 1].second.first.getlocalbounds().width / 2;
////
////		for (int i = productboxes.size() - 1; i >= 1; i--)
////		{
////			productboxes[i].first.setposition(productboxes[i - 1].first.getposition());
////			float textx = productboxes[i].first.getposition().x + productboxes[i].first.getsize().x / 2 - productboxes[i].second.first.getlocalbounds().width / 2;
////			productboxes[i].second.first.setposition(textx, 600);
////		}
////
////		productboxes[0].first.setposition(newpos);
////		productboxes[0].second.first.setposition(textx, 600);
////
////		// xóa màn hình
////		window.clear(sf::color::white);
////
////		//window.draw(sprite);
////		window.draw(thickline);
////
////
////
////		// vẽ các sản phẩm
////		for (int i = 0; i < films.size(); i++)
////		{
////			sf::texture texture;
////			if (!texture.loadfromfile(productboxes[i].second.second)) {
////				return exit_failure;
////			}
////			sf::sprite sprite(texture);
////			sf::vector2u windowsize = window.getsize();
////			float scalex = 290.0 / texture.getsize().x;
////			float scaley = 475.0 / texture.getsize().y;
////			sprite.setscale(scalex, scaley);
////			float x = productboxes[i].first.getposition().x + 5;
////			float y = productboxes[i].first.getposition().y + 5;
////			sprite.setposition(x, y);
////
////			window.draw(productboxes[i].first);
////			window.draw(sprite);
////			window.draw(productboxes[i].second.first);
////		}
////
////
////		// hiển thị màn hình
////		window.display();
////
////		// chờ một giây
////		sf::sleep(sf::seconds(1));
////	}
////
////	return 0;
////}
//
//struct film {
//	string title;
//	string desc;
//	string image;
//};
//
//std::vector<film> films;
////std::vector<pair<sf::rectangleshape, pair<sf::text, string>>> productboxes;
////std::pair<sf::rectangleshape, bool> box[3][12][6];
//
//int createfilmswindow(vector<pair<sf::rectangleshape, pair<sf::text, string>>>& productboxes, sf::renderwindow& mainwindow)
//{
//	sf::renderwindow window(sf::videomode(1050, 1000), "create window");
//
//	sf::texture texture;
//	if (!texture.loadfromfile("fotor-ai-20231112163130.jpg"))
//		return exit_failure;
//
//	sf::font font;
//	if (!font.loadfromfile("svn-times new roman bold.ttf"))
//	{
//		std::cout << "failed to load font!" << std::endl;
//		return -1;
//	}
//
//	// tạo sprite sử dụng texture đã tải
//	sf::sprite sprite(texture);
//	sf::vector2u windowsize = window.getsize();
//	float scalex = 1050.0 / texture.getsize().x;
//	float scaley = 1000.0 / texture.getsize().y;
//	sprite.setscale(scalex, scaley);
//
//
//	sf::rectangleshape buttontitle(sf::vector2f(600, 45));
//	buttontitle.setfillcolor(sf::color(86, 0, 172, 70));
//	buttontitle.setposition(200, 70);
//
//	sf::rectangleshape linetitle(sf::vector2f(5, 45));
//	linetitle.setfillcolor(sf::color(18, 104, 10));
//	linetitle.setposition(200, 70);
//
//	sf::text inputtexttitle;
//	inputtexttitle.setfont(font);
//	inputtexttitle.setcharactersize(27);
//	inputtexttitle.setfillcolor(sf::color(255, 255, 255));
//	inputtexttitle.setposition(210, 73);
//
//	sf::rectangleshape buttondesc(sf::vector2f(600, 500));
//	buttondesc.setfillcolor(sf::color(86, 0, 172, 70));
//	buttondesc.setposition(200, 200);
//
//	sf::rectangleshape linedesc(sf::vector2f(5, 500));
//	linedesc.setfillcolor(sf::color(18, 104, 10));
//	linedesc.setposition(200, 200);
//
//	sf::text inputtextdesc;
//	inputtextdesc.setfont(font);
//	inputtextdesc.setcharactersize(27);
//	inputtextdesc.setfillcolor(sf::color(255, 255, 255));
//	inputtextdesc.setposition(210, 196);
//
//	sf::rectangleshape buttonimage(sf::vector2f(600, 45));
//	buttonimage.setfillcolor(sf::color(86, 0, 172, 70));
//	buttonimage.setposition(200, 785);
//
//	sf::rectangleshape lineimage(sf::vector2f(5, 45));
//	lineimage.setfillcolor(sf::color(18, 104, 10));
//	lineimage.setposition(200, 785);
//
//	sf::text inputtextimage;
//	inputtextimage.setfont(font);
//	inputtextimage.setcharactersize(27);
//	inputtextimage.setfillcolor(sf::color(255, 255, 255));
//	inputtextimage.setposition(210, 788);
//
//	sf::texture createtexture;
//	if (!createtexture.loadfromfile("2023-11-13_171327.png"))
//		return exit_failure;
//
//	sf::sprite createsprite(createtexture);
//	float scalex1 = 300.0 / createtexture.getsize().x;
//	float scaley1 = 75.0 / createtexture.getsize().y;
//	createsprite.setscale(scalex1, scaley1);
//	createsprite.setposition(350, 870);
//
//	sf::font fontcreate;
//	if (!fontcreate.loadfromfile("sourcesanspro-bold.ttf"))
//	{
//		std::cout << "failed to load font!" << std::endl;
//		return -1;
//	}
//
//	sf::text textcreate;
//	textcreate.setfont(fontcreate);
//	textcreate.setcharactersize(37);
//	textcreate.setfillcolor(sf::color(255, 255, 255));
//	textcreate.setposition(432, 883);
//	textcreate.setstring("create");
//
//	string textdesc = "";
//
//	bool isinputtitleactive = false;
//	bool isinputdescactive = false;
//	bool isinputimageactive = false;
//
//	while (window.isopen())
//	{
//		sf::event event;
//		while (window.pollevent(event))
//		{
//			if (event.type == sf::event::closed)
//			{
//				window.close();
//			}
//			if (event.type == sf::event::mousebuttonpressed && event.mousebutton.button == sf::mouse::left)
//			{
//				if (ismouseover(buttontitle, event))
//				{
//					linetitle.setfillcolor(sf::color(128, 241, 118));
//					linedesc.setfillcolor(sf::color(18, 104, 10));
//					lineimage.setfillcolor(sf::color(18, 104, 10));
//					isinputtitleactive = true;
//					isinputdescactive = false;
//					isinputimageactive = false;
//				}
//				else if (ismouseover(buttondesc, event))
//				{
//					linedesc.setfillcolor(sf::color(128, 241, 118));
//					linetitle.setfillcolor(sf::color(18, 104, 10));
//					lineimage.setfillcolor(sf::color(18, 104, 10));
//					isinputdescactive = true;
//					isinputtitleactive = false;
//					isinputimageactive = false;
//				}
//				else if (ismouseover(buttonimage, event)) {
//					lineimage.setfillcolor(sf::color(128, 241, 118));
//					linedesc.setfillcolor(sf::color(18, 104, 10));
//					linetitle.setfillcolor(sf::color(18, 104, 10));
//					isinputdescactive = false;
//					isinputtitleactive = false;
//					isinputimageactive = true;
//				}
//				else {
//					linedesc.setfillcolor(sf::color(18, 104, 10));
//					linetitle.setfillcolor(sf::color(18, 104, 10));
//					lineimage.setfillcolor(sf::color(18, 104, 10));
//					isinputdescactive = false;
//					isinputtitleactive = false;
//					isinputimageactive = false;
//				}
//
//				if (createsprite.getglobalbounds().contains(event.mousebutton.x, event.mousebutton.y)) {
//					string currenttexttitle = inputtexttitle.getstring();
//					string currenttextdesc = textdesc;
//					string currenttextimage = inputtextimage.getstring();
//					if (currenttexttitle == "") {
//						linetitle.setfillcolor(sf::color(126, 0, 33));
//					}
//					if (currenttextdesc == "") {
//						linedesc.setfillcolor(sf::color(126, 0, 33));
//					}
//					if (currenttextimage == "") {
//						lineimage.setfillcolor(sf::color(126, 0, 33));
//					}
//					if (currenttexttitle != "" && currenttextdesc != "" && currenttextimage != "") {
//						films.push_back({ currenttexttitle, currenttextdesc, currenttextimage });
//						sf::rectangleshape productbox(sf::vector2f(300, 500));
//						productbox.setfillcolor(sf::color::white);
//						productbox.setoutlinethickness(2);
//						productbox.setoutlinecolor(sf::color::black);
//						productbox.setposition(20 + (films.size() - 1) * 350, 125);
//
//						sf::text producttext(currenttexttitle, font, 24);
//						producttext.setfillcolor(sf::color::black);
//						float textx = productbox.getposition().x + productbox.getsize().x / 2 - producttext.getlocalbounds().width / 2;
//						//producttext.setposition(30 + i * 350, 135);
//						producttext.setposition(textx, 600);
//
//						productboxes.push_back({ productbox , {producttext, currenttextimage} });
//						
//					}
//				}
//			}
//			else if (event.type == sf::event::textentered)
//			{
//				if (isinputtitleactive)
//				{
//					if (event.text.unicode < 128)
//					{
//						if (event.text.unicode == '\b')
//						{
//							if (!inputtexttitle.getstring().isempty()) {
//								std::string currenttext = inputtexttitle.getstring();
//								currenttext.pop_back();
//								inputtexttitle.setstring(currenttext);
//							}
//						}
//						else if (event.text.unicode == '\r' || event.text.unicode == '\n')
//						{
//							inputtexttitle.setstring(inputtexttitle.getstring() + "\n");
//						}
//						else
//						{
//							inputtexttitle.setstring(inputtexttitle.getstring() + static_cast<char>(event.text.unicode));
//						}
//					}
//				}
//				else if (isinputdescactive)
//				{
//					if (event.text.unicode < 128)
//					{
//						if (event.text.unicode == '\b')
//						{
//							if (!inputtextdesc.getstring().isempty()) {
//								std::string currenttext = inputtextdesc.getstring();
//								currenttext.pop_back();
//								textdesc.pop_back();
//								inputtextdesc.setstring(currenttext);
//							}
//						}
//						else if (event.text.unicode == '\r' || event.text.unicode == '\n')
//						{
//							inputtextdesc.setstring(inputtextdesc.getstring() + "\n");
//							textdesc += "\n";
//						}
//						else
//						{
//							string laststring;
//							stringstream ss(inputtextdesc.getstring());
//							while (getline(ss, laststring, '\n')) {
//							}
//
//							sf::text temptext;
//							temptext.setfont(font);
//							temptext.setcharactersize(27);
//							temptext.setstring(laststring);
//							float linedescwidth = temptext.getlocalbounds().width;
//							float buttondescwidth = buttondesc.getlocalbounds().width;
//							if (linedescwidth > buttondescwidth - 20)
//							{
//								// thêm ký tự xuống dòng
//								inputtextdesc.setstring(inputtextdesc.getstring() + "\n");
//							}
//							inputtextdesc.setstring(inputtextdesc.getstring() + static_cast<char>(event.text.unicode));
//							textdesc += static_cast<char>(event.text.unicode);
//						}
//
//					}
//				}
//				else if (isinputimageactive)
//				{
//					if (event.text.unicode < 128)
//					{
//						if (event.text.unicode == '\b')
//						{
//							if (!inputtextimage.getstring().isempty()) {
//								std::string currenttext = inputtextimage.getstring();
//								currenttext.pop_back();
//								inputtextimage.setstring(currenttext);
//							}
//						}
//						else if (event.text.unicode == '\r' || event.text.unicode == '\n')
//						{
//							inputtextimage.setstring(inputtextimage.getstring() + "\n");
//						}
//						else
//						{
//							inputtextimage.setstring(inputtextimage.getstring() + static_cast<char>(event.text.unicode));
//						}
//					}
//				}
//			}
//			if (event.type == sf::event::mousemoved)
//			{
//				sf::vector2i mouseposition = sf::mouse::getposition(window);
//				if (createsprite.getglobalbounds().contains(static_cast<float>(mouseposition.x), static_cast<float>(mouseposition.y)))
//				{
//					if (!createtexture.loadfromfile("2023-11-13_173035.png"))
//						return exit_failure;
//					float scalex1 = 300.0 / createtexture.getsize().x;
//					float scaley1 = 75.0 / createtexture.getsize().y;
//					createsprite.setscale(scalex1, scaley1);
//				}
//				else
//				{
//					if (!createtexture.loadfromfile("2023-11-13_171327.png"))
//						return exit_failure;
//					float scalex1 = 300.0 / createtexture.getsize().x;
//					float scaley1 = 75.0 / createtexture.getsize().y;
//					createsprite.setscale(scalex1, scaley1);
//				}
//			}
//		}
//
//		window.clear();
//		window.draw(sprite);
//
//		window.draw(buttontitle);
//		window.draw(inputtexttitle);
//		window.draw(linetitle);
//
//		window.draw(buttondesc);
//		window.draw(inputtextdesc);
//		window.draw(linedesc);
//
//		window.draw(buttonimage);
//		window.draw(inputtextimage);
//		window.draw(lineimage);
//
//		window.draw(createsprite);
//		window.draw(textcreate);
//
//		window.display();
//	}
//
//	return 0;
//}
//
////int main()
////{
////	// tạo cửa sổ kích thước 800x600 pixels
////
////	sf::renderwindow window(sf::videomode(1195, 672), "drawing line");
////	
////
////	//////////////////////font///////////////////////////
////	sf::font font;
////	if (!font.loadfromfile("svn-times new roman bold.ttf"))
////	{
////		std::cout << "failed to load font!" << std::endl;
////		return -1;
////	}
////	//////////////////////font///////////////////////////
////
////
////	sf::rectangleshape thickline(sf::vector2f(1195, 3));
////	thickline.setfillcolor(sf::color::red);
////	thickline.setposition(0, 100);
////
////	//////////////////////homepage//////////////////
////	
////	//std::vector<pair<string, string>> films;
////
////	string title = "my nhan dao chich";
////	string desc = "";
////	string linkimage = "mynhandaochich.jpg";
////	films.push_back({ title, desc, linkimage });
////
////	title = "am hon do thi";
////	desc = "";
////	linkimage = "amhondothi.jpg";
////	films.push_back({ title, desc, linkimage });
////
////	title = "nguoi vo cuoi cung";
////	desc = "";
////	linkimage = "nguoivocuoicung.jpg";
////	films.push_back({ title, desc, linkimage });
////
////	title = "nam dem kinh hoang";
////	desc = "";
////	linkimage = "5demkinhhoang.jpg";
////	films.push_back({ title, desc, linkimage });
////
////	title = "quy mon quan";
////	desc = "";
////	linkimage = "quymonquan.jpg";
////	films.push_back({ title, desc, linkimage });
////
////	title = "wolfoo";
////	desc = "";
////	linkimage = "wolfoo.jpg";
////	films.push_back({ title, desc, linkimage });
////
////	title = "dat rung phuong nam";
////	desc = "";
////	linkimage = "datrungphuongnam.jpg";
////	films.push_back({ title, desc, linkimage });
////
////	title = "biet doi marvel";
////	desc = "";
////	linkimage = "marvel.jpg";
////	films.push_back({ title, desc, linkimage });
////
////	title = "hai ke doi tra";
////	desc = "";
////	linkimage = "haikedoitra.png";
////	films.push_back({ title, desc, linkimage });
////
////	std::vector<pair<sf::rectangleshape, pair<sf::text, string>>> productboxes;
////
////	for (int i = 0; i < films.size(); i++)
////	{
////		sf::rectangleshape productbox(sf::vector2f(300, 500));
////		productbox.setfillcolor(sf::color::white);
////		productbox.setoutlinethickness(2);
////		productbox.setoutlinecolor(sf::color::black);
////		productbox.setposition(20 + i * 350, 125);
////
////		sf::text producttext(films[i].title, font, 24);
////		producttext.setfillcolor(sf::color::black);
////		float textx = productbox.getposition().x + productbox.getsize().x / 2 - producttext.getlocalbounds().width / 2;
////		//producttext.setposition(30 + i * 350, 135);
////		producttext.setposition(textx, 600);
////
////		productboxes.push_back({ productbox , {producttext, films[i].image} });
////	}
////
////	//////////////////////homepage//////////////////
////
////
////	//////////////////////order//////////////////
////	sf::texture texture;
////	if (!texture.loadfromfile("order.jpg"))
////		return exit_failure;
////
////	// tạo sprite sử dụng texture đã tải
////	sf::sprite sprite(texture);
////	sf::vector2u windowsize = window.getsize();
////	float scalex = 1195.0 / texture.getsize().x;
////	float scaley = 572.0 / texture.getsize().y;
////	sprite.setscale(scalex, scaley);
////	sprite.setposition(0, 100);
////
////	std::pair<sf::rectangleshape, bool> box[3][12][6];
////	//vector< std::pair<sf::rectangleshape, bool>> box[12][6];
////
////	double x_0 = 157, y_0 = 277;
////	double delta_x = 74.5, delta_y = 64;
////
////	for (int k = 0; k < 3; k++) {
////		for (int i = 0; i < 12; i++) {
////			for (int j = 0; j < 6; j++) {
////				double x = x_0 + i * delta_x, y = y_0 + j * delta_y;
////				box[k][i][j].second = false;
////				box[k][i][j].first.setsize(sf::vector2f(59, 52));
////				box[k][i][j].first.setfillcolor(sf::color(238, 100, 87)); //100, 238, 87
////				box[k][i][j].first.setoutlinethickness(2);
////				box[k][i][j].first.setoutlinecolor(sf::color::black);
////				box[k][i][j].first.setposition(x, y);
////			}
////		}
////	}
////
////
////	//////////////////////order//////////////////
////
////	///////////////////////////////////
////
////	//bool selectbutton[3]; memset(selectbutton, false, 3);
////	bool homepagebutton = true;
////	bool selectdropdownbutton = false;
////	bool selectandupdatebutton = false; int indexbutton = 0;
////	bool createbuttonactive = false;
////
////	sf::text homepagetext("homepage", font, 24);
////	homepagetext.setfillcolor(sf::color::black);
////	homepagetext.setposition(500, 500);
////
////	sf::circleshape button1(25);
////	button1.setfillcolor(sf::color(139, 216, 189)); // màu xám
////	button1.setoutlinethickness(5);
////	button1.setoutlinecolor(sf::color(150, 150, 150)); // màu xám nhạt
////	button1.setposition(100, 25);
////
////	sf::texture texture1;
////	if (!texture1.loadfromfile("icon-home-removebg-preview.png"))
////	{
////		std::cout << "failed to load icon." << std::endl;
////		return -1;
////	}
////	sf::sprite iconsprite1(texture1);
////	iconsprite1.setscale(0.1f, 0.1f);
////	iconsprite1.setposition(94, 28);
////	///////////////////////////////////
////
////	//////////////////dropdown/////////////////////////
////
////	sf::rectangleshape dropdownbox(sf::vector2f(125, 50));
////	dropdownbox.setfillcolor(sf::color::white);
////	dropdownbox.setoutlinethickness(2);
////	dropdownbox.setoutlinecolor(sf::color::black);
////	dropdownbox.setposition(300, 25);
////
////	sf::text dropdowntext("room", font, 24);
////	dropdowntext.setfillcolor(sf::color::black);
////	dropdowntext.setposition(320, 35);
////
////	std::vector< std::pair<sf::text, sf::rectangleshape> > options;
////	sf::rectangleshape option1box(sf::vector2f(125, 50));
////	option1box.setfillcolor(sf::color::white);
////	option1box.setoutlinethickness(2);
////	option1box.setoutlinecolor(sf::color::black);
////	option1box.setposition(300, 75);
////
////	sf::text option1("room 1", font, 24);
////	option1.setposition(323, 85);
////	option1.setfillcolor(sf::color::black);
////	options.push_back({ {option1} , option1box });
////
////	sf::rectangleshape option2box(sf::vector2f(125, 50));
////	option2box.setfillcolor(sf::color::white);
////	option2box.setoutlinethickness(2);
////	option2box.setoutlinecolor(sf::color::black);
////	option2box.setposition(300, 125);
////
////	sf::text option2("room 2", font, 24);
////	option2.setposition(323, 135);
////	option2.setfillcolor(sf::color::black);
////	options.push_back({ {option2} , option2box });
////
////	sf::rectangleshape option3box(sf::vector2f(125, 50));
////	option3box.setfillcolor(sf::color::white);
////	option3box.setoutlinethickness(2);
////	option3box.setoutlinecolor(sf::color::black);
////	option3box.setposition(300, 175);
////
////	sf::text option3("room 3", font, 24);
////	option3.setposition(323, 185);
////	option3.setfillcolor(sf::color::black);
////	options.push_back({ {option3} , option3box });
////
////	bool isdropdownactive = false;
////
////	sf::convexshape arrow(3);
////	arrow.setpoint(0, sf::vector2f(0, 0));
////	arrow.setpoint(1, sf::vector2f(15, 0));
////	arrow.setpoint(2, sf::vector2f(7.5, 7.5));
////	arrow.setfillcolor(sf::color::black);
////	arrow.setposition(405, 47);
////	bool isarrowdownup = true;
////
////	//////////////////dropdown/////////////////////////
////
////	/////////////////create////////////////////////////
////
////	sf::rectangleshape createbutton(sf::vector2f(125, 50));
////	createbutton.setfillcolor(sf::color::white);
////	createbutton.setoutlinethickness(2);
////	createbutton.setoutlinecolor(sf::color::black);
////	createbutton.setposition(600, 25);
////
////	sf::text createbuttontext("create", font, 24);
////	createbuttontext.setfillcolor(sf::color::black);
////	createbuttontext.setposition(630, 35);
////
////	/////////////////create////////////////////////////
////
////	sf::renderwindow window1(sf::videomode(1050, 1000), "create window");
////	window1.setvisible(false);
////
////	while (window.isopen())
////	{
////		sf::event event;
////		while (window.pollevent(event))
////		{
////			if (event.type == sf::event::closed)
////			{
////				window.close();
////			}
////			if (event.type == sf::event::mousebuttonpressed && event.mousebutton.button == sf::mouse::left)
////			{
////				// kiểm tra xem người dùng đã ấn vào nút hay chưa
////				if (button1.getglobalbounds().contains(event.mousebutton.x, event.mousebutton.y))
////				{
////					homepagebutton = true;
////					selectdropdownbutton = false;
////					dropdowntext.setstring("room");
////					selectandupdatebutton = false;
////					indexbutton = 0;
////				}
////				if (ismouseover(dropdownbox, window))
////				{
////					dropdownbox.setfillcolor(sf::color(111, 110, 111));
////					isdropdownactive = !isdropdownactive;
////				}
////				else if (isdropdownactive)
////				{
////					for (int i = 0; i < 3; i++) {
////						{
////							//option.first.second = false;
////							if (ismouseover(options[i].second, window))
////							{
////								dropdowntext.setstring(options[i].first.getstring());
////								indexbutton = i + 1;
////								dropdownbox.setfillcolor(sf::color::white);
////								isdropdownactive = false;
////								isarrowdownup = true;
////								homepagebutton = false;  selectdropdownbutton = true; selectandupdatebutton = true;
////								break;
////							}
////						}
////					}
////
////				}
////				if (selectandupdatebutton) {
////					if (indexbutton) {
////						for (int i = 0; i < 12; i++) {
////							for (int j = 0; j < 6; j++) {
////								if (box[indexbutton - 1][i][j].first.getglobalbounds().contains(event.mousebutton.x, event.mousebutton.y)) {
////									if (box[indexbutton - 1][i][j].second) {
////										box[indexbutton - 1][i][j].second = false;
////										box[indexbutton - 1][i][j].first.setfillcolor(sf::color(238, 100, 87)); //100, 238, 87
////
////									}
////									else {
////										box[indexbutton - 1][i][j].second = true;
////										box[indexbutton - 1][i][j].first.setfillcolor(sf::color(100, 238, 87)); //100, 238, 87
////									}
////								}
////							}
////						}
////					}
////				}
////				if (createbutton.getglobalbounds().contains(event.mousebutton.x, event.mousebutton.y))
////				{
////					//createfilmswindow(productboxes, window);
////					window.setvisible(false);
////					window1.setvisible(true);
////					sf::texture texture;
////					if (!texture.loadfromfile("fotor-ai-20231112163130.jpg"))
////						return exit_failure;
////
////					// tạo sprite sử dụng texture đã tải
////					sf::sprite sprite(texture);
////					sf::vector2u windowsize = window1.getsize();
////					float scalex = 1050.0 / texture.getsize().x;
////					float scaley = 1000.0 / texture.getsize().y;
////					sprite.setscale(scalex, scaley);
////
////
////					sf::rectangleshape buttontitle(sf::vector2f(600, 45));
////					buttontitle.setfillcolor(sf::color(86, 0, 172, 70));
////					buttontitle.setposition(200, 70);
////
////					sf::rectangleshape linetitle(sf::vector2f(5, 45));
////					linetitle.setfillcolor(sf::color(18, 104, 10));
////					linetitle.setposition(200, 70);
////
////					sf::text inputtexttitle;
////					inputtexttitle.setfont(font);
////					inputtexttitle.setcharactersize(27);
////					inputtexttitle.setfillcolor(sf::color(255, 255, 255));
////					inputtexttitle.setposition(210, 73);
////
////					sf::rectangleshape buttondesc(sf::vector2f(600, 500));
////					buttondesc.setfillcolor(sf::color(86, 0, 172, 70));
////					buttondesc.setposition(200, 200);
////
////					sf::rectangleshape linedesc(sf::vector2f(5, 500));
////					linedesc.setfillcolor(sf::color(18, 104, 10));
////					linedesc.setposition(200, 200);
////
////					sf::text inputtextdesc;
////					inputtextdesc.setfont(font);
////					inputtextdesc.setcharactersize(27);
////					inputtextdesc.setfillcolor(sf::color(255, 255, 255));
////					inputtextdesc.setposition(210, 196);
////
////					sf::rectangleshape buttonimage(sf::vector2f(600, 45));
////					buttonimage.setfillcolor(sf::color(86, 0, 172, 70));
////					buttonimage.setposition(200, 785);
////
////					sf::rectangleshape lineimage(sf::vector2f(5, 45));
////					lineimage.setfillcolor(sf::color(18, 104, 10));
////					lineimage.setposition(200, 785);
////
////					sf::text inputtextimage;
////					inputtextimage.setfont(font);
////					inputtextimage.setcharactersize(27);
////					inputtextimage.setfillcolor(sf::color(255, 255, 255));
////					inputtextimage.setposition(210, 788);
////
////					sf::texture createtexture;
////					if (!createtexture.loadfromfile("2023-11-13_171327.png"))
////						return exit_failure;
////
////					sf::sprite createsprite(createtexture);
////					float scalex1 = 300.0 / createtexture.getsize().x;
////					float scaley1 = 75.0 / createtexture.getsize().y;
////					createsprite.setscale(scalex1, scaley1);
////					createsprite.setposition(350, 870);
////
////					sf::font fontcreate;
////					if (!fontcreate.loadfromfile("sourcesanspro-bold.ttf"))
////					{
////						std::cout << "failed to load font!" << std::endl;
////						return -1;
////					}
////
////					sf::text textcreate;
////					textcreate.setfont(fontcreate);
////					textcreate.setcharactersize(37);
////					textcreate.setfillcolor(sf::color(255, 255, 255));
////					textcreate.setposition(432, 883);
////					textcreate.setstring("create");
////
////					string textdesc = "";
////
////					bool isinputtitleactive = false;
////					bool isinputdescactive = false;
////					bool isinputimageactive = false;
////
////					while (window1.isopen())
////					{
////						sf::event event;
////						while (window1.pollevent(event))
////						{
////							if (event.type == sf::event::closed)
////							{
////								window1.close();
////							}
////							if (event.type == sf::event::mousebuttonpressed && event.mousebutton.button == sf::mouse::left)
////							{
////								if (ismouseover(buttontitle, event))
////								{
////									linetitle.setfillcolor(sf::color(128, 241, 118));
////									linedesc.setfillcolor(sf::color(18, 104, 10));
////									lineimage.setfillcolor(sf::color(18, 104, 10));
////									isinputtitleactive = true;
////									isinputdescactive = false;
////									isinputimageactive = false;
////								}
////								else if (ismouseover(buttondesc, event))
////								{
////									linedesc.setfillcolor(sf::color(128, 241, 118));
////									linetitle.setfillcolor(sf::color(18, 104, 10));
////									lineimage.setfillcolor(sf::color(18, 104, 10));
////									isinputdescactive = true;
////									isinputtitleactive = false;
////									isinputimageactive = false;
////								}
////								else if (ismouseover(buttonimage, event)) {
////									lineimage.setfillcolor(sf::color(128, 241, 118));
////									linedesc.setfillcolor(sf::color(18, 104, 10));
////									linetitle.setfillcolor(sf::color(18, 104, 10));
////									isinputdescactive = false;
////									isinputtitleactive = false;
////									isinputimageactive = true;
////								}
////								else {
////									linedesc.setfillcolor(sf::color(18, 104, 10));
////									linetitle.setfillcolor(sf::color(18, 104, 10));
////									lineimage.setfillcolor(sf::color(18, 104, 10));
////									isinputdescactive = false;
////									isinputtitleactive = false;
////									isinputimageactive = false;
////								}
////
////								if (createsprite.getglobalbounds().contains(event.mousebutton.x, event.mousebutton.y)) {
////									string currenttexttitle = inputtexttitle.getstring();
////									string currenttextdesc = textdesc;
////									string currenttextimage = inputtextimage.getstring();
////									if (currenttexttitle == "") {
////										linetitle.setfillcolor(sf::color(126, 0, 33));
////									}
////									if (currenttextdesc == "") {
////										linedesc.setfillcolor(sf::color(126, 0, 33));
////									}
////									if (currenttextimage == "") {
////										lineimage.setfillcolor(sf::color(126, 0, 33));
////									}
////									if (currenttexttitle != "" && currenttextdesc != "" && currenttextimage != "") {
////										cout << "phim size = " << films.size() << ' ';
////										for (int i = 0; i < films.size(); i++)
////										{
////											productboxes[i].first.setposition(20 + i * 350, 125);
////
////											productboxes[i].second.first.setstring(films[i].title);
////											float textx = productboxes[i].first.getposition().x + productboxes[i].first.getsize().x / 2 - productboxes[i].second.first.getlocalbounds().width / 2;
////											productboxes[i].second.first.setposition(textx, 600);
////											productboxes[i].second.second = films[i].image;
////										}
////										films.push_back({ currenttexttitle, currenttextdesc, currenttextimage });
////										cout << "phim size = " << films.size() << ' ';
////										cout << "productboxes size = " << productboxes.size() << ' ';
////										sf::rectangleshape productbox(sf::vector2f(300, 500));
////										productbox.setfillcolor(sf::color::white);
////										productbox.setoutlinethickness(2);
////										productbox.setoutlinecolor(sf::color::black);
////										productbox.setposition(20 + (films.size() - 1) * 350, 125);
////
////										sf::text producttext(currenttexttitle, font, 24);
////										producttext.setfillcolor(sf::color::black);
////										float textx = productbox.getposition().x + productbox.getsize().x / 2 - producttext.getlocalbounds().width / 2;
////										cout << "productbox.getposition().x" << productbox.getposition().x << endl;
////										cout << "productbox.getsize().x" << productbox.getsize().x << endl;
////										cout << "producttext.getlocalbounds().width" << producttext.getlocalbounds().width << endl;
////										producttext.setposition(textx, 600);
////
////										productboxes.push_back({ productbox , {producttext, currenttextimage} });
////										cout << "productboxes size = " << productboxes.size() << endl;
////										//sf::vector2f offset(0, 0);
////										//sf::vector2f newpos = productboxes[productboxes.size() - 1].first.getposition() + offset;
////										//float textx = productboxes[productboxes.size() - 1].first.getposition().x + productboxes[productboxes.size() - 1].first.getsize().x / 2 - productboxes[productboxes.size() - 1].second.first.getlocalbounds().width / 2;
////
////										//for (int i = productboxes.size() - 1; i >= 1; i--)
////										//{
////										//	productboxes[i].first.setposition(productboxes[i - 1].first.getposition());
////										//	float textx = productboxes[i].first.getposition().x + productboxes[i].first.getsize().x / 2 - productboxes[i].second.first.getlocalbounds().width / 2;
////										//	productboxes[i].second.first.setposition(textx, 600);
////										//}
////
////										//productboxes[0].first.setposition(newpos);
////										//productboxes[0].second.first.setposition(textx, 600);
////									}
////								}
////							}
////							else if (event.type == sf::event::textentered)
////							{
////								if (isinputtitleactive)
////								{
////									if (event.text.unicode < 128)
////									{
////										if (event.text.unicode == '\b')
////										{
////											if (!inputtexttitle.getstring().isempty()) {
////												std::string currenttext = inputtexttitle.getstring();
////												currenttext.pop_back();
////												inputtexttitle.setstring(currenttext);
////											}
////										}
////										else if (event.text.unicode == '\r' || event.text.unicode == '\n')
////										{
////											inputtexttitle.setstring(inputtexttitle.getstring() + "\n");
////										}
////										else
////										{
////											inputtexttitle.setstring(inputtexttitle.getstring() + static_cast<char>(event.text.unicode));
////										}
////									}
////								}
////								else if (isinputdescactive)
////								{
////									if (event.text.unicode < 128)
////									{
////										if (event.text.unicode == '\b')
////										{
////											if (!inputtextdesc.getstring().isempty()) {
////												std::string currenttext = inputtextdesc.getstring();
////												currenttext.pop_back();
////												textdesc.pop_back();
////												inputtextdesc.setstring(currenttext);
////											}
////										}
////										else if (event.text.unicode == '\r' || event.text.unicode == '\n')
////										{
////											inputtextdesc.setstring(inputtextdesc.getstring() + "\n");
////											textdesc += "\n";
////										}
////										else
////										{
////											string laststring;
////											stringstream ss(inputtextdesc.getstring());
////											while (getline(ss, laststring, '\n')) {
////											}
////
////											sf::text temptext;
////											temptext.setfont(font);
////											temptext.setcharactersize(27);
////											temptext.setstring(laststring);
////											float linedescwidth = temptext.getlocalbounds().width;
////											float buttondescwidth = buttondesc.getlocalbounds().width;
////											if (linedescwidth > buttondescwidth - 20)
////											{
////												// thêm ký tự xuống dòng
////												inputtextdesc.setstring(inputtextdesc.getstring() + "\n");
////											}
////											inputtextdesc.setstring(inputtextdesc.getstring() + static_cast<char>(event.text.unicode));
////											textdesc += static_cast<char>(event.text.unicode);
////										}
////
////									}
////								}
////								else if (isinputimageactive)
////								{
////									if (event.text.unicode < 128)
////									{
////										if (event.text.unicode == '\b')
////										{
////											if (!inputtextimage.getstring().isempty()) {
////												std::string currenttext = inputtextimage.getstring();
////												currenttext.pop_back();
////												inputtextimage.setstring(currenttext);
////											}
////										}
////										else if (event.text.unicode == '\r' || event.text.unicode == '\n')
////										{
////											inputtextimage.setstring(inputtextimage.getstring() + "\n");
////										}
////										else
////										{
////											inputtextimage.setstring(inputtextimage.getstring() + static_cast<char>(event.text.unicode));
////										}
////									}
////								}
////							}
////							if (event.type == sf::event::mousemoved)
////							{
////								sf::vector2i mouseposition = sf::mouse::getposition(window1);
////								if (createsprite.getglobalbounds().contains(static_cast<float>(mouseposition.x), static_cast<float>(mouseposition.y)))
////								{
////									if (!createtexture.loadfromfile("2023-11-13_173035.png"))
////										return exit_failure;
////									float scalex1 = 300.0 / createtexture.getsize().x;
////									float scaley1 = 75.0 / createtexture.getsize().y;
////									createsprite.setscale(scalex1, scaley1);
////								}
////								else
////								{
////									if (!createtexture.loadfromfile("2023-11-13_171327.png"))
////										return exit_failure;
////									float scalex1 = 300.0 / createtexture.getsize().x;
////									float scaley1 = 75.0 / createtexture.getsize().y;
////									createsprite.setscale(scalex1, scaley1);
////								}
////							}
////						}
////
////						window1.clear();
////						window1.draw(sprite);
////						
////						window1.draw(buttontitle);
////						window1.draw(inputtexttitle);
////						window1.draw(linetitle);
////
////						window1.draw(buttondesc);
////						window1.draw(inputtextdesc);
////						window1.draw(linedesc);
////
////						window1.draw(buttonimage);
////						window1.draw(inputtextimage);
////						window1.draw(lineimage);
////
////						window1.draw(createsprite);
////						window1.draw(textcreate);
////
////						window1.display();
////					}
////					//createfilmswindow()
////					window.setvisible(true);
////					window1.setvisible(false);
////
////					cout << "phim size = " << films.size() << ' ';
////					cout << "productboxes size = " << productboxes.size() << ' ';
////				}
////			}
////
////		}
////		window.clear(sf::color::white);
////
////		//if (homepageadmin) {
////		window.draw(button1);
////		window.draw(iconsprite1);
////		//}
////
////		if (homepagebutton) {
////			sf::vector2f offset(0, 0);
////			sf::vector2f newpos = productboxes[productboxes.size() - 1].first.getposition() + offset;
////			cout << "phim size = " << films.size() << ' ';
////			cout << "productboxes size = " << productboxes.size() << ' ' << "homepage" << endl;
////			cout << "productboxes[productboxes.size() - 1].first.getposition().x = " << productboxes[productboxes.size() - 1].first.getposition().x << endl;
////			cout << "productboxes[productboxes.size() - 1].first.getsize().x = " << productboxes[productboxes.size() - 1].first.getsize().x << endl;
////			cout << "productboxes[productboxes.size() - 1].second.first.getstring().toansistring()" << productboxes[productboxes.size() - 1].second.first.getstring().toansistring() << endl;
////			cout << "productboxes[productboxes.size() - 1].second.first.getlocalbounds().width = " << productboxes[productboxes.size() - 1].second.first.getlocalbounds().width << endl;
////			float textx = productboxes[productboxes.size() - 1].first.getposition().x + productboxes[productboxes.size() - 1].first.getsize().x / 2 - productboxes[productboxes.size() - 1].second.first.getlocalbounds().width / 2;
////			cout << "phim size = " << films.size() << ' ';
////			cout << "productboxes size = " << productboxes.size() << ' ' << "homepage2" << endl;
////			for (int i = productboxes.size() - 1; i >= 1; i--)
////			{	
////				productboxes[i].first.setposition(productboxes[i - 1].first.getposition());
////				float text_x = productboxes[i].first.getposition().x + productboxes[i].first.getsize().x / 2 - productboxes[i].second.first.getlocalbounds().width / 2;
////				productboxes[i].second.first.setposition(text_x, 600);
////			}
////
////			productboxes[0].first.setposition(newpos);
////			productboxes[0].second.first.setposition(textx, 600);
////
////
////			for (int i = 0; i < films.size(); i++)
////			{
////				sf::texture texture;
////				if (!texture.loadfromfile(productboxes[i].second.second)) {
////					return exit_failure;
////				}
////				sf::sprite sprite(texture);
////				sf::vector2u windowsize = window.getsize();
////				float scalex = 290.0 / texture.getsize().x;
////				float scaley = 475.0 / texture.getsize().y;
////				sprite.setscale(scalex, scaley);
////				float x = productboxes[i].first.getposition().x + 5;
////				float y = productboxes[i].first.getposition().y + 5;
////				sprite.setposition(x, y);
////
////				window.draw(productboxes[i].first);
////				window.draw(sprite);
////				window.draw(productboxes[i].second.first);
////			}
////
////			sf::sleep(sf::seconds(0.7));
////		}
////
////		if (selectdropdownbutton) {
////			window.draw(sprite);
////		}
////
////		if (selectandupdatebutton) {
////			if (indexbutton) {
////				for (int i = 0; i < 12; i++) {
////					for (int j = 0; j < 6; j++) {
////						window.draw(box[indexbutton - 1][i][j].first);
////					}
////				}
////			}
////		}
////
////		window.draw(thickline);
////
////		window.draw(dropdownbox);
////		window.draw(dropdowntext);
////		if (isarrowdownup) {
////			arrow.setpoint(0, sf::vector2f(0, 0));
////			arrow.setpoint(1, sf::vector2f(15, 0));
////			arrow.setpoint(2, sf::vector2f(7.5, 7.5));
////			arrow.setfillcolor(sf::color::black);
////			window.draw(arrow);
////		}
////
////		if (isdropdownactive)
////		{
////			isarrowdownup = false;
////			arrow.setpoint(0, sf::vector2f(7.5, 0));
////			arrow.setpoint(1, sf::vector2f(0, 7.5));
////			arrow.setpoint(2, sf::vector2f(15, 7.5));
////			arrow.setfillcolor(sf::color::black);
////			window.draw(arrow);
////
////			for (const std::pair<sf::text, sf::rectangleshape> option : options)
////			{
////				window.draw(option.second);
////				window.draw(option.first);
////			}
////		}
////
////		window.draw(createbutton);
////		window.draw(createbuttontext);
////
////		window.display();
////	}
////}