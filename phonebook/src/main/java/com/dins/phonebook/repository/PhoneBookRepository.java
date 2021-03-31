package com.dins.phonebook.repository;

import com.dins.phonebook.domain.PhoneBookNote;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.CrudRepository;
import org.springframework.transaction.annotation.Transactional;

import java.util.Optional;

public interface PhoneBookRepository extends CrudRepository<PhoneBookNote, Long> {
    Iterable<PhoneBookNote> findPhoneBookNotesByUserId(Long id);

    Optional<PhoneBookNote> findPhoneBookNoteByUserIdAndId(Long id, Long noteId);

    Optional<PhoneBookNote> findPhoneBookNoteByUserIdAndPhoneNumber(Long id, String phoneNumber);

    Iterable<PhoneBookNote> findPhoneBookNoteByPhoneNumber(String phoneNumber);

    @Modifying
    @Transactional
    void deletePhoneBookNoteByUserIdAndId(Long id, Long phoneBookNoteId);

    Optional<PhoneBookNote> findById(Long id);

    @Modifying
    @Transactional
    @Query("update PhoneBookNote p set p.name = :name, p.phoneNumber = :phoneNumber where p.id = :noteId and  p.user.id = :id")
    void updatePhoneBookNoteByUserIdAndId(Long id, Long noteId, String name, String phoneNumber);
}
