package com.dins.phonebook.service;

import com.dins.phonebook.domain.PhoneBookNote;
import com.dins.phonebook.domain.User;
import com.dins.phonebook.repository.UserRepository;
import com.dins.phonebook.service.UserService;
import org.junit.Before;
import org.junit.jupiter.api.Test;
import org.junit.runner.RunWith;
import org.mockito.Mockito;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.hateoas.EntityModel;
import org.springframework.test.context.junit4.SpringRunner;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.*;

@RunWith(SpringRunner.class)
@SpringBootTest
class UserServiceImplTest {

    @Autowired
    private UserService userService;

    @MockBean
    private UserRepository userRepository;

    @Before
    public void setUp() {
        List<PhoneBookNote> phoneBookNoteList = new ArrayList<>();
        phoneBookNoteList.add(new PhoneBookNote("231", "name"));
        phoneBookNoteList.add(new PhoneBookNote("312", "java"));
        User user = new User("Dima", phoneBookNoteList);
        user.setId(1L);
        phoneBookNoteList.forEach(u->u.setUser(user));
        Mockito.when(userRepository.findById(user.getId())).thenReturn(java.util.Optional.of(user));
    }

    @Test
    void getUser() {
        List<PhoneBookNote> phoneBookNoteList = new ArrayList<>();
        phoneBookNoteList.add(new PhoneBookNote("231", "name"));
        phoneBookNoteList.add(new PhoneBookNote("312", "java"));
        User user = new User("Dima", phoneBookNoteList);
        user.setId(1L);
        phoneBookNoteList.forEach(u->u.setUser(user));
        Mockito.when(userRepository.findById(user.getId())).thenReturn(java.util.Optional.of(user));

        String name = "Dima";
        System.out.println(userService.getAllUsers());
        EntityModel<User> user1 = userService.getUser(1L);
        assertThat(Objects.requireNonNull(user1.getContent()).getName())
                .isEqualTo(name);
    }

    @Test
    void getAllUsers() {
        List<PhoneBookNote> phoneBookNoteList = new ArrayList<>();
        phoneBookNoteList.add(new PhoneBookNote("231", "name"));
        phoneBookNoteList.add(new PhoneBookNote("312", "java"));
        User user = new User("Dima", phoneBookNoteList);
        user.setId(1L);
        phoneBookNoteList.forEach(u->u.setUser(user));
        List<User> users = new ArrayList<>();
        users.add(user);
        Mockito.when(userRepository.findAll()).thenReturn(users);

        Iterable<User> allUsers = userService.getAllUsers();
        assertThat(allUsers).isEqualTo(users);
    }

    @Test
    void addUser() {
        List<PhoneBookNote> phoneBookNoteList = new ArrayList<>();
        phoneBookNoteList.add(new PhoneBookNote("231", "name"));
        phoneBookNoteList.add(new PhoneBookNote("312", "java"));
        User user = new User("Dima", phoneBookNoteList);
        user.setId(1L);
        phoneBookNoteList.forEach(u->u.setUser(user));
        boolean b = userService.addUser(user);
        assertThat(b).isEqualTo(true);
    }
}