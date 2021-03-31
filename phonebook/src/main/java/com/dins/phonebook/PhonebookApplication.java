package com.dins.phonebook;

import com.dins.phonebook.domain.User;
import com.dins.phonebook.domain.PhoneBookNote;
import com.dins.phonebook.repository.UserRepository;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;
import org.springframework.transaction.annotation.Transactional;

import java.util.LinkedList;
import java.util.List;

@SpringBootApplication
public class PhonebookApplication {
    public static void main(String[] args) {
        SpringApplication.run(PhonebookApplication.class, args);
    }
    @Bean
    public CommandLineRunner demo(UserRepository repository) {
        return new CommandLineRunner() {
            @Override
            @Transactional()
            public void run(String... args) {
                List<PhoneBookNote> book = new LinkedList<>();
                book.add(new PhoneBookNote("1231", "qeqwe"));
                book.add(new PhoneBookNote("12341", "qeqwe"));
                book.add(new PhoneBookNote("1235", "qeqwe"));
                User user = new User();
                user.setName("Dima");
                book.forEach(b -> b.setUser(user));
                user.setPhoneBook(book);
                repository.save(user);
            }
        };
    }
}
