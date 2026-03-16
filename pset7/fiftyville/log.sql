-- Keep a log of any SQL queries you execute as you solve the mystery.

--I want to read the crime-scene reports' description at the day and place of the theft to get started on the investigation
SELECT description
  FROM crime_scene_reports
 WHERE year = 2024 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

 --I want to read the interviews at the day of the crime, mentioning the word bakery, who will be about the duck
 SELECT transcript
   FROM interviews
  WHERE year = 2024 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%';

  --Get all license plates that exited the bakery within 10 minutes of the theft
  SELECT license_plate
    FROM bakery_security_logs
   WHERE year = 2024 AND month = 7 AND day = 28 AND hour = 10 AND (minute >= 15 AND minute <25);

--Get all account numbers that made an atm transaction at Legget Street at the day of the theft
SELECT account_number
  FROM atm_transactions
 WHERE year = 2024 AND month = 7 AND day = 28 AND atm_location ='Leggett Street';

--Combine the above while joining people and bank_accounts on person_id
--To Get the name of the people who: made the mentioned atm transaction and also exited the bakery as mentioned before
 SELECT name
   FROM people, bank_accounts
  WHERE people.id = bank_accounts.person_id
    AND license_plate IN
        (SELECT license_plate
        FROM bakery_security_logs
        WHERE year = 2024 AND month = 7 AND day = 28 AND hour = 10 AND (minute >= 15 AND minute <25))
    AND account_number IN
        (SELECT account_number
        FROM atm_transactions
        WHERE year = 2024 AND month = 7 AND day = 28 AND atm_location ='Leggett Street');

--Find the first flight out of Fiftiville the day after the crime
SELECT flights.id
  FROM flights, airports
 WHERE flights.origin_airport_id = airports.id
   AND year = 2024
   AND month = 7
   AND day = 29
   AND city = 'Fiftyville'
   AND hour =
       (SELECT MIN(hour)
          FROM flights, airports
         WHERE flights.origin_airport_id = airports.id
           AND year = 2024 AND month = 7 AND day = 29 AND city = 'Fiftyville')
   AND minute =
       (SELECT MIN(minute)
          FROM flights, airports
         WHERE flights.origin_airport_id = airports.id
           AND year = 2024
           AND month = 7
           AND day = 29
           AND city = 'Fiftyville'
           AND hour =
               (SELECT MIN(hour)
                  FROM flights, airports
                 WHERE flights.origin_airport_id = airports.id
                   AND year = 2024
                   AND month = 7
                   AND day = 29
                   AND city = 'Fiftyville'));

--Find the destination of that flight
SELECT city
		FROM flights AS f, airports AS a
	WHERE f.destination_airport_id = a.id
			AND f.id =
							(SELECT flights.id
										FROM flights, airports
									WHERE flights.origin_airport_id = airports.id
											AND year = 2024
											AND month = 7
											AND day = 29
											AND city = 'Fiftyville'
											AND hour =
															(SELECT MIN(hour)
																		FROM flights, airports
																	WHERE flights.origin_airport_id = airports.id
																			AND year = 2024 AND month = 7 AND day = 29 AND city = 'Fiftyville')
											AND minute =
															(SELECT MIN(minute)
																		FROM flights, airports
																	WHERE flights.origin_airport_id = airports.id
																			AND year = 2024
																			AND month = 7
																			AND day = 29
																			AND city = 'Fiftyville'
																			AND hour =
																							(SELECT MIN(hour)
																										FROM flights, airports
																									WHERE flights.origin_airport_id = airports.id
																											AND year = 2024
																											AND month = 7
																											AND day = 29
																											AND city = 'Fiftyville')));


--Now find all the passengers in the first flight out of fiftyville the day after the crime
SELECT passport_number
  FROM flights AS f, passengers AS p
 WHERE f.id = p.flight_id
   AND f.id =
       (SELECT flights.id
          FROM flights, airports
         WHERE flights.origin_airport_id = airports.id
           AND year = 2024
           AND month = 7
           AND day = 29
           AND city = 'Fiftyville'
           AND hour =
               (SELECT MIN(hour)
                  FROM flights, airports
                 WHERE flights.origin_airport_id = airports.id
                   AND year = 2024 AND month = 7 AND day = 29 AND city = 'Fiftyville')
                   AND minute =
                       (SELECT MIN(minute)
                          FROM flights, airports
                         WHERE flights.origin_airport_id = airports.id
                           AND year = 2024
                           AND month = 7
                           AND day = 29
                           AND city = 'Fiftyville'
                           AND hour =
                              (SELECT MIN(hour)
                                  FROM flights, airports
                                 WHERE flights.origin_airport_id = airports.id
                                   AND year = 2024
                                   AND month = 7
                                   AND day = 29
                                   AND city = 'Fiftyville')));



--Find all the people who were passengers on flight id = 36 & also where involved in the bakery theft as mentioned before
SELECT id, name
  FROM people
 WHERE passport_number IN
       (SELECT passport_number
          FROM flights AS f, passengers AS p
         WHERE f.id = p.flight_id
           AND f.id =
               (SELECT flights.id
                  FROM flights, airports
                 WHERE flights.origin_airport_id = airports.id
                   AND year = 2024
                   AND month = 7
                   AND day = 29
                   AND city = 'Fiftyville'
                   AND hour =
                       (SELECT MIN(hour)
                           FROM flights, airports
                          WHERE flights.origin_airport_id = airports.id
                            AND year = 2024 AND month = 7 AND day = 29 AND city = 'Fiftyville')
                   AND minute =
                       (SELECT MIN(minute)
                          FROM flights, airports
                         WHERE flights.origin_airport_id = airports.id
                           AND year = 2024
                           AND month = 7
                           AND day = 29
                           AND city = 'Fiftyville'
                           AND hour =
                              (SELECT MIN(hour)
                                 FROM flights, airports
                                WHERE flights.origin_airport_id = airports.id
                                  AND year = 2024
                                  AND month = 7
                                  AND day = 29
                                  AND city = 'Fiftyville'))))
   AND name IN
       (SELECT name
          FROM people, bank_accounts
         WHERE people.id = bank_accounts.person_id
           AND license_plate IN
               (SELECT license_plate
                  FROM bakery_security_logs
                 WHERE year = 2024 AND month = 7 AND day = 28 AND hour = 10 AND (minute >= 15 AND minute <25))
           AND account_number IN
               (SELECT account_number
                  FROM atm_transactions
                 WHERE year = 2024 AND month = 7 AND day = 28 AND atm_location ='Leggett Street'));


--Found Luca (id = 467400) and Bruce (id = 686048). One of them is the thief. now lets search the phone calls
--to see if any of them made any calls less than 1 minute long, and to whom.
SELECT caller, receiver
  FROM phone_calls
 WHERE year = 2024 AND month = 7 AND day = 28 AND duration < 60
   AND caller IN
							(SELECT phone_number
										FROM people
									WHERE passport_number IN
															(SELECT passport_number
																		FROM flights AS f, passengers AS p
																	WHERE f.id = p.flight_id
																			AND f.id =
																							(SELECT flights.id
																										FROM flights, airports
																									WHERE flights.origin_airport_id = airports.id
																											AND year = 2024
																											AND month = 7
																											AND day = 29
																											AND city = 'Fiftyville'
																											AND hour =
																															(SELECT MIN(hour)
																																			FROM flights, airports
																																		WHERE flights.origin_airport_id = airports.id
																																				AND year = 2024 AND month = 7 AND day = 29 AND city = 'Fiftyville')
																											AND minute =
																															(SELECT MIN(minute)
																																		FROM flights, airports
																																	WHERE flights.origin_airport_id = airports.id
																																			AND year = 2024
																																			AND month = 7
																																			AND day = 29
																																			AND city = 'Fiftyville'
																																			AND hour =
																																						(SELECT MIN(hour)
																																									FROM flights, airports
																																								WHERE flights.origin_airport_id = airports.id
																																										AND year = 2024
																																										AND month = 7
																																										AND day = 29
																																										AND city = 'Fiftyville'))))
											AND name IN
															(SELECT name
																		FROM people, bank_accounts
																	WHERE people.id = bank_accounts.person_id
																			AND license_plate IN
																							(SELECT license_plate
																										FROM bakery_security_logs
																									WHERE year = 2024 AND month = 7 AND day = 28 AND hour = 10 AND (minute >= 15 AND minute <25))
																			AND account_number IN
																							(SELECT account_number
																										FROM atm_transactions
																									WHERE year = 2024 AND month = 7 AND day = 28 AND atm_location ='Leggett Street')));

--The last query produced only one outcome: We have found the thief (the caller) and the accomplish (the receiver)
--Now lets find their names
--First the thief
SELECT name, phone_number FROM people
 WHERE phone_number IN
							(SELECT caller
										FROM phone_calls
									WHERE year = 2024 AND month = 7 AND day = 28 AND duration < 60
											AND caller IN
															(SELECT phone_number
																		FROM people
																	WHERE passport_number IN
																							(SELECT passport_number
																										FROM flights AS f, passengers AS p
																									WHERE f.id = p.flight_id
																											AND f.id =
																															(SELECT flights.id
																																		FROM flights, airports
																																	WHERE flights.origin_airport_id = airports.id
																																			AND year = 2024
																																			AND month = 7
																																			AND day = 29
																																			AND city = 'Fiftyville'
																																			AND hour =
																																							(SELECT MIN(hour)
																																											FROM flights, airports
																																										WHERE flights.origin_airport_id = airports.id
																																												AND year = 2024 AND month = 7 AND day = 29 AND city = 'Fiftyville')
																																			AND minute =
																																							(SELECT MIN(minute)
																																										FROM flights, airports
																																									WHERE flights.origin_airport_id = airports.id
																																											AND year = 2024
																																											AND month = 7
																																											AND day = 29
																																											AND city = 'Fiftyville'
																																											AND hour =
																																														(SELECT MIN(hour)
																																																	FROM flights, airports
																																																WHERE flights.origin_airport_id = airports.id
																																																		AND year = 2024
																																																		AND month = 7
																																																		AND day = 29
																																																		AND city = 'Fiftyville'))))
																			AND name IN
																							(SELECT name
																										FROM people, bank_accounts
																									WHERE people.id = bank_accounts.person_id
																											AND license_plate IN
																															(SELECT license_plate
																																		FROM bakery_security_logs
																																	WHERE year = 2024 AND month = 7 AND day = 28 AND hour = 10 AND (minute >= 15 AND minute <25))
																											AND account_number IN
																															(SELECT account_number
																																		FROM atm_transactions
																																	WHERE year = 2024 AND month = 7 AND day = 28 AND atm_location ='Leggett Street'))));

--Now the accomplish
SELECT name, phone_number FROM people
 WHERE phone_number IN
							(SELECT receiver
										FROM phone_calls
									WHERE year = 2024 AND month = 7 AND day = 28 AND duration < 60
											AND caller IN
															(SELECT phone_number
																		FROM people
																	WHERE passport_number IN
																							(SELECT passport_number
																										FROM flights AS f, passengers AS p
																									WHERE f.id = p.flight_id
																											AND f.id =
																															(SELECT flights.id
																																		FROM flights, airports
																																	WHERE flights.origin_airport_id = airports.id
																																			AND year = 2024
																																			AND month = 7
																																			AND day = 29
																																			AND city = 'Fiftyville'
																																			AND hour =
																																							(SELECT MIN(hour)
																																											FROM flights, airports
																																										WHERE flights.origin_airport_id = airports.id
																																												AND year = 2024 AND month = 7 AND day = 29 AND city = 'Fiftyville')
																																			AND minute =
																																							(SELECT MIN(minute)
																																										FROM flights, airports
																																									WHERE flights.origin_airport_id = airports.id
																																											AND year = 2024
																																											AND month = 7
																																											AND day = 29
																																											AND city = 'Fiftyville'
																																											AND hour =
																																														(SELECT MIN(hour)
																																																	FROM flights, airports
																																																WHERE flights.origin_airport_id = airports.id
																																																		AND year = 2024
																																																		AND month = 7
																																																		AND day = 29
																																																		AND city = 'Fiftyville'))))
																			AND name IN
																							(SELECT name
																										FROM people, bank_accounts
																									WHERE people.id = bank_accounts.person_id
																											AND license_plate IN
																															(SELECT license_plate
																																		FROM bakery_security_logs
																																	WHERE year = 2024 AND month = 7 AND day = 28 AND hour = 10 AND (minute >= 15 AND minute <25))
																											AND account_number IN
																															(SELECT account_number
																																		FROM atm_transactions
																																	WHERE year = 2024 AND month = 7 AND day = 28 AND atm_location ='Leggett Street'))));
