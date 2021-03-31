package com.dins.phonebook.controller;

import com.dins.phonebook.domain.User;
import com.dins.phonebook.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.hateoas.EntityModel;
import org.springframework.http.HttpStatus;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

import java.util.Map;

@Controller
@RequestMapping(path="/user")
public class UserController {

    @Autowired
    private UserService userService;

    @GetMapping(path="/{id}")
    public @ResponseBody
    EntityModel<User> getUser (@PathVariable Long id) {
        return userService.getUser(id);
    }

    @DeleteMapping(path="/{id}")
    @ResponseStatus(HttpStatus.OK)
    public @ResponseBody
    String deleteUser (@PathVariable Long id) {
        userService.deleteUser(id);
        return "Deleted";
    }

    @PutMapping(path = "/{id}")
    @ResponseStatus(HttpStatus.OK)
    public @ResponseBody
    String updateUser(@PathVariable Long id, @RequestBody Map<String, String> name){
        userService.updateName(id, name.get("name"));
        return "Updated";
    }
}
