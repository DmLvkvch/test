package com.dins.phonebook.controller;

import com.dins.phonebook.domain.PhoneBookNote;
import com.dins.phonebook.domain.User;
import com.dins.phonebook.service.PhoneBookService;
import com.dins.phonebook.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

@Controller
@RequestMapping(path="/")
public class MainController {

    @Autowired
    private UserService userService;

    @Autowired
    private PhoneBookService phoneBookService;

    @GetMapping(path="/users")
    public @ResponseBody
    Iterable<User> getAllUsers() {
        return userService.getAllUsers();
    }

    @PostMapping(path="/add-user")
    @ResponseStatus(HttpStatus.CREATED)
    public @ResponseBody
    String addNewUser(@RequestBody User user){
        userService.addUser(user);
        return "Saved";
    }

    @GetMapping(path="/find-user")
    public @ResponseBody
    Iterable<User> getUserByName(@RequestParam String name) {
        return userService.getUsersByNameLike(name);
    }

    @GetMapping(path="/find-book-note")
    public @ResponseBody
    Iterable<PhoneBookNote> getPhoneBook(@RequestParam String phoneNumber) {
        return phoneBookService.getPhoneBookNotesByPhoneNumber(phoneNumber);
    }
}