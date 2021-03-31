package com.dins.phonebook.service;

import com.dins.phonebook.controller.MainController;
import com.dins.phonebook.controller.UserController;
import com.dins.phonebook.domain.User;
import com.dins.phonebook.exception.UserNotFoundException;
import com.dins.phonebook.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.hateoas.EntityModel;
import org.springframework.stereotype.Service;
import static org.springframework.hateoas.server.mvc.WebMvcLinkBuilder.*;

@Service
@Qualifier("userService")
public class UserServiceImpl implements UserService{

    @Autowired
    private UserRepository userRepository;

    @Override
    public EntityModel<User> getUser(Long id) {
        User user = userRepository.findById(id).orElseThrow(() -> new UserNotFoundException(id));
        return EntityModel.of(user,
                linkTo(methodOn(UserController.class).getUser(id)).withSelfRel(),
                linkTo(methodOn(MainController.class).getAllUsers()).withRel("users"));
    }

    @Override
    public Iterable<User> getAllUsers() {
        return userRepository.findAll();
    }

    @Override
    public Iterable<User> getUsersByNameLike(String name) {
        return userRepository.findByNameLike("%".concat(name).concat("%"));
    }

    @Override
    public boolean deleteUser(Long id) {
        userRepository.deleteById(id);
        return true;
    }

    @Override
    public boolean addUser(User user) {
        user.getPhoneBook().forEach(b->b.setUser(user));
        userRepository.save(user);
        return true;
    }

    @Override
    public boolean updateName(Long id, String name) {
        userRepository.updateName(id, name);
        return true;
    }
}
