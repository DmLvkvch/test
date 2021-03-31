package com.dins.phonebook.repository;

import com.dins.phonebook.domain.User;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;
import org.springframework.transaction.annotation.Transactional;

@Repository
public interface UserRepository extends CrudRepository<User, Long> {

    Iterable<User> findByNameLike(String name);

    void deleteById(Long id);

    @Modifying
    @Transactional
    @Query("update User u set u.name = :name where u.id = :id")
    void updateName(Long id, String name);
}
