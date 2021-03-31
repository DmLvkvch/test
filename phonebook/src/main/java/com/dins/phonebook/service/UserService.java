package com.dins.phonebook.service;

import com.dins.phonebook.domain.User;
import org.springframework.hateoas.EntityModel;

public interface UserService {
    EntityModel<User> getUser(Long id);
    Iterable<User> getAllUsers();
    Iterable<User> getUsersByNameLike(String name);
    boolean deleteUser(Long id);
    boolean addUser(User user);
    boolean updateName(Long id, String name);
}
