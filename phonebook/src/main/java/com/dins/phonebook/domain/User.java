package com.dins.phonebook.domain;

import com.fasterxml.jackson.annotation.JsonIgnore;
import com.fasterxml.jackson.annotation.JsonManagedReference;

import javax.persistence.*;
import java.util.List;

@Entity
public class User {
    @Id
    @GeneratedValue(strategy=GenerationType.AUTO)
    @JsonIgnore
    private Long id;

    private String name;

    @OneToMany(mappedBy = "user", fetch = FetchType.LAZY, cascade = CascadeType.ALL, orphanRemoval=true)
    @JsonManagedReference
    @JsonIgnore
    private List<PhoneBookNote> phoneBook;

    public User() {}

    public User(String name, List<PhoneBookNote> phoneBook) {
        this.name = name;
        this.phoneBook = phoneBook;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<PhoneBookNote> getPhoneBook() {
        return phoneBook;
    }

    public void setPhoneBook(List<PhoneBookNote> phoneBook) {
        this.phoneBook = phoneBook;
    }

}
