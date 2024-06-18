import AddContactForm from "../sections/AddContactForm.jsx";
import {useEffect, useState} from "react";
import ContactTile from "../components/ContactTile.jsx";
import axios from "axios";
import Loading from "../components/Loading.jsx";
import {FontAwesomeIcon} from "@fortawesome/react-fontawesome";
import { faAddressBook } from "@fortawesome/free-solid-svg-icons";

const MainPage = () => {

    const [contacts, setContacts] = useState([])
    const [loading, setLoading] = useState(true)

    useEffect(() => {
        getContacts();
    }, []);

    const getContacts = () => {
        setLoading(true)
        axios.get("/api/contacts")
            .then((r) => {
                setContacts(r.data);
            }).catch((e) => {})
            .finally(() => {
                setLoading(false)
            })
    }

    return (
        <div className="flex">
            <div className="w-2/5">
                <div className="text-5xl text-white mb-10">
                    <h3><FontAwesomeIcon icon={faAddressBook} /> Phone Book</h3>
                </div>
                <AddContactForm onAdd={(newContact) => setContacts((prev) => {
                    return [...prev, newContact];
                })} />
            </div>
            <div className="w-3/5 pl-20 pr-5 pt-2">
                {
                    loading ? <Loading /> : <div className="flex flex-col gap-2">
                        {contacts.map((contact) => <ContactTile key={contact.id} contact={contact} onContactDeleted={getContacts} />)}
                    </div>
                }
            </div>
        </div>
    );
};

export default MainPage;