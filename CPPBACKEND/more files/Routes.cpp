#pragma once
#include "Routes.h"
#include <crow.h>

void includeRoutes(crow::App<crow::CORSHandler> &app)
{
    // Route to signup
    CROW_ROUTE(app, "/signup")
        .methods("POST"_method)([](const crow::request &req)
                                {
            try
            {
                // Parse JSON data from the request body
                json requestData = json::parse(req.body);
                std::string name = requestData["name"];
                std::string email = requestData["email"];
                std::string password = requestData["password"];
                User user(name, email, password);

                // user.setUser(requestData);
                json data =  user.getUserDetails();
                
                // Return a success response
                return crow::response(data.dump(2));
            }
            catch (const std::exception &e)
            {
                // Print an error message if an exception occurs
                std::cerr << e.what() << '\n';
               
                // Return an error response
                return crow::response(500, "internal server error");
            } });


    // Route to signup
    CROW_ROUTE(app, "/changeDetails")
        .methods("POST"_method)([](const crow::request &req)
                                {
            try
            {
                 // Extract email and password from request headers
                std::string name = req.get_header_value("name");
                std::string email = req.get_header_value("email");
                std::string password = req.get_header_value("password");
                
                User user(name, email, password);
                   
                // Parse JSON data from the request body
                json requestData = json::parse(req.body);
                std::string newName = requestData["newName"];
                std::string newEmail = requestData["newEmail"];
                std::string newPassword = requestData["newPassword"];


                user.changeUserDetails(newName, newEmail, newPassword);
               
                json data =  user.getUserDetails();
                
                // Return a success response
                return crow::response(data.dump(2));
            }
            catch (const std::exception &e)
            {
                // Print an error message if an exception occurs
                std::cerr << e.what() << '\n';
               
                // Return an error response
                return crow::response(500, "internal server error");
            } });



    // Route to add a new note
    CROW_ROUTE(app, "/addNote")
        .methods("POST"_method)([](const crow::request &req)
                                {
            try
            {
                 // Extract email and password from request headers
                std::string name = req.get_header_value("name");
                std::string email = req.get_header_value("email");
                std::string password = req.get_header_value("password");

                std::cout << name << email << password;
                // User user(name, email, password);
                // Parse JSON data from the request body
                json requestData = json::parse(req.body);
                // std::cout << requestData.dump(2);
                NoteManager noteManager(name, email, password);

                // Call the addNote function with the parsed JSON data
                noteManager.addNote(requestData);

                // Return a success response
                return crow::response(requestData.dump(2));
            }
            catch (const std::exception &e)
            {
                // Print an error message if an exception occurs
                std::cerr << e.what() << '\n';

                // Return an error response
                return crow::response(500, "Internal Server Error");
            } });


    // Route to edit note
    CROW_ROUTE(app, "/editNote")
        .methods("POST"_method)([](const crow::request &req)
                                {
            try
            {
                 // Extract email and password from request headers
                std::string name = req.get_header_value("name");
                std::string email = req.get_header_value("email");
                std::string password = req.get_header_value("password");

                // User user(name, email, password);

                // Parse JSON data from the request body
                json requestData = json::parse(req.body);
                // std::cout << requestData.dump(2);
                NoteManager noteManager(name, email, password);

                // Call the editNote function with the parsed JSON data
                noteManager.editNote(requestData);

                // Return a success response
                return crow::response(requestData.dump(2));
            }
            catch (const std::exception &e)
            {
                // Print an error message if an exception occurs
                std::cerr << e.what() << '\n';

                // Return an error response
                return crow::response(500, "Internal Server Error");
            } });



    // Route to mark a note as done
    CROW_ROUTE(app, "/checkNote")
        .methods("POST"_method)([](const crow::request &req)
                                {
            try
            {
                 // Extract email and password from request headers
                std::string name = req.get_header_value("name");
                std::string email = req.get_header_value("email");
                std::string password = req.get_header_value("password");

                // User user(name, email, password);

                // Parse JSON data from the request body
                json requestData = json::parse(req.body);
                // std::cout << requestData.dump(2);

                // Extract parameters from the parsed JSON data
                std::string id = requestData["id"];
                int done = requestData["done"];
                NoteManager noteManager(name, email, password);

                // Call the checkNote function with the extracted parameters
                noteManager.checkNote(id, done);

                // Return a success response
                return crow::response(id);
            }
            catch (const std::exception &e)
            {
                // Print an error message if an exception occurs
                std::cerr << e.what() << '\n';
                // Return an error response
                return crow::response(500, "Internal Server Error");
            } });



    // Route to delete a note
    CROW_ROUTE(app, "/deleteNote")
        .methods("POST"_method)([](const crow::request &req)
                                {
            try
            {
                 // Extract email and password from request headers
                std::string name = req.get_header_value("name");
                std::string email = req.get_header_value("email");
                std::string password = req.get_header_value("password");

                // User user(name, email, password);

                // Parse JSON data from the request body
                json requestData = json::parse(req.body);
                // std::cout << requestData.dump(2);

                // Extract parameters from the parsed JSON data
                std::string id = requestData["id"];
                NoteManager noteManager(name, email, password);

                // Call the deleteNote function with the extracted parameters
                noteManager.deleteNote(id);

                // Return a success response
                return crow::response(id);
            }
            catch (const std::exception &e)
            {
                // Print an error message if an exception occurs
                std::cerr << e.what() << '\n';

                // Return an error response
                return crow::response(500, "Internal Server Error");
            } });



    // Route to view all notes
    CROW_ROUTE(app, "/viewNote")
        .methods("GET"_method)([](const crow::request &req)
                               {
            try
            {
                 // Extract email and password from request headers
                std::string name = req.get_header_value("name");
                std::string email = req.get_header_value("email");
                std::string password = req.get_header_value("password");

                // User user(name, email, password);
                NoteManager noteManager(name, email, password);

                // Call the getNotes function to get all notes
                json notes = noteManager.getNotes();
                // std::cout <<  "Notes::   :::  "<< notes.dump(2);

                // Return the notes in the response body
                return crow::response(notes.dump(2));   //dump is just for formatting notes with indentation of 2
            }
            catch (const std::exception &e)
            {
                // Print an error message if an exception occurs
                std::cerr << e.what() << '\n';

                // Return an error response
                return crow::response(500, "Internal Server Error");
            } });
}
